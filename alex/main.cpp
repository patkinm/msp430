//#include "lcd16.c"



#include "Pump.h"

int main (void)
{ 
  	WDTCTL = WDTPW + WDTHOLD;  // stop watchdog timer
	
  	Pump myPump;
	
	myPump.Run();
  
  

}





