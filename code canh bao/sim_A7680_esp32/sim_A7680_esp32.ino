#include "main.h"
const char* ssid = "KS Chuong"; //Enter SSID
const char* password = "0946627518"; //Enter Password

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600 * 7;
const int   daylightOffset_sec = 3600 * 0;


void get_real_time(void);
void warning(void);

uint32_t time_millis;
uint32_t time_warning1;


uint8_t count_warning1;
uint8_t count_time;
uint8_t old_count_time;

uint16_t count_sensor ;

typedef struct
{
  uint8_t sensor;
  uint8_t bnt1;
  uint8_t bnt2;
  uint8_t bnt3;
  uint8_t bnt4;
  uint8_t warning;
} Status;
Status status;

typedef struct
{
  uint8_t sec;
  uint8_t min;
  uint8_t hour;
  uint8_t day;
  uint8_t date;
  uint8_t month;
  uint8_t year;
} gio;
gio Time;



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

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);


}

void loop() {
  // put your main code here, to run repeatedly:
  status.sensor = READ_SENSOR;
  //Serial.println(status.sensor);
  get_real_time();
  warning();

}


/************* lay thoi gian thuc ************/
void get_real_time(void)
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
  }
  if (millis() - time_millis > 1000)
  {
    count_time ++;
    time_millis = millis();
  }
  if (old_count_time != count_time)
  {
    //Serial.println(&timeinfo, "%B %d %Y %H:%M:%S");
    Time.sec = timeinfo.tm_sec;
    Time.min = timeinfo.tm_min;
    Time.hour = timeinfo.tm_hour;
    Time.day  = timeinfo.tm_mday;
    Time.month = timeinfo.tm_mon;
    Time.year  = timeinfo.tm_year;
    old_count_time = count_time;
  }
}

/*************** canh bao khi co rung **************/
void warning(void)
{
  if (status.sensor == 1 && status.warning == 0)
  {
    status.warning = 1;
  }
  /********** khi bat dau tac dong ***********/
  if (status.warning == 1)
  {
    if (status.sensor == 1) count_sensor++;
    if (millis() - time_warning1 > 1000)
    {
      count_warning1 ++;
      if(count_warning1 > 9) count_warning1 = 10;
      time_warning1  = millis();
    }
    if(count_warning1 == 10)
    {
      Serial.println(count_sensor);
      status.warning = 2;
    }
  }
  /*********** sau 10s tac dong ************/
  if(status.warning == 2)
  {
    if(count_sensor >= LEVEL_RING1) status.warning = 3;
    else 
    {
      status.warning = 0;
      count_sensor = 0;
    }
  }
  /********* neu du dieu kien tac dong ******/
  if(status.warning == 3)
  {
    
  }

  

}
