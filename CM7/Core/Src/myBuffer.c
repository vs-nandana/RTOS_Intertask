/*
 * myBuffer.c
 *
 *  Created on: 16-Mar-2026
 *      Author: nandana
 */
#include "myBuffer.h"

/* Buffer definitions — live here, not in main.c */
char    rxBuff[RX_BUFFER_SIZE];
uint8_t rxChar  = 0;
uint8_t rxIndex = 0;

Command_t ParseCommand(const char *str)
{
    /* Temporary copy so we don't modify the original */
    char upper[RX_BUFFER_SIZE];
    strncpy(upper, str, RX_BUFFER_SIZE - 1);
    upper[RX_BUFFER_SIZE - 1] = '\0';  // safety null terminate

    /* Convert to uppercase */
    for(int i = 0; upper[i]; i++)
        upper[i] = toupper((unsigned char)upper[i]);

    /* Compare and return command */
    if     (strcmp(upper, "ON")   == 0) return CMD_LED_ON;
    else if(strcmp(upper, "OFF")  == 0) return CMD_LED_OFF;
    else if(strcmp(upper, "SLOW") == 0) return CMD_SLOW_BLINK;
    else if(strcmp(upper, "FAST") == 0) return CMD_FAST_BLINK;
    else                                return CMD_UNKNOWN;
}

