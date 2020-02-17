#include <ESP8266WiFi.h>
/************************mpu6050*****************************/


#include "MPU6050.h"

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69
MPU6050 accelgyro;
//MPU6050 accelgyro(0x69); // <-- use for AD0 high
int16_t ax, ay, az;
int16_t gx, gy, gz;
// uncomment "OUTPUT_READABLE_ACCELGYRO" if you want to see a tab-separated
// list of the accel X/Y/Z and then gyro X/Y/Z values in decimal. Easy to read,
// not so easy to parse, and slow(er) over UART.
#define OUTPUT_READABLE_ACCELGYRO

void mpu_getValues();

/*************************end*******************************/


/************************thingspeak**************************/

String apiKey = "4OFYC0INTEKXZAFF";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "abcd";     // replace with your wifi ssid and wpa2 key
const char *pass =  "nishanchh";
const char* server = "api.thingspeak.com";

WiFiClient client;
void thingspeak_send();

/***********************end************************************/
void setup() 
{
       Serial.begin(115200);
       delay(10);
       Serial.println("Connecting to ");
       Serial.println(ssid);
       WiFi.begin(ssid, pass);
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
   #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}
 
void loop() 
{

  if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
{
 //  mpu_getValues();
  thingspeak_send();
  
}
     client.stop();
}

void thingspeak_send()
{
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
        String postStr = apiKey;
        postStr +="&field1=";
        postStr += String(ax);
        postStr +="&field2=";
        postStr += String(ay);
        postStr +="&field3=";
        postStr += String(az);
        postStr +="&field4=";
        postStr += String(gx);
        postStr +="&field5=";
        postStr += String(gy);
        postStr +="&field6=";
        postStr += String(gz);
        postStr += "\r\n\r\n\r\n\r\n\r\n\r\n";
        client.print("POST /update HTTP/1.1\n");
        client.print("Host: api.thingspeak.com\n");
        client.print("Connection: close\n");
        client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
        client.print("Content-Type: application/x-www-form-urlencoded\n");
        client.print("Content-Length: ");
        client.print(postStr.length());
        client.print("\n\n");
        client.print(postStr); 
}

void mpu_getValues()
{
      

    // these methods (and a few others) are also available
    //accelgyro.getAcceleration(&ax, &ay, &az);
    //accelgyro.getRotation(&gx, &gy, &gz);
    #ifdef OUTPUT_READABLE_ACCELGYRO
        // display tab-separated accel/gyro x/y/z values
        Serial.print("a/g:\t");
        Serial.print(ax); Serial.print("\t");
        Serial.print(ay); Serial.print("\t");
        Serial.print(az); Serial.print("\t");
        Serial.print(gx); Serial.print("\t");
        Serial.print(gy); Serial.print("\t");
        Serial.println(gz);
    #endif
}
