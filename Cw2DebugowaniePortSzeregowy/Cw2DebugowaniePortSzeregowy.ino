#include "Adafruit_TinyUSB.h"
//Zmienne globalne widoczne we wszystkich funkcjach
int a = 0;
int b = 200;
char buffer[40];//Tablica znaków

void setup() {
  Serial.begin(9600);//inicjalizacja portu szeregowego 
  Serial.println("Port zaincjowany"); //Potwierdzenie zaincjowania                                            //portu
}

void loop() {
  a++;				     //W każdej iteracji zwiększ a o 1
  sprintf(buffer, "%d,%d", a, b);  //Formatowania ciągu znaków
  Serial.println(buffer);	     //Prześlij wiadomość
  delay(50);                       //Odczekaj 50 ms.
}
