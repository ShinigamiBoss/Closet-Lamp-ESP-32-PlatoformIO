#include <Arduino.h>
#include "include/LED Parametes.h"

// Button state read
uint16_t buttonState;
int ButtonIn = 32;

void setup()
{
  //Setup external wakeup
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_32, 0);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Starting process...");
  // Set pins number
  SetPins(23, 22, 21, 19);
  InitializeLED();

  //Set button input
  pinMode(ButtonIn, INPUT_PULLUP);

  while(digitalRead(ButtonIn) == LOW)
  {
    WriteLED(55, 221, 215, 0);
  }

  WriteLED(0, 0, 0,0);

  Serial.println("Going to sleep...");

  esp_deep_sleep_start();
  
}

void loop()
{
  //Not used due to deep sleep
}
