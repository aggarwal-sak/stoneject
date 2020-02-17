#include <ESP8266WiFi.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include "OneButton.h"  
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

/******************GPS SETTINGS***********************************/

TinyGPSPlus gps;  // The TinyGPS++ object
SoftwareSerial ss(D3,D4); // The serial connection to the GPS device
float latitude , longitude;
int year , month , date, hour , minute , second;
String date_str , time_str , lat_str , lng_str;
int pm;

/********************GPS_END*************************************/

/*************ACCELEROMETER DEFINITIONS**************************/

/*CONNECTIONS
 * SCL--->>>D1
 * SDA--->>>D2 
 */
MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;
String aax,aay,aaz;
#define OUTPUT_READABLE_ACCELGYRO

#define LED_PIN LED_BUILTIN
bool blinkState = false;
/********************END_ACCELERO********************************/

/*****************UPDATE BUTTON**********************************/

/*CONNECTIONS
 * BUTTON---->>> D7
 * LED---->>> D8
 */
OneButton button(D7, true);                         //attach a button on pin A1 to the libraRY
#define UPDATE_LED D8
/*********************END_BUTTON********************************/

/********************WIFI_SETTINGS******************************/
const char* ssid     = "nissan";
const char* password = "password";
const char* host = "iotprojectnis.000webhostapp.com";
const int httpPort = 80;
String send_str;
/*********************END_WIFI*********************************/
void accelero();
void setup() 
{
  Serial.begin(115200);
    pinMode(UPDATE_LED, OUTPUT);
 //GPS
    ss.begin(9600);
 //END
 
//ACCELERO
    Wire.begin();
    accelgyro.initialize();
//END

//WIFI
  // WiFi.begin(ssid, password); 
//END
 Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() 
{
//  WiFiClient client;
//  if (!client.connect(host, httpPort)) {
//    Serial.println("connection failed");
//    return;
//  }
//    while (ss.available() > 0)
//if (gps.encode(ss.read()))
//    {
//      if (gps.location.isValid())
//      {
//        latitude = gps.location.lat();
//        lat_str = String(latitude , 6);
//        longitude = gps.location.lng();
//        lng_str = String(longitude , 6);
//      }
//
//      if (gps.date.isValid())
//      {
//        date_str = "";
//        date = gps.date.day();
//        month = gps.date.month();
//        year = gps.date.year();
//
//        if (date < 10)
//          date_str = '0';
//        date_str += String(date);
//
//        date_str += " / ";
//
//        if (month < 10)
//          date_str += '0';
//        date_str += String(month);
//
//        date_str += " / ";
//
//        if (year < 10)
//          date_str += '0';
//        date_str += String(year);
//      }
//
//      if (gps.time.isValid())
//      {
//        time_str = "";
//        hour = gps.time.hour();
//        minute = gps.time.minute();
//        second = gps.time.second();
//
//        minute = (minute + 30);
//        if (minute > 59)
//        {
//          minute = minute - 60;
//          hour = hour + 1;
//        }
//        hour = (hour + 5) ;
//        if (hour > 23)
//          hour = hour - 24;
//
//        if (hour >= 12)
//          pm = 1;
//        else
//          pm = 0;
//
//        hour = hour % 12;
//
//        if (hour < 10)
//          time_str = '0';
//        time_str += String(hour);
//
//        time_str += " : ";
//
//        if (minute < 10)
//          time_str += '0';
//        time_str += String(minute);
//
//        time_str += " : ";
//
//        if (second < 10)
//          time_str += '0';
//        time_str += String(second);
//
//        if (pm == 1)
//          time_str += " PM ";
//        else
//          time_str += " AM ";
//
//      }
//
//    }
//    Serial.print(time_str);
//    Serial.print(", ");
//    Serial.print(date_str);
//    Serial.print(", ");
//    Serial.print(lat_str);
//    Serial.print(", ");
//    Serial.println(lng_str);
//  accelero();//ax,ay,az,gx,gy,gz values from here
//  aax=String(ax);
//  aay=String(ay);
//  aaz=String(az);
//String send_str = String("GET ") + "/api/fridge/insert.php?lat="+lat_str+"&lon="+lng_str+"&time="+time_str+"&date="+date_str+"&x="+aax+"&y="+aay+"&z="+aaz+"&class="+"A" + " HTTP/1.1\r\n" +
//               "Host: " + host + "\r\n" + 
//               "Connection: close\r\n\r\n" ;
////https://iotprojectnis.000webhostapp.com/api/fridge/insert.php?lat=12&lon=11&time=1&date=2&x=3&y=4&z=2&class=10
////  client.print(send_str);
//// Serial.println(send_str);
//  delay(500);
  
     while (ss.available() > 0)
    if (gps.encode(ss.read()))
    {
      if (gps.location.isValid())
      {
        latitude = gps.location.lat();
        lat_str = String(latitude , 6);
        longitude = gps.location.lng();
        lng_str = String(longitude , 6);
      }

      if (gps.date.isValid())
      {
        date_str = "";
        date = gps.date.day();
        month = gps.date.month();
        year = gps.date.year();

        if (date < 10)
          date_str = '0';
        date_str += String(date);

        date_str += " / ";

        if (month < 10)
          date_str += '0';
        date_str += String(month);

        date_str += " / ";

        if (year < 10)
          date_str += '0';
        date_str += String(year);
      }

      if (gps.time.isValid())
      {
        time_str = "";
        hour = gps.time.hour();
        minute = gps.time.minute();
        second = gps.time.second();

        minute = (minute + 30);
        if (minute > 59)
        {
          minute = minute - 60;
          hour = hour + 1;
        }
        hour = (hour + 5) ;
        if (hour > 23)
          hour = hour - 24;

        if (hour >= 12)
          pm = 1;
        else
          pm = 0;

        hour = hour % 12;

        if (hour < 10)
          time_str = '0';
        time_str += String(hour);

        time_str += " : ";

        if (minute < 10)
          time_str += '0';
        time_str += String(minute);

        time_str += " : ";

        if (second < 10)
          time_str += '0';
        time_str += String(second);

        if (pm == 1)
          time_str += " PM ";
        else
          time_str += " AM ";

      }

    }
    Serial.print(time_str);
    Serial.print(", ");
    Serial.print(date_str);
    Serial.print(", ");
    Serial.print(lat_str);
    Serial.print(", ");
    Serial.println(lng_str);

}



void accelero()
{
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
}


