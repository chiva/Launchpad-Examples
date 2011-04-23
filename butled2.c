// butled2.c - press button to light LED
// Two loops , one for each state of the button
// Launchpad v1.3 board, LED1 active high on P1.0,
// button B1 active high on P1.3
// J H Davies, 2006-06-01;
// Launchpad port: S Reig, 2011-04-23; Code Composer Studio v4.2.3
// ----------------------------------------------------------------------

#include <msp430g2231.h>       // Specific device
// Pins for LED and button on port 1
#define LED1	BIT0
#define B1	BIT3

void main (void)
{
  WDTCTL = WDTPW + WDTHOLD;    // Stop watchdog timer
  P1DIR |= LED1;               // Set pin with LED1 to output
  
  for (;;) {                   // Loop forever
    while ((P1IN & B1) == 0) { // Loop while button up
    }                          // doing nothing
// Actions to be taken when button is pressed
    P1OUT |= LED1;             // Turn LED1 on
    while ((P1IN & B1) != 0) { // Loop while button down
    }                          // doing nothing
// Actions to be taken when button is released
    P1OUT &= ~LED1;            // Turn LED1 off
  }
}
