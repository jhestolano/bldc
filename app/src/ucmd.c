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

/*-----------------------------------------------------------------------------
 *  Macro detiniftions.
 *-----------------------------------------------------------------------------*/
#define uCMD_BUFF_SIZE (16)
#define uCMD_CHAR_LF (10)
#define uCMD_CHAR_CR (13)
#define uCMD_NULL_CHAR (0)

/*-----------------------------------------------------------------------------
 *  Structure type definitions.
 *-----------------------------------------------------------------------------*/
typedef struct _uCmd_S {
  uint8_t buff[uCMD_BUFF_SIZE + 1]; /* Buffer memory. +1 for null char. */
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
static void uCmd_NewCharCallback (void* params);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_Init
 *  Description:  Initialize uCmd module.
 * =====================================================================================
 */
void uCmd_Init (uCmd_CharRxCallback* fncptr) {
  DBG_CATCH_NULL_PTR(fncptr);
  memset((void*)&_ucmd_s, 0, sizeof(_ucmd_s));
  _ucmd_s.isempty = true;
  _ucmd_s.cnt = 0;

  /* Connect char rx interrupt to new char handle function. */
  *fncptr = uCmd_NewCharCallback;
}		/* -----  end of function uCmd_Init  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_NewCharCallback
 *  Description:  Handles new char event. This function runs in interrupt context.
 * =====================================================================================
 */
static void uCmd_NewCharCallback (void* params)
{
  DBG_CATCH_NULL_PTR(params);
  uint8_t newchar = *((uint8_t*)params);

  if(_ucmd_s.isfull) {
    /* Handle & set overrun error. */
    DBG_DEBUG("Buffer full. Ignoring char.\n\r");
    return;
  }

  if ( ((newchar == uCMD_CHAR_LF) || (newchar == uCMD_CHAR_CR)) && (_ucmd_s.isempty) ) {
    /* If a Line Feed or Carriage Return character is received on an empty buffer, */
    /* just ignore it as it does not make sense to add to buffer for process. This also */
    /* protects for the case when a terminal sends LF+CR when hitting Enter. */
    return;
  } else if ( ((newchar == uCMD_CHAR_LF) || (newchar == uCMD_CHAR_CR)) && (!_ucmd_s.isfull )) {
    /* NOTE: The end of the sequence has been received, but there is no guarantee yet */
    /* as to if the command is valid or not. This flag just means that is ready to */
    /* be processed. */
    _ucmd_s.iscmplt = true;

    /* Replace end character with the null character. The command processing */
    /* module does not care about end char, but about C-null string character. */
    _ucmd_s.buff[_ucmd_s.cnt] = uCMD_NULL_CHAR;
    DBG_DEBUG("Cmd complete.\n\r");
  } else if (!_ucmd_s.isfull) {
    _ucmd_s.iscmplt = false;
    _ucmd_s.isempty = false;
    _ucmd_s.buff[_ucmd_s.cnt] = newchar;
    _ucmd_s.cnt++;
  }

  if ( _ucmd_s.cnt >= uCMD_BUFF_SIZE ) {
    DBG_DEBUG("Buffer is full.\n\r");
    _ucmd_s.isfull = true;
  } else {
    _ucmd_s.isfull = false;
  }

  /* Make sure it is always null char terminated. */
  _ucmd_s.buff[uCMD_BUFF_SIZE] = uCMD_NULL_CHAR;
  return;
}		/* -----  end of function uCmd_NewCharCallback  ----- */
