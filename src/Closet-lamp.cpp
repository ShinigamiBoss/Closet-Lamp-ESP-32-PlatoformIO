#include <Arduino.h>
#include "include/LED Parametes.h"

// Button state read
uint16_t buttonState;
int ButtonIn = 12;

int DarkSeaGreen[4] = {193, 255, 193, 0};
int MediumTurquoise[4] = {112, 219, 219, 0};
int AcquaMarine[4] = {127,255, 212,0};
int SeaGreen[4] = {84, 255, 159, 0};
int Tiffany[4] = {0, 128, 255, 0};
int Tiffany2[4] = {0, 0, 255, 0};

int Test1[4] = {128, 0, 255, 0};
int Test2[4] = {0, 128, 255, 0};
int Test3[4] = {0, 0, 255, 0};


#define ONBOARD_LED 22

void setup()
{
  //Setup external wakeup
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_12, 1);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Starting process...");
  // Set pins number
  SetPins(32, 33, 25, 26);
  InitializeLED();

  //Set button input
  pinMode(ButtonIn, INPUT_PULLUP);

  //pinMode(ONBOARD_LED,OUTPUT);

  //Serial.println("Digital read: ");
  //Serial.println(digitalRead(ButtonIn));

  while(digitalRead(ButtonIn) == HIGH)
  {
    //turn on the LED
    //WriteLED(55, 221, 215, 0);
    WriteLED(64,220,128,0);
  }

  WriteLED(0, 0, 0,0);

  Serial.println("Going to sleep...");

  esp_deep_sleep_start();
  
}

void loop()
{
  //Not used due to deep sleep
}
