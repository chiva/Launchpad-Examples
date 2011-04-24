// flashled.c - toggles LEDs with period of about 1s
// Software delay for() loop
// Launchpad v1.3 board, LED1,2 active high on P1.0,6
// J H Davies, 2006-06-03;
// Launchpad port: S Reig, 2011-04-23; Code Composer Studio v4.2.3
// ----------------------------------------------------------------------

#include <msp430g2231.h>          // Specific device

// Pins for LEDs
#define LED1 BIT0
#define LED2 BIT6
// Iterations of delay loop; reduce for simulation
#define DELAYLOOPS 50000

void main (void){
  volatile unsigned int LoopCtr;  // Loop counter: volatile!
  
  WDTCTL = WDTPW | WDTHOLD;       // Stop watchdog timer
  P1OUT = LED1;                   // Preload LED1 on , LED2 off
  P1DIR = LED1|LED2;              // Set pins with LED1 ,2 to output
  for(;;){                        // Loop forever
    for (LoopCtr = 0; LoopCtr < DELAYLOOPS; ++LoopCtr){
    }                             // Empty delay loop
    P1OUT ^= LED1|LED2;           // Toggle LEDs
  }
}
