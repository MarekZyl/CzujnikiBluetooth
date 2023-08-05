#include "Adafruit_TinyUSB.h"
void setup() 
{
  Serial.begin(9600);
  while (!Serial) {
    delay(10); // Czekaj na połączenie
  }

  Serial.println("A");
  byte a;
  Serial.println(a,BIN); 
  a = (1<<3);
  Serial.println(a,BIN);
  a |= (1<<5);
  Serial.println(a,BIN);

  Serial.println("B");
  byte b = 36;
  b = (b>>1);
  Serial.println(b,DEC);

  Serial.println("C");
  byte c = 72;
  bool d = 72&0b1000;
  Serial.println(c,BIN);
  Serial.println(d);
}

void loop() 
{}
