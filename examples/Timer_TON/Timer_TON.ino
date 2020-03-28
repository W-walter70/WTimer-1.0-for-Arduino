// WSystem -- Walter P. 
// Milan - Italy 
// note*: to use this library with Arduino Uno it's better to set the timers available into the header file at 5 or 10
// this library works well with Arduino Mega , DUE 
// in this example I use a push button to start the soft timer but you can use everything is boolean such as bit or output or direct input 

#include <WTimer.h>

#define ledpin 13    // led on Arduino UNO
#define pb 5         // push button connected on Arduino in pull down configuration
WTimer mytimers;    // My library declaration


void setup()
{
	pinMode(ledpin,OUTPUT);
	digitalWrite(ledpin, LOW);
	pinMode(pb,INPUT);
		
	mytimers.presetTimer(1,3000,TON);                             // Preset the timer #1 for 3 seconds (3000 ms), type TON
	mytimers.initTimers(millis());
	
	
}

void loop()
{
	mytimers.runTimers(millis());                                    // this method is called every cycle of  program
		
	mytimers.timer[1].Start=digitalRead(pb);                         //push the button
	
	
	digitalWrite(ledpin,mytimers.timer[1].Done);                     // and after 3 sec. the led will light on
	                                                                 // when the button is released the led will light off
	
}