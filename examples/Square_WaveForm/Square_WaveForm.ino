// WSystem -- Walter P.
// Milan - Italy
// note*: to use this library with Arduino Uno it's better to set the timers available into the header file at 5 or 10
// this library works well with Arduino Mega , DUE
// in this example I use a push button to start the soft timer but you can use everything is boolean such as bit or output or direct input
// this library is written in Atmel Studio 6.2 + Visual Micro for Atmel Studio 
// I suggest to use this tool instead Arduino IDE to have more benefit such as intellisense, list of fields , methods and else
// It is possible to use Visual Studio + Visual Micro for Visual Studio 

#include <WTimer.h>

#define ledpin 13    // led on Arduino UNO
#define pb 5
WTimer mytimers;     // My library declaration

boolean state=false;

void setup()
{
	pinMode(ledpin,OUTPUT);
	digitalWrite(ledpin, LOW);
        pinMode(pb,INPUT);
		
	mytimers.initTimers(millis());
	mytimers.enableClocks();
	
}

void loop()
{
        mytimers.runTimers(millis());                                       // this method is called every cycle of  program
        state=digitalRead(pb);
        if(!state)
        {
            digitalWrite(ledpin,mytimers.SquareWave.C.freq7);               // the led blink at clock8 frequency
	}
        else
        {
            digitalWrite(ledpin,mytimers.SquareWave.C.freq9);               // the led blink at clock8 frequency
        }
	
	  //  you can also create mixed frequency in this way 
	  //  digitalWrite(ledpin,mytimers.SquareWave.C.freq8 && mytimers.SquareWave.C.freq4);     

}


