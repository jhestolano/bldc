/*
 * =====================================================================================
 *
 *       Filename:  ucmd.c
 *
 *    Description:  : Decode character string into executable commands.
 *
 *        Version:  1.0
 *        Created:  06/21/2020 09:28:27 PM
 *       Revision:  none
 *       Compiler:  arm-none-eabi-gcc
 *
 *         Author:  Pickman22
 *   Organization:  elrobotista.com
 *
 * =====================================================================================
 */
#include <string.h>
#include "ucmd.h"
#include <stdbool.h>
#include "dbg.h"
#include <stdio.h>

/*-----------------------------------------------------------------------------
 *  Macro detiniftions.
 *-----------------------------------------------------------------------------*/
#ifdef UNIT_TEST
#define STATIC
#define INLINE
#else
#define STATIC static
#define INLINE inline
#endif

/*-----------------------------------------------------------------------------
 *  Structure type definitions.
 *-----------------------------------------------------------------------------*/
typedef struct _uCmd_S {
  uint8_t buff[uCMD_BUFF_SIZE]; /* Buffer memory. */
  uint8_t iscmplt; /* Message complete flag. */
  uint16_t cnt; /* Number of elements in buffer. */
  uint8_t isovrflwn; /* Signal overflow condition. */
} uCmd_S;

/*-----------------------------------------------------------------------------
 *  Static global variables.
 *-----------------------------------------------------------------------------*/
static volatile uCmd_S _ucmd_s;

static uint8_t _ucmd_name[uCMD_MAX_CMD_SIZE];

static uint8_t _ucmd_arg[uCMD_MAX_ARG_SIZE];

/*-----------------------------------------------------------------------------
 * Static function prototypes. 
 *-----------------------------------------------------------------------------*/
static void _new_ch_callback (void*);
STATIC inline uint8_t _is_eol_ch(uint8_t);
STATIC INLINE uint8_t _is_alpha_num(uint8_t);
static inline void _add_new_ch(uint8_t);
STATIC INLINE int32_t _find_ch(uint8_t*, uint8_t);
STATIC INLINE  int32_t _strlen(uint8_t*);
STATIC INLINE int32_t _get_cmd_str(uint8_t*, uint8_t*);
STATIC INLINE int32_t _get_arg_str(uint8_t*, uint8_t*);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _get_arg_str
 *  Description:  Copy raw string command into buffer.
 * =====================================================================================
 */
int32_t _get_arg_str ( uint8_t* str, uint8_t* argstr )
{
  return -1;
}		/* -----  end of function _get_arg_str  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _get_cmd_str
 *  Description:  Copy raw string command into buffer.
 * =====================================================================================
 */
int32_t _get_cmd_str ( uint8_t* str, uint8_t* cmdstr )
{
  int32_t idx =_find_ch(str, uCMD_CHAR_BRK);
  if ( idx > 0 ) {
    memcpy(cmdstr, str, idx);
    cmdstr[idx] = uCMD_NULL_CHAR;
  }
  else {
    idx = -1;
  }
  return idx;
}		/* -----  end of function _get_cmd_str  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _strlen
 *  Description:  Calculates length of a null terminated string. Returns
 *                for strings longer than uCMD_MAX_STR_LEN.
 * =====================================================================================
 */
STATIC INLINE int32_t _strlen ( uint8_t* str )
{
  int32_t ret;
  int32_t idx;
  for( idx = 0; (str[idx] != uCMD_NULL_CHAR) && (idx < uCMD_MAX_STR_LEN - 1); idx++ ) { }
  if ( str[idx] == uCMD_NULL_CHAR ) {
    /* Test if for loop was terminated due to finding null char. This means that we */
    /* have the correct string size. */
    ret = idx;
  }
  else {
    /* Loop was broken due to reaching maximum possible string size. */
    ret = -1;
  }
  return ret;
}		/* -----  end of function _strlen  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _find_ch
 *  Description:  Find the index of a character within string. Return -1 if not found,
 *                or string is invalid.
 * =====================================================================================
 */
STATIC INLINE int32_t _find_ch ( uint8_t* str, uint8_t ch )
{
  int32_t idx;
  int32_t ret = -1;
  int32_t strsz = _strlen(str);
  if ( strsz > 0 ) {
    for ( idx = 0; (str[idx] != ch) && (idx < strsz - 1); idx++ ) { }
    if ( str[idx] == ch ) {
      ret = idx;
    }
    else {
      ret = -1;
    }
  }
  return ret;
}		/* -----  end of function _find_ch  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  _add_new_ch
 *  Description:  Add new character to buffer and increment counter.
 * =====================================================================================
 */
static inline void _add_new_ch ( uint8_t newchar )
{
  _ucmd_s.buff[_ucmd_s.cnt] = newchar;
  _ucmd_s.cnt++;
  return;
}		/* -----  end of function _add_new_ch  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _is_eol_ch
 *  Description:  Returns true if the current char is an end of line character.
 * =====================================================================================
 */
STATIC inline uint8_t _is_eol_ch (uint8_t ch)
{
  return (ch == uCMD_CHAR_LF) ||
         (ch == uCMD_CHAR_CR);
}		/* -----  end of function _is_eol_ch  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _is_alpha_num
 *  Description:  Returns true if character is alpha-numeric.
 * =====================================================================================
 */
STATIC INLINE uint8_t _is_alpha_num ( uint8_t chr )
{
  return ((chr >= uCMD_CHAR_A)  &&
          (chr <= uCMD_CHAR_Z)) ||
         ((chr >= uCMD_CHAR_a)  &&
          (chr <= uCMD_CHAR_z)) ||
         ((chr >= uCMD_CHAR_0)  &&
          (chr <= uCMD_CHAR_9));
}		/* -----  end of function _is_alpha_num  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _new_ch_callback
 *  Description:  Handles new char event. This function runs in interrupt context.
 * =====================================================================================
 */
static void _new_ch_callback (void* params)
{
  DBG_CATCH_NULL_PTR(params);
  uint8_t newchar = *((uint8_t*)params);

  /* If buffer is empty and end of line character received, just ignore it and return. */
  /* If an end character is received after the message is complete, ignore it and return. */
  /* If buffer is overflown, a character cannot be normally added. Wait for recovery conditions. */
  if(!uCmd_BuffIsFull() &&
     !(uCmd_BuffIsEmpty() && (_is_eol_ch(newchar) || (newchar == uCMD_CHAR_SPACE))) &&
     ! uCmd_BuffIsOvrFlwn()) {

    /* If buffer is not empty and end of message character received, signal a message */
    /* complete so that command can be processed. Also replace end character with */
    /* null character so that it can be processed as a null-terminated string. */
    if(!uCmd_BuffIsEmpty() && _is_eol_ch(newchar)) {
      _ucmd_s.iscmplt = true;
      _add_new_ch(uCMD_NULL_CHAR);
      /* Call string parser. */
    }

    /* If this is the last character that fits into buffer and no end of message caharacter */
    /* has been received, then signal overflow condition. */
    /* When an overflow condition has happened, flush the buffer and ignore all characters */
    /* until a new end of line has been received as previous command was invalid. */
    else if(uCmd_GetCnt() == (uCMD_BUFF_SIZE - 1)) {
      _ucmd_s.isovrflwn = true;
      uCmd_FlushBuff();

    } else {
      /* This is a valid char and command is not complete. Add it to buffer. */
      _add_new_ch(newchar);
    }
  } else if (uCmd_BuffIsOvrFlwn() && _is_eol_ch(newchar)) {
    /* Are conditions valid to recover from overflow? */
    _ucmd_s.isovrflwn = false;
    uCmd_FlushBuff();
  }
  return;
}		/* -----  end of function _new_ch_callback  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_Init
 *  Description:  Initialize uCmd module.
 * =====================================================================================
 */
void uCmd_Init (uCmd_CharRxCallback* fncptr) {
  /* DBG_CATCH_NULL_PTR(fncptr); */
  uCmd_FlushBuff();
  _ucmd_s.isovrflwn = false;
  /* Connect char rx interrupt to new char handle function. */
  *fncptr = _new_ch_callback;
}		/* -----  end of function uCmd_Init  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_BuffIsFull
 *  Description:  Buffer is full flag is set.
 * =====================================================================================
 */
uint8_t uCmd_BuffIsFull (void)
{
  return _ucmd_s.cnt >= uCMD_BUFF_SIZE;
}		/* -----  end of function uCmd_BuffIsFull  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_GetBuff
 *  Description:  Copy raw buffer, whatever is in there. This function assumes there is
                  enough space in the target buffer to copy all data.
 * =====================================================================================
 */
void uCmd_GetBuff (uint8_t* buff)
{
  memcpy((void*)buff, (void*)_ucmd_s.buff, sizeof(_ucmd_s.buff));
}		/* -----  end of function uCmd_GetBuff  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_BuffIsEmpty
 *  Description:  Buffer is empty flag.
 * =====================================================================================
 */
uint8_t uCmd_BuffIsEmpty (void)
{
  return _ucmd_s.cnt == 0;
}		/* -----  end of function uCmd_BuffIsEmpty  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_GetCnt
 *  Description:  Get the current number of bytes in buffer.
 * =====================================================================================
 */
uint8_t uCmd_GetCnt (void)
{
  return _ucmd_s.cnt;
}		/* -----  end of function uCmd_GetCnt  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_FlushBuff
 *  Description:  Set contents of buffer to zero and reset counter.
 * =====================================================================================
 */
void uCmd_FlushBuff (void) {
  memset((void*)_ucmd_s.buff, 0, sizeof(_ucmd_s.buff));
  _ucmd_s.iscmplt = false;
  _ucmd_s.cnt = 0;
  return;
}		/* -----  end of function uCmd_FlushBuff  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_IsCmplt
 *  Description:  Signals that the raw command is ready to be processed.
 * =====================================================================================
 */
uint8_t uCmd_IsCmplt (void)
{
  return _ucmd_s.iscmplt;
}		/* -----  end of function uCmd_IsCmplt  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_BuffIsOvrFlwn
 *  Description:  Signals that buffer has been overflown.
 * =====================================================================================
 */
uint8_t uCmd_BuffIsOvrFlwn ( void )
{
  return _ucmd_s.isovrflwn;
}		/* -----  end of function uCmd_BuffIsOvrFlwn  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_ParseStr
 *  Description:  Parse raw command and return the pointer to the command to run
 *                and its argument.
 * =====================================================================================
 */
uCmd_St uCmd_ParseStr (uint8_t* str, uCmd_Callback* fncptr, int32_t* fcnarg)
{
  int32_t idx;
  uCmd_St ret = uCmd_NullPtr_E;
  if(str && fncptr && fcnarg) {
    memset((void*)_ucmd_name, 0, sizeof(_ucmd_name));
    memset((void*)_ucmd_arg, 0, sizeof(_ucmd_arg));
    idx = _get_cmd_str(str, _ucmd_name);
    _get_arg_str(&str[idx], _ucmd_arg);
  }
  return ret;
}		/* -----  end of function uCmd_ParseStr  ----- */
