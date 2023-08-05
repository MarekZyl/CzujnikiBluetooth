#include <bluefruit.h>

void connect_callback(uint16_t conn_handle)
{
  digitalWrite(LED_RED, HIGH);  
}

void disconnect_callback(uint16_t conn_handle, uint8_t reason)
{
  digitalWrite(LED_RED, LOW);
}

void setup() 
{
  Bluefruit.begin();
 	Bluefruit.setTxPower(-4);    
 	Bluefruit.setName("Rudy102");
  Bluefruit.Advertising.addName();
 	Bluefruit.Advertising.setInterval(160, 160);   
 	Bluefruit.Advertising.setFastTimeout(1);

 	Bluefruit.Periph.setConnectCallback(connect_callback);
	Bluefruit.Periph.setDisconnectCallback(disconnect_callback);
   
  pinMode(LED_RED, OUTPUT);

  Bluefruit.Advertising.start(0); 

  suspendLoop();
}


void loop() 
{
  
}
