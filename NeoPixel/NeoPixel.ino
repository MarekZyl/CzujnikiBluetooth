#include <Adafruit_NeoPixel.h>
#define PIN       8
#define NUMPIXELS 1

//Deklaracja obiektu klasy Adafruit_NeoPixel
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB);

//Stałe określające poszczególne kolory
#define PEACH 200,50,5
#define CYAN 10,150,70
#define PURPLE 180,3,180
#define BLUE 5,5,190
#define WHITE 150,150,150
#define GREEN 10,180,10

//Tablica przechowuje kolejne kolory dla diody
uint32_t colors[7] = {pixels.Color(PEACH), pixels.Color(CYAN), 
   pixels.Color(PURPLE), pixels.Color(BLUE), pixels.Color(WHITE), 
   pixels.Color(GREEN), pixels.Color(0,0,0)};

void setup() {
  // Inicjalizacja klasy
  pixels.begin();
}

//Pętla wyświetla kolejne kolory zdefiniowane w tablicy
void loop() {
   for (byte i = 0; i < 7; i++)
   {
    pixels.setPixelColor(0, colors[i]);
    pixels.show();
    delay(500);
   }  
}
