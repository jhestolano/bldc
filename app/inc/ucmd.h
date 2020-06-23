/*
 * =====================================================================================
 *
 *       Filename:  ucmd.h
 *
 *    Description:  : micro-command line.
 *
 *        Version:  1.0
 *        Created:  06/21/2020 09:29:32 PM
 *       Revision:  none
 *       Compiler:  arm-none-eabi-gcc
 *
 *         Author:  Pickman22
 *   Organization:  elrobotista.com
 *
 * =====================================================================================
 */
#include <stdint.h>

#define uCMD_BUFF_SIZE (16)

typedef void (*uCmd_CharRxCallback)(void* params);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_Init
 *  Description:  Initialize uCmd module.
 * =====================================================================================
 */
void uCmd_Init(uCmd_CharRxCallback* fncptr);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_BuffIsEmpty
 *  Description:  Buffer is empty flag.
 * =====================================================================================
 */
uint8_t uCmd_BuffIsEmpty (void);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_GetCnt
 *  Description:  Get the current number of bytes in buffer.
 * =====================================================================================
 */
uint8_t uCmd_GetCnt (void);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_BuffIsFull
 *  Description:  Buffer is full flag is set.
 * =====================================================================================
 */
uint8_t uCmd_BuffIsFull (void);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_GetBuff
 *  Description:  Copy raw buffer, whatever is in there. This function assumes there is
                  enough space in the target buffer to copy all data.
 * =====================================================================================
 */
void uCmd_GetBuff (uint8_t* buff);
