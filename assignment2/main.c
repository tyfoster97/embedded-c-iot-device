/**
 * @author Ty Foster
 * @version 2020.10.22
 * SER486 - Assignment 2
 */

#include <avr/io.h>
//#define DDRB (*((volatile char *) 0x24))
//#define PORTB (*((volatile char *) 0x25))
#define SIM_TIME 35
#define HARD_TIME 100

void delay(int ms) {
    int i, j;
    for(i = 1; i < ms; i++) {
        for(j = 1; j < HARD_TIME; j++) {
        }
    }
}

int main(void)
{
    DDRB |= 0x02; //initialize pin 1 as output

    while(1) {
        PORTB |= 0x02; // toggle pin on
        delay(2000); // wait 2s
        PORTB &= 0xFD; // toggle pin off
        delay(2000); // wait 2s
    }

    return 0;
}
