#include <Arduino.h>
#include "include/LED Parametes.h"

// Button state read
uint16_t buttonState;
int ButtonIn = 32;

void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // Set pins number
  SetPins(23, 22, 21, 19);
  InitializeLED();

  //Set button input
  pinMode(ButtonIn, INPUT_PULLUP);

  
}

void loop()
{
  // read the state of the pushbutton value
  buttonState = digitalRead(ButtonIn);
  
  Serial.println(buttonState);  
  
  if (buttonState == 1)
  {
    WriteLED(55, 221,215,0);
  }
  else
  {
    WriteLED(0, 0, 0,0);
  }
}
