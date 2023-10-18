#include "USB.h"
#include "USBHIDKeyboard.h"
USBHIDKeyboard Keyboard;
bool run = false;

const int buttonPin = 0;
void setup(){
  pinMode(buttonPin, INPUT_PULLUP);

  Keyboard.begin();

  USB.PID(0x07F8);
  USB.VID(0x045E);
  USB.productName("USB Keyboard");
  USB.manufacturerName("Microsoft");
  USB.begin();
}

void loop(){
  while (digitalRead(buttonPin) == HIGH){
    if(run){
      Keyboard.write(KEY_CAPS_LOCK);
      delay(500);
    }
    else{
      delay(500);
    }
  }
  delay(1000);
  run = !run;
}
