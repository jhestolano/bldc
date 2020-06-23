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
/* #include "uart.h" */
#include <stdbool.h>
#include "dbg.h"
#include <stdio.h>

/*-----------------------------------------------------------------------------
 *  Macro detiniftions.
 *-----------------------------------------------------------------------------*/
#define uCMD_CHAR_LF (10)
#define uCMD_CHAR_CR (13)
#define uCMD_NULL_CHAR (0)

/*-----------------------------------------------------------------------------
 *  Structure type definitions.
 *-----------------------------------------------------------------------------*/
typedef struct _uCmd_S {
  uint8_t buff[uCMD_BUFF_SIZE]; /* Buffer memory. */
  uint8_t isempty; /* Buffer is empty flag. */
  uint8_t isfull; /* Buffer is full flag. */
  uint8_t iscmplt; /* Message complete flag. */
  uint16_t cnt; /* Number of elements in buffer. */
} uCmd_S;

/*-----------------------------------------------------------------------------
 *  Static global variables.
 *-----------------------------------------------------------------------------*/
static volatile uCmd_S _ucmd_s;

/*-----------------------------------------------------------------------------
 * Static function prototypes. 
 *-----------------------------------------------------------------------------*/
static void _new_ch_callback (void*);
static void _new_ch_proc(uint8_t);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _new_ch_proc
 *  Description:  Process newly received char.
 * =====================================================================================
 */
void _new_ch_proc ( uint8_t newchar )
{
  /* If buffer is empty and end of message character received, just ignore it and return. */

  /* If buffer is not empty and end of message character received, signal a message */
  /* complete so that command can be processed. Also replace end character with */
  /* null character so that it can be processed as a null-terminated string. */

  /* If this is the last character that fits into buffer and no end of message caharacter */
  /* has been received, then signal overflow condition. */

  /* When an overflow condition has happened, flush the buffer and ignore all characters */
  /* until a new end of line has been received as previous command was invalid. */
  _ucmd_s.buff[_ucmd_s.cnt] = newchar;
  return;
}		/* -----  end of function _new_ch_proc  ----- */

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
  if(_ucmd_s.isfull) {
    return;
  }
  _new_ch_proc(newchar);
  _ucmd_s.cnt++;
  if(_ucmd_s.cnt >= uCMD_BUFF_SIZE) {
    _ucmd_s.isfull = true;
  }
}		/* -----  end of function _new_ch_callback  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_Init
 *  Description:  Initialize uCmd module.
 * =====================================================================================
 */
void uCmd_Init (uCmd_CharRxCallback* fncptr) {
  /* DBG_CATCH_NULL_PTR(fncptr); */
  memset((void*)&_ucmd_s, 0, sizeof(_ucmd_s));
  _ucmd_s.isempty = true;
  _ucmd_s.cnt = 0;
  _ucmd_s.isfull = false;
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
  return _ucmd_s.isfull;
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
  return _ucmd_s.isempty;
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
