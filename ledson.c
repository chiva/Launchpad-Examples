// ledson.c - simple program to light LEDs
// Sets pin to output , lights pattern of LEDs , then loops forever
// Launchpad v1.3 with LEDs active high on P1.0,6
// J H Davies , 2006-05-17;
// Launchpad port: S Reig , 2011-04-23; Code Composer Studio v4.2.3
// ----------------------------------------------------------------------
#include <msp430g2231.h>		// Specific device

void main (void)
{
	WDTCTL = WDTPW | WDTHOLD; 	// Stop watchdog timer
	P1DIR = 0x41; 		// Set pins with LEDs to output , 0b01000001
	P1OUT = 0x01; 		// LED1 (P1.0) on
	for (;;) {			// Loop forever ...
	}					// ... doing nothing
}
