#include <Wire.h>

byte I2C_write(byte SAD, byte SUB, byte DATA)
{
  Wire.beginTransmission (SAD);
  Wire.write (SUB);
  Wire.write (DATA);
  return Wire.endTransmission ();
}


byte I2C_read(byte SAD, byte SUB)
{
  Wire.beginTransmission (SAD);
  Wire.write (SUB);
  Wire.endTransmission (false);

  Wire.requestFrom (SAD,byte(1));
  byte value;
  value = Wire.read();

  return value;
}

void setup() 
{
  Wire.begin();
 
  pinMode(13, OUTPUT);      
  I2C_read(0x1C, 0x0F);
}

void loop()
{

}
