#ifndef MAIN_H
#define MAIN_H

#include<WiFi.h>
#include <FirebaseESP32.h>
#include <stdio.h>
#include <EEPROM.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Timezone.h>

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

#define BUZZER 5
#define BUZZER_ON  digitalWrite(BUZZER, HIGH)
#define BUZZER_OFF digitalWrite(BUZZER, LOW)

#define SENSOR   7
#define READ_SENSOR   digitalRead(SENSOR)


#define BNT1   1
#define BTN2   2
#define BNT3   3
#define BNT4   4


#define READ_BNT1    digitalRead(BNT1)
#define READ_BNT2    digitalRead(BNT2)
#define READ_BNT3    digitalRead(BNT3)
#define READ_BNT4    digitalRead(BNT4)


const char* ssid = "KS Chuong"; //Enter SSID
const char* password = "0946627518"; //Enter Password



WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

Timezone myTZ;
const int utcOffsetInSeconds = 7 * 3600;








#endif
