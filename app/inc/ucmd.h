/*
 * ===================================================================================== Filename:  ucmd.h
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

/*-----------------------------------------------------------------------------
 *  Macro detiniftions.
 *-----------------------------------------------------------------------------*/
#define uCMD_BUFF_SIZE (16)
#define uCMD_CHAR_LF (10)
#define uCMD_CHAR_CR (13)
#define uCMD_CHAR_SPACE (32)
#define uCMD_CHAR_BRK (uCMD_CHAR_SPACE)
#define uCMD_NULL_CHAR (0)
#define uCMD_MAX_CMD_SIZE (8)
#define uCMD_MAX_ARG_SIZE (8)
#define uCMD_CHAR_0 (48)
#define uCMD_CHAR_9 (57)
#define uCMD_CHAR_A (65)
#define uCMD_CHAR_Z (90)
#define uCMD_CHAR_a (97)
#define uCMD_CHAR_z (122)
#define uCMD_MAX_STR_LEN (64)

/*-----------------------------------------------------------------------------
 * Global variable definitions. 
 *-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * Type definitions. 
 *-----------------------------------------------------------------------------*/
typedef void (*uCmd_CharRxCallback)(void* params);
typedef void (*uCmd_Callback)(void* arg);

typedef enum {
  uCmd_Ok_E = 0,
  uCmd_NullPtr_E = 1,
  uCmd_Unknwn_E = 255,
} uCmd_St;

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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_FlushBuff
 *  Description:  Set contents of buffer to zero and reset counter.
 * =====================================================================================
 */
void uCmd_FlushBuff (void);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_IsCmplt
 *  Description:  Signals that the raw command is ready to be processed.
 * =====================================================================================
 */
uint8_t uCmd_IsCmplt (void);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_BuffIsOvrFlwn
 *  Description:  Signals that buffer has been overflown.
 * =====================================================================================
 */
uint8_t uCmd_BuffIsOvrFlwn ( void );

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uCmd_ParseStr
 *  Description:  Parse raw command and return the pointer to the command to run
 *                and its argument.
 * =====================================================================================
 */
uCmd_St uCmd_ParseStr (uint8_t* str, uCmd_Callback* fncptr, int32_t* fcnarg);
