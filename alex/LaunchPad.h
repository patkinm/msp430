#pragma once

#include <msp430g2553.h>



#include "stdafx.h"
#include "Direction.h"


class LaunchPad
{
public:

	static LaunchPad& GetInstance()
	{
      	return launchPadInstance;
	}

	void InitPin(int numberOfPin, Direction direct)
	{
		if(direct == Out)
		{
	 		P1DIR |= 0x01 << numberOfPin; // Set to output direction
		}
		else if(direct == In)
		{
	 		P1DIR &= ~(0x01 << numberOfPin); // Set to output direction
		}
	}
	
	void SetPin(int numberOfPin, bool stateOfBit)
	{
		if(stateOfBit)
		{
	 		P1OUT |= 0x01 << numberOfPin; // Set to output direction
		}
		else if(!stateOfBit)
		{
	 		P1OUT &= ~(0x01 << numberOfPin); // Set to output direction
		}
	}
	
	bool IsPin(int numberOfPin)
	{
	  	if((P1OUT & (0x01 << numberOfPin)) == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
	bool GetPin(int numberOfPin)
	{
	  	if((P1IN & (0x01 << numberOfPin)) == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
        
        void InitADC(char serialNumber)
        {
            ADC10CTL0 = ADC10ON | SREF_0 | ADC10SHT_3;// | REF2_5V | REFOUT;
            ADC10CTL1 = serialNumber * 0x1000u | ADC10DIV_7 | ADC10SSEL_2;
            ADC10AE0 = 1 << serialNumber;
        }

	int GetADCData(char serialNumber)
	{
		            ADC10CTL0 = ADC10ON | SREF_0 | ADC10SHT_3;// | REF2_5V | REFOUT;
            ADC10CTL1 = serialNumber * 0x1000u | ADC10DIV_7 | ADC10SSEL_2;
            ADC10AE0 = 1 << serialNumber;
	  	int avg = 0;
		for (uchar i = 0; i < 16; i++)
		{
		  ADC10CTL0 |= ENC | ADC10SC;
		  while (ADC10CTL1 & ADC10BUSY) {};
		  avg += ADC10MEM;
		}
		int tmp = avg / 16;
		return tmp;
	}
  
private:
  
  static LaunchPad launchPadInstance;
    
  LaunchPad();
  
  ~LaunchPad();
};
