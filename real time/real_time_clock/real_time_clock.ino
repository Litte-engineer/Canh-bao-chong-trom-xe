#include <WiFi.h>
#include "time.h"

const char* ssid = "Đoàn KA"; // Name of the Wi-Fi box
const char* password = "hoikhanh"; // MDP of the Wi-Fi box

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600 * 7;
const int   daylightOffset_sec = 3600 * 0;


typedef struct
{
  uint8_t sec;
  uint8_t min;
  uint8_t hour;
  uint8_t day;
  uint8_t date;
  uint8_t month;
} gio;
gio Time;

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.mode(WIFI_STA); // Optional
  WiFi.begin(ssid, password);
  Serial.println("\nConnecting");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.println("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());

  // We configure the NTP server
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
  }

  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  Time.hour = timeinfo.tm_hour; 
  Serial.println(Time.hour);



  delay(1000);
}
