#include "main.h"
const char* ssid = "KS Chuong"; //Enter SSID
const char* password = "0946627518"; //Enter Password

uint32_t Time;
uint16_t count;

typedef struct
{
  uint8_t sensor;
  uint8_t bnt1;
  uint8_t bnt2;
  uint8_t bnt3;
  uint8_t bnt4;

} Status;
Status status;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  sim.begin(115200);
  gps.begin(9600);

  EEPROM.begin(512);


  pinMode(BUZZER, OUTPUT);
  pinMode(SENSOR, INPUT);
  pinMode(BNT1, INPUT_PULLUP);
  pinMode(BNT2, INPUT_PULLUP);
  pinMode(BNT3, INPUT_PULLUP);
  pinMode(BNT4, INPUT_PULLUP);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  timeClient.begin();
  myTZ.setLocation("Asia/Ho_Chi_Minh");


}

void loop() {
  // put your main code here, to run repeatedly:
  status.sensor = READ_SENSOR;





}
