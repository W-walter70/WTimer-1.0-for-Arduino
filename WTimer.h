// This library can be used when the user has to delay one or more events
// Likely in automation programming , plc for example , the use of delay blocking method isn't good 
// The delay(x) method locks the flow of the program , try to image if you have a pump or motors or lights to control while the program is stopped by the delay ...
// There are types of timer functionality , TON and TOF 
// TON -> delay after event , you must to push a button and after a programmable timing , the lamp or the motor will start 
// If the timer.Done isn't true of if it is , when you release the button the timer.Done will commute on false 
// TOF .> delay after event , when you push the button immediately the timer.Done is true but when you release the button just only after a programming time
// the timer.Done will commute to false.The timer.Done is used in digitalWrite() method for example 
// 29/07/2014  Written by 
// Walter Porcellini Milan-Italy
// 

#ifndef _WTIMER_h
 #define _WTIMER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

 #define  MAX_TIMERS       30    // Timers available
 #define  MAX_DELTA_TIME   100   // maximum delta time for each scan is 100 milliseconds 
 #define  TON  1
 #define  TOF  2

 // Timer structure

 typedef struct
 {
	 bool Start;           // Start timer
	 unsigned int Preset;    // Timer preset (milliseconds)
	 unsigned int Counter;   // Timer accumulator
	 bool Done;            // Timer output
	 unsigned int Type;      // TON or TOF , type of timer
	 bool mem;             // memory used for timer TOF
 }sTimer;

typedef struct sClock
{
	unsigned int freq1:1 ;
	unsigned int freq2:1 ;
	unsigned int freq3:1 ;
	unsigned int freq4:1 ;
	unsigned int freq5:1 ;
	unsigned int freq6:1 ;
	unsigned int freq7:1 ;
	unsigned int freq8:1 ;
	unsigned int freq9:1 ;
	unsigned int freq10:1 ;
	unsigned int freq11:1 ;
    unsigned int freq12:1 ;
	unsigned int freq13:1 ; 
	unsigned int freq14:1 ;
	unsigned int freq15:1 ;
	unsigned int freq16:1 ;
}clockType;

union u_Clocks
{
	unsigned int W;
	clockType        C;
};

class WTimer
{
  protected:

  public:
	 void initTimers(unsigned long millis);
     bool presetTimer(int numTimer,int preset,int type);
	 void runTimers(unsigned long millis);
	 unsigned long getDeltaTime();
	 void enableClocks();
	 void disableClocks();
	 sTimer timer[MAX_TIMERS]  ;
     u_Clocks SquareWave;
	 
  private:
     bool clockEnable;
	 unsigned long deltaTime;
	 unsigned long mem_millis;
	 unsigned long lastdeltaTime;
     void runTimerTON(int numTimer);
     void runTimerTOF(int numTimer);
	 void runClocks();	
};


 
#endif

