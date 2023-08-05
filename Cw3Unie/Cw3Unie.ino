#include "Adafruit_TinyUSB.h"
//różne typy 16 bitowe, w przypadku unii dzielą one przestrzeń w //pamięci mikrokontolera
  union Krotkie { //Unia składa się z
   byte b[2]; //Tablicy dwóch bajtów
   int i; //zmiennej int o nazwie i
   unsigned int ui; //zmiennej int bez znaku
  } krotkie;


void print_16Bit (void)
{
  Serial.println (krotkie.i);
  Serial.println (krotkie.ui);
  Serial.print (krotkie.b[1],HEX);
  Serial.println (krotkie.b[0],HEX);
  Serial.println ("");
}

void setup() {
  //Port szeregowy do przesyłania danych (opis w ćwiczeniu //wprowadzającym do Arduino
  Serial.begin(115200);
  while (!Serial) {
    delay(10); // Czekaj na połączenie
  }
//Wpisuje do unii krotkie jako int
  krotkie.i = (int)(-6);
  print_16Bit();//Wypisanie wartości unii

  //wpisanie danych do Uni jako dwa bajty
  byte b[2]= {0x8F,0x10};
  krotkie.b[1] = b[1];
  krotkie.b[0] = b[0];
  print_16Bit();
}

void loop ()
{}
