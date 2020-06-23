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

typedef void (*uCmd_CharRxCallback)(void* params);

void uCmd_Init(uCmd_CharRxCallback* fncptr);

