

#include "Pump.h"

int Pump::PUMP = 1;
int Pump::PUMPLED = 0;
int Pump::ADC1 = 5;
int Pump::ADC2 = 6;
int Pump::ADC3 = 7;

Pump::Pump()
{
	lcdinit();
   	gotoXy(0, 0);
  	prints("Pump init...");
	__delay_cycles (1000000);
	LaunchPad::GetInstance().InitPin(PUMP, Out);
	LaunchPad::GetInstance().InitPin(PUMPLED, Out);
	
	
  	mTempLow = LaunchPad::GetInstance().GetADCData(ADC1);      //Pin 1.5
	mTempHigh = LaunchPad::GetInstance().GetADCData(ADC2);     //Pin 1.6
	mTempControl = LaunchPad::GetInstance().GetADCData(ADC3);  //Pin 1.7
	
	
};

Pump::~Pump()
{
	
};

void Pump::Run()
{
	clear();
  	while(true)
	{
		ShowTemps(1);
		
		if(mTempLow < 500)
			RunPump();
		else
		  	StopPump();
		
		if(IsPumpRun())
		{
		  	gotoXy(0, 0);
		  	prints("Pump On ");
		}
		else
		{
			gotoXy(0, 0);
		  	prints("Pump Off");
		}
		
		

	
	
	
	
	
	
	}; 
	 
};

void Pump::ShowTemps(int row)
{
	UpdateTemps();
  
  	gotoXy(0, row);
	prints("L:");
	gotoXy(3, row);
	prints(mTempLow);
	
	gotoXy(8, row);
	prints("H:");
	gotoXy(11, row);
	prints(mTempHigh);
		
//	gotoXy(13, row);
//	prints("C:");
//	gotoXy(10, row);
//	prints(mTempControl);
};



