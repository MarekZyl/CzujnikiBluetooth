#include <bluefruit.h>

BLEService        BatteryService = BLEService(0x180F);
BLECharacteristic BatteryLevel = BLECharacteristic(0x2A19);

void setup() 
{
  Bluefruit.begin();
  Bluefruit.setTxPower(-4);    
  Bluefruit.setName("Rudy102");
  Bluefruit.Advertising.addName();
  Bluefruit.Advertising.setInterval(160, 160);   
  Bluefruit.Advertising.setFastTimeout(1); 

  BatteryService.begin();

	BatteryLevel.setProperties(CHR_PROPS_READ);
//Alternatywnie: BatteryLevel.setProperties(CHR_PROPS_NOTIFY);
 	BatteryLevel.setPermission(SECMODE_OPEN,SECMODE_NO_ACCESS);
 	BatteryLevel.setFixedLen(1); 
// Alternatywnie: .setMaxLen(uint16_t len)
  BatteryLevel.begin();

  uint8_t data[1] = {10};
 	BatteryLevel.write(data,1);

  Bluefruit.Advertising.start(0); 

  suspendLoop();
}


void loop() 
{
  
}
