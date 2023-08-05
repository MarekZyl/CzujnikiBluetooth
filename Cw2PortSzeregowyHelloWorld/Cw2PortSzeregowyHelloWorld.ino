#include "Adafruit_TinyUSB.h"

void setup() {
  Serial.begin(9600);             //zainicjuj port szeregowy
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello world!"); //wyślij wiadomość
  delay(1000);
}
