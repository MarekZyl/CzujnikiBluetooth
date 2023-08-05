#include <bluefruit.h>

void setup() 
{
  Bluefruit.begin();
  Bluefruit.setTxPower(-4);    
  Bluefruit.setName("Rudy102");
  Bluefruit.Advertising.addName();
  Bluefruit.Advertising.setInterval(160, 160);   
  Bluefruit.Advertising.setFastTimeout(1);
  Bluefruit.Advertising.start(0);    
  suspendLoop();//Funkcja zatrzymuje wykonywanie pętli loop
}

void loop() 
{
  // pętla nie będzie wykonywana
}
