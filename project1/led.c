/********************************************************
 * led.c
 *
 * this file provides function defenitions for SER486
 * led library functions.  Blink is implemented using
 * a hardware-based timer and finite state machine (FSM)
 * in order to improve system latency characteristics.
 *
 * Author:   Ty Foster
 * Date:     11/13/2020
 * Revision: 1.0
 *
 * Copyright(C) 2020, Arizona State University
 * All rights reserved
 *
 * functions are:
 *      set_blink(char *) - sets blink pattern to a new
 *                      message, clears FSM
 *
 *      update(void) - called in main control loop to
 *                      update the state of the LED FSM
 */
#include "delay.h"
#include "led.h"

/* ATTRIBUTES */
#define PORTB (*((volatile char *) 0x25))
#define DDRB (*((volatile char *) 0x24))
#define PHASE1 10;
#define PHASE2 20;
char * blink_msg;
unsigned int blink_pos;
unsigned char blink_state;

/* METHODS */
/**********************************
 * set_blink(char * msg)
 *
 * Sets the blink pattern to a new
 *  message, clears the blink FSM.
 *
 * arguments:
 *   msg - pointer to char array to
 *      use as the message
 *
 * returns:
 *   nothing
 *
 * changes:
 *   FSM for LED
 *   sets LED to off state
 */
void led_set_blink(char * msg) {
    /* blink_msg = msg */
    blink_msg = msg;
    /* blink_pos = 0 */
    blink_pos = 0;
    /* blink_state = PHASE1 */
    blink_state = PHASE1;
    /* delay_set(0,0) */
    delay_set(0,0);
    /* led_off */
    led_off();
}

/**********************************
 * update(void)
 *
 * Updates the state of the FSM.
 *
 * arguments:
 *   nothing
 *
 * returns:
 *   nothing
 *
 * changes:
 *   LED FSM state
 */
void led_update(void) {
    /* if blink_msg = 0, done */
    if (blink_msg != 0) {
        /* if !delay_isdone(0), done */
        if (!delay_isdone(0)) {
            /* update FSM */
            blink_state = PHASE2;
        }
    }
}
