#include <Arduino.h>

#include <Wire.h>

void setup()
{
  // When using the ESP32 with the Arduino IDE, use the Wire.h library to communicate with devices using I2C.
  // With this library, you initialize the I2C as follows:
  // Wire.begin(I2C_SDA, I2C_SCL);
  // viable options for SDA are 21, 33
  // viable options for SCL are 22, 32
  // Default if there are no arguments are SDA=21, SCL=22
  
  Wire.begin(21, 22);
  Serial.begin(115200);
  Serial.println("\nI2C Scanner");
}

void loop()
{
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for (address = 1; address < 127; address++)
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
      {
        Serial.print("0");
      }
      Serial.println(address, HEX);
      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknow error at address 0x");
      if (address < 16)
      {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
  {
    Serial.println("No I2C devices found\n");
  }
  else
  {
    Serial.println("done\n");
  }
  delay(5000);
}