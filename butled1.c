// butled1.c - press button to light LED
// Single loop with "if"
// Launchpad v1.3 board, LED1 active high on P1.0,
// button B1 active high on P1.3
// J H Davies, 2006-06-01;
// Launchpad port: S Reig, 2011-04-23; Code Composer Studio v4.2.3
// ----------------------------------------------------------------------

#include <msp430g2231.h>    // Specific device
// Pins for LED and button on port 1
#define LED1	BIT0
#define B1	BIT3

void main (void)
{
  WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
  P1DIR |= LED1;            // Set pin with LED1 to output
  for (;;){                 // Loop forever
    if ((P1IN & B1) == 0) { // Is button down?
    	P1OUT |= LED1;      // Yes: Turn LED1 on
    } else {
	P1OUT &= ~LED1;     // No: Turn LED1 off
    }
  }
}
