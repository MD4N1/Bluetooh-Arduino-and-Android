/* Demo Pengendali LED jarak jauh dengan Bluetooth Dongle dan USB Host Shield
 * Perangkat yang digunakan:
 * 1. Arduino Duemilanove 328p
 * 2. USB Host Shield, library dapat di download di https://github.com/felis/USB_Host_Shield_2.0
 * 3. USB Bluetooth Dongle (bebas)
 * 4. Smartphone Android minimal Ginger Bread
 * 5. Aplikasi BluetoothAndroidAndroid.apk, source code Arduino asli dll., dapat didownload di https://github.com/mharkus/BluetoothArduinoAndroid
*/

#include <Arduino.h>
#include <Usb.h>
#include <SPP.h>
#include <usbhub.h>

USB Usb;
BTD Btd(&Usb); // Buat Bluetooth Dongle
SPP SerialBT(&Btd, "MD4N1 Arduino","1234"); //Nama Devais Bluetooh Dongle dan PIN nya

char val[4];
int pin1 = 2;
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;
int pin5 = 6;
int pin6 = 7;
int index = 0;

void setup()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  Serial.begin(57600);
  if (Usb.Init() == -1)
  {
    while (1); //halt
  }
  //Serial.println("Kendali Jarak Jauh siap");
}

void loop()
{
  Usb.Task();
  if (SerialBT.connected)
  {
   if(SerialBT.available())
   {
    if(index < 3)
    {
      val[index] = SerialBT.read();
      SerialBT.print(val[index]);
      index++;
    }

    val[index] = '\0';

    SerialBT.println("");
    if(index == 3)
    {
      if(strcmp("p11", val) == 0)
      {
        digitalWrite(pin1, HIGH);
        //Serial.print("Pin "); Serial.print(pin1); Serial.println(" Nyala");
        Serial.print("p11");
      }
      else if(strcmp("p10", val) == 0)
      {
        digitalWrite(pin1, LOW);
        //Serial.print("Pin "); Serial.print(pin1); Serial.println(" Padam");
        Serial.print("p10");
      }
      else if(strcmp("p21", val) == 0)
      {
        digitalWrite(pin2, HIGH);
        //Serial.print("Pin "); Serial.print(pin2); Serial.println(" Nyala");
        Serial.print("p21");
      }
      else if(strcmp("p20", val) == 0)
      {
        digitalWrite(pin2, LOW);
        //Serial.print("Pin "); Serial.print(pin2); Serial.println(" Padam");
        Serial.print("p20");
      }
      else if(strcmp("p31", val) == 0)
      {
        digitalWrite(pin3, HIGH);
        //Serial.print("Pin "); Serial.print(pin3); Serial.println(" Nyala");
        Serial.print("p31");
      }
      else if(strcmp("p30", val) == 0)
      {
        digitalWrite(pin3, LOW);
        //Serial.print("Pin "); Serial.print(pin3); Serial.println(" Padam");
        Serial.print("p30");
      }
      else if(strcmp("p41", val) == 0)
      {
        digitalWrite(pin4, HIGH);
        //Serial.print("Pin "); Serial.print(pin4); Serial.println(" Nyala");
        Serial.print("p41");
      }
      else if(strcmp("p40", val) == 0)
      {
        digitalWrite(pin4, LOW);
        //Serial.print("Pin "); Serial.print(pin4); Serial.println(" Padam");
        Serial.print("p40");
      }
      else if(strcmp("p51", val) == 0)
      {
        digitalWrite(pin5, HIGH);
        //Serial.print("Pin "); Serial.print(pin5); Serial.println(" Nyala");
        Serial.print("p51");
      }
      else if(strcmp("p50", val) == 0)
      {
        digitalWrite(pin5, LOW);
        //Serial.print("Pin "); Serial.print(pin5); Serial.println(" Padam");
        Serial.print("p50");
      }
      else if(strcmp("p61", val) == 0)
      {
        digitalWrite(pin6, HIGH);
        //Serial.print("Pin "); Serial.print(pin6); Serial.println(" Nyala");
        Serial.print("p61");
      }
      else if(strcmp("p60", val) == 0)
      {
        digitalWrite(pin6, LOW);
        //Serial.print("Pin "); Serial.print(pin6); Serial.println(" Padam");
        Serial.print("p60");
      }
      else if(strcmp("ar1", val) == 0)
      {
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, HIGH);
        //Serial.print("Pin "); Serial.print(pin1); Serial.print(",");Serial.print(pin2); Serial.print(",");Serial.print(pin3); Serial.println(" Nyala");
        Serial.print("ar1");
      }
      else if(strcmp("ar0", val) == 0)
      {
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        //Serial.print("Pin "); Serial.print(pin1); Serial.print(",");Serial.print(pin2); Serial.print(",");Serial.print(pin3); Serial.println(" Padam");
        Serial.print("ar0");
      }
      else if(strcmp("ag1", val) == 0)
      {
        digitalWrite(pin4, HIGH);
        digitalWrite(pin5, HIGH);
        digitalWrite(pin6, HIGH);
        //Serial.print("Pin "); Serial.print(pin4); Serial.print(",");Serial.print(pin5); Serial.print(",");Serial.print(pin6); Serial.println(" Nyala");
        Serial.print("ag1");
      }
      else if(strcmp("ag0", val) == 0)
      {
        digitalWrite(pin4, LOW);
        digitalWrite(pin5, LOW);
        digitalWrite(pin6, LOW);
        //Serial.print("Pin "); Serial.print(pin4); Serial.print(",");Serial.print(pin5); Serial.print(",");Serial.print(pin6); Serial.println(" Padam");
        Serial.print("ag0");
      }
      index = 0;
    }
   }
  }
}
