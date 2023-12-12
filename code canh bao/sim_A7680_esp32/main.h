#ifndef MAIN_H
#define MAIN_H

#include <WiFi.h>
#include <FirebaseESP32.h>
#include <stdio.h>
#include <EEPROM.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include "time.h"


#define sim  Serial2

#define GPS_TX 18
#define GPS_RX 19
SoftwareSerial gps;

FirebaseData firebaseData;
WiFiClient client;
String  path = "/";
FirebaseJson json;

#define FIREBASE_HOST "https://pzemt-iot-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "JY9IoWAjx649T8XKBYH9jJAinAmfVhbtMxkGbBRN"

#define BUZZER 32
#define BUZZER_ON  digitalWrite(BUZZER, HIGH)
#define BUZZER_OFF digitalWrite(BUZZER, LOW)

#define SENSOR   34
#define READ_SENSOR   digitalRead(SENSOR)


#define BNT1   13
#define BNT2   12
#define BNT3   14
#define BNT4   27


#define READ_BNT1    digitalRead(BNT1)
#define READ_BNT2    digitalRead(BNT2)
#define READ_BNT3    digitalRead(BNT3)
#define READ_BNT4    digitalRead(BNT4)

#define LEVEL_RING1   30000
#define LEVEL_RING_OFF  100

#define ADD_MUM         0




/***** luu du lieu tu EEPROM ********/
void EEPROM_put(int add, String Data)
{
  for (int i = 0; i < 10 ; i++)
  {
    EEPROM.write(i + add, Data[i]);
    EEPROM.commit();
  }
}
/******** lay du lieu tu eeprom *********/
String EEPROM_get(int add)
{
  String sdt = "";
  for (int i = add; i < add + 10; i++)
  {
    char c  = EEPROM.read(i);
    sdt += (String)c;
  }
  return sdt;
}

void sim_at_wait()
{
  delay(500);
  if (sim.available())
  {
    Serial.println(sim.readString());
  }
}
bool sim_at_cmd(String cmd)
{
  sim.println(cmd);
  //delay(500);
  sim_at_wait();
}
bool sim_at_send(char c) {
  sim.write(c);
}


void sent_sms(String mumber, String mess)
{
  String num = (String)mumber[1] + (String)mumber[2] + (String)mumber[3]
               + (String)mumber[4] + (String)mumber[5] + (String)mumber[6] + (String)mumber[7]
               + (String)mumber[8] + (String)mumber[9];
  Serial.println(num);
  String com = "+84" + (String)num;
  Serial.println(com);
  sim_at_cmd("AT+CMGF=1");
  String temp = "AT+CMGS=\"";
  temp += (String)com;
  temp += "\"";
  sim_at_cmd(temp);
  sim_at_cmd(mess);
  sim_at_send(0x1A);
  delay(1000);
}

void sim_init(void)
{
  sim_at_cmd("AT");
  sim_at_cmd("ATI");
  sim_at_cmd("AT+CPIN?");
  sim_at_cmd("AT+CSQ");
  sim_at_cmd("AT+CIMI");
}

void sim_call(String mumber)
{
  
}



#endif
