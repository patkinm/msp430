#pragma once

#include "stdafx.h"
#include "LaunchPad.h"
#include "lcd16.h"


/*
	Pump p1.1;



*/

class Pump
{
public:
  
  	Pump();
	
	~Pump();
	
	void Run();

	int GetLowTemp()
	{
		return mTempLow;
	}
	
	int GetHighTemp()
	{
		return mTempHigh;
	}
	
	int GetControlTemp()
	{
		return mTempControl;
	}
	
	void UpdateTemps()
	{
	    mTempLow = LaunchPad::GetInstance().GetADCData(5) * 0.404f - 273;      //Pin 1.5
		mTempHigh = LaunchPad::GetInstance().GetADCData(6) * 0.404f - 273;     //Pin 1.6
		mTempControl = LaunchPad::GetInstance().GetADCData(7) * 0.404f - 273;  //Pin 1.7
	}
	
	void ShowTemps(int row);
	
	void RunPump()
	{
		LaunchPad::GetInstance().SetPin(PUMP, true);  
		TurnOnPumpLed();
	};
	
	void StopPump()
	{
		LaunchPad::GetInstance().SetPin(PUMP, false);
		TurnOffPumpLed();		
	};
	
	bool IsPumpRun()
	{
		return LaunchPad::GetInstance().IsPin(PUMP);  
	};
	
	void TurnOnPumpLed()
	{
		LaunchPad::GetInstance().SetPin(PUMPLED, true);  
	}
	
	void TurnOffPumpLed()
	{
		LaunchPad::GetInstance().SetPin(PUMPLED, false);  
	}

private:
  	
  	static int PUMP;
	static int PUMPLED;
  	static int ADC1;
  	static int ADC2;
	static int ADC3;
	
  	int mTempLow;
	
	int mTempHigh;
	
	int mTempControl;

};