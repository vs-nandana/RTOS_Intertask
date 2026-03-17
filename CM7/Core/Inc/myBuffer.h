/*
 * myBuffer.h
 *
 *  Created on: 16-Mar-2026
 *      Author: nandana
 */

#ifndef INC_MYBUFFER_H_
#define INC_MYBUFFER_H_

#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "main.h"          // for Command_t enum

/* Buffer size */
#define RX_BUFFER_SIZE 5

/* Extern — buffer is defined in mybuffer.c,
   accessed in main.c and callback */
extern char    rxBuff[RX_BUFFER_SIZE];
extern uint8_t rxChar;
extern uint8_t rxIndex;

typedef enum
{
	CMD_STARTUP=0,
	CMD_UNKNOWN,
    CMD_LED_ON ,
    CMD_LED_OFF,
    CMD_SLOW_BLINK,
    CMD_FAST_BLINK

} Command_t;

/* Function declaration */
Command_t ParseCommand(const char *str);


#endif /* INC_MYBUFFER_H_ */
