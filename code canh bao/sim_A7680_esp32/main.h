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




#endif
