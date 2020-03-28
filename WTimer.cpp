// Walter P.
// 29/07/2014

#include "WTimer.h"

void WTimer::initTimers(unsigned long millis)
{
   int i;
   for(i=0;i<MAX_TIMERS;i++)
   {
	   timer[i].Counter=0;
   }
   
   mem_millis=millis;
   clockEnable=false;
   SquareWave.W=0;

}

bool WTimer::presetTimer(int numTimer,int preset,int type)
{
	 if(numTimer > MAX_TIMERS -1 || type > 2 || type < 1)
	 {
		 numTimer=MAX_TIMERS -1;
		 return false;
	 }

	 timer[numTimer].Preset=preset;
	 timer[numTimer].Type=type;
	 return true;

}

void WTimer::enableClocks()
{
	clockEnable=true;
}

void WTimer::disableClocks()
{
	clockEnable=false;
}

void WTimer::runClocks()
{
	SquareWave.W+=deltaTime;
	if(SquareWave.W >= 65000)
	{
		SquareWave.W=0;
	}
}

unsigned long WTimer::getDeltaTime()
{
	return deltaTime;
}

void WTimer::runTimers(unsigned long millis)
{
    int i;
    deltaTime=millis - mem_millis;
	if(abs(deltaTime)> 10000)
	{
		deltaTime=lastdeltaTime;
	}
	
    for(i=0;i<MAX_TIMERS;i++)
    {
	    switch(timer[i].Type)
	    {
		    case TON: runTimerTON(i);
		    break;

		    case TOF: runTimerTOF(i);
		    break;
	    }
    }
	 
	if(clockEnable==true)
	{
		runClocks();
	} 
	
	lastdeltaTime=deltaTime;
	mem_millis=millis;
}


void WTimer::runTimerTON(int numTimer)
{
	if(timer[numTimer].Start==true && timer[numTimer].Counter < timer[numTimer].Preset)
	{
		timer[numTimer].Counter+=deltaTime; 
	}
	if (timer[numTimer].Start==false)
	{
		timer[numTimer].Counter=0;
	}

	timer[numTimer].Done=(timer[numTimer].Start==true) && (timer[numTimer].Counter >= timer[numTimer].Preset);
}

void WTimer::runTimerTOF(int numTimer)
{
	if(timer[numTimer].Start==true)
	{
		timer[numTimer].mem=true;
	}
	if(timer[numTimer].Start==false && timer[numTimer].mem==true && (timer[numTimer].Counter < timer[numTimer].Preset))
	{
		timer[numTimer].Counter+=deltaTime; 
	}
	if( timer[numTimer].Counter >= timer[numTimer].Preset)
	{
		timer[numTimer].mem=false;
		timer[numTimer].Counter=0;
	}
	timer[numTimer].Done=(timer[numTimer].Start==true) || (timer[numTimer].Counter < timer[numTimer].Preset && timer[numTimer].mem==1);
}
