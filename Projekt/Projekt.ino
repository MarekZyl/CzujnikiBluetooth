#include <bluefruit.h>
#include <Adafruit_NeoPixel.h>

#define PIN       8

//Deklaracja obiektu klasy Adafruit_NeoPixel
Adafruit_NeoPixel pixels(1, PIN, NEO_GRB);
//Deklaracja serwisu i charakteystyki GATT
BLEService        RGBService = BLEService(0xBEEF);
BLECharacteristic RGBColor = BLECharacteristic(0xABBA);

void RGBwrite_callback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len)
{
  //Zapis do charakterystyki ustala nowy kolor diody
  uint32_t color = pixels.Color(data[0], data[1], data[2]);
  pixels.setPixelColor(0, color);
  pixels.show();
}

void setup() 
{
  //Konfiguracja rozgłaszania
  Bluefruit.begin();  
  Bluefruit.setTxPower(-4);    
  Bluefruit.setName("RGB");
  Bluefruit.Advertising.addName();
  Bluefruit.Advertising.setInterval(160, 160);   
  Bluefruit.Advertising.setFastTimeout(1); 

//Konfiguracja serwisu GATT
  RGBService.begin();
  RGBColor.setProperties(CHR_PROPS_WRITE|CHR_PROPS_READ); 
  RGBColor.setPermission(SECMODE_OPEN,SECMODE_OPEN);    
  RGBColor.setFixedLen(3);
  RGBColor.setWriteCallback(RGBwrite_callback);   
  RGBColor.begin();

//Inicjalizacja obiektu dla diody RGB
  pixels.begin();

  Bluefruit.Advertising.start(0); 
  suspendLoop();
}

void loop() {
  // put your main code here, to run repeatedly:

}
