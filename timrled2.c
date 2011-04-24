// timrled2.c - toggles LEDs with period of about 1.0s
// Poll timer A in Up mode with period of about 0.5s
// Timer clock is SMCLK divided by 8, up mode, period 50000
// Launchpad v1.3 , LED1,2 active high on P1.0,6
// J H Davies, 2006-06-16;
// Launchpad port: S Reig, 2011-04-24; Code Composer Studio v4.2.3
// ----------------------------------------------------------------------

#include <msp430g2231.h>    // Specific device

// Pins for LEDs
#define LED1 BIT0
#define LED2 BIT6

void main (void) {
    WDTCTL = WDTPW|WDTHOLD;             // Stop watchdog timer
    P1OUT = LED1;                       // Preload LED1 on , LED2 off
    P1DIR = LED1|LED2;                  // Set pins for LED1 ,2 to output
    TACCR0 = 65499;                     // Upper limit of count for TAR
    TACTL = MC_1|ID_3|TASSEL_2|TACLR;   // Set up and start Timer A
// "Up to CCR0" mode , divide clock by 8, clock from SMCLK , clear timer
    for (;;) {                          // Loop forever
        while ((TACTL & TAIFG) == 0) {  // Wait for overflow
        }                               // doing nothing
        TACTL &= ~TAIFG;                // Clear overflow flag
        P1OUT ^= LED1|LED2;             // Toggle LEDs
    }                                   // Back around infinite loop
}
