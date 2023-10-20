#include "USB.h"
#include "USBHIDKeyboard.h"

USBHIDKeyboard Keyboard;
volatile bool run = false;
const int buttonPin = 0;
const int ledPin = 15;

//CONFIG
const int interval = 500;
const byte key = KEY_END;
//END CONFIG

void setup(){
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), changeState, RISING);

  Keyboard.begin();

  USB.PID(0x07F8);
  USB.VID(0x045E);
  USB.productName("USB Keyboard");
  USB.manufacturerName("Microsoft");
  USB.begin();
}

void loop(){
    if(run){
      Keyboard.write(key);
      digitalWrite(ledPin,HIGH);
    }
    else{
      digitalWrite(ledPin,LOW);
    }
    delay(interval);
}

void changeState(){
    run = !run;
}
