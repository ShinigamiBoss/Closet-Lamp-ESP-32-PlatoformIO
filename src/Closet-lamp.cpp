#include <Arduino.h>
#include "include/LED Parametes.h"

//Button state read
uint16_t buttonState;

void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  //Set pins number
  SetPins(23,22,21,19);
  InitializeLED();
}

void loop()
{
  // read the state of the pushbutton value
  buttonState = analogRead(A6);

    if (buttonState <= 200)
    {
      WriteLED(55, 221,215,0);
    }
    else
    {
      WriteLED(0, 0, 0,0);
    }
}
