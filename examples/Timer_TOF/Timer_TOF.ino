// WSystem -- Walter P.
// Milan - Italy
// note*: to use this library with Arduino Uno it's better to set the timers available into the header file at 5 or 10
// this library works well with Arduino Mega , DUE
// in this example I use a push button to start the soft timer but you can use everything is boolean such as bit or output or direct input

#include <WTimer.h>

#define ledpin 13    // led on Arduino UNO
#define pb 5         // push button connected on Arduino in pull down configuration
WTimer mytimers;     // My library declaration


void setup()
{
	pinMode(ledpin,OUTPUT);
	digitalWrite(ledpin, LOW);
	pinMode(pb,INPUT);
	
	mytimers.presetTimer(10,5000,TOF);                             // Preset the timer #10 for 5 seconds (5000 ms), type TOF
	mytimers.initTimers(millis());
	
	
}

void loop()
{
	mytimers.runTimers(millis());                                    // this method is called every cycle of  program
	
	mytimers.timer[10].Start=digitalRead(pb);                        //push the button and the led will light on
	
	
	digitalWrite(ledpin,mytimers.timer[10].Done);                    // when you release the button the led remains again on for 5 sec.
                                                                         // and then it will light off automatically
}