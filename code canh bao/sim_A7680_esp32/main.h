#ifndef MAIN_H
#define MAIN_H

#include<WiFi.h>
#include <FirebaseESP32.h>
#include <stdio.h>
#include <EEPROM.h>
#include <Arduino.h>
#include <SoftwareSerial.h>

#define sim  Serial2

FirebaseData firebaseData;
WiFiClient client;
String  path = "/";
FirebaseJson json;

#define FIREBASE_HOST "https://pzemt-iot-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "JY9IoWAjx649T8XKBYH9jJAinAmfVhbtMxkGbBRN"

const char* ssid = "KS Chuong"; //Enter SSID
const char* password = "0946627518"; //Enter Password











#endif
