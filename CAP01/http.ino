//
//
//#include <TinyGPS++.h>
//#include <SoftwareSerial.h>
//#include <ESP8266WiFi.h>
//
//TinyGPSPlus gps;  // The TinyGPS++ object
//
//SoftwareSerial ss(4, 5); // The serial connection to the GPS device
//
//const char* ssid     = "nissan";
//const char* password = "password";
//const char* host = "iotprojectnis.000webhostapp.com";
//
//float latitude , longitude;
//int year , month , date, hour , minute , second;
//String date_str , time_str , lat_str , lng_str;
//int pm;
//
//void setup()
//{
//  Serial.begin(115200);
//  ss.begin(2400);
//  Serial.println();
//  Serial.print("Connecting to ");
//  Serial.println(ssid);
//
//  WiFi.begin(ssid, password);
//
//  while (WiFi.status() != WL_CONNECTED)
//  {
//    delay(500);
//    Serial.print(".");
//  }
//  Serial.println("");
//  Serial.println("WiFi connected");
//
//  Serial.println("Server started");
//
//  // Print the IP address
//  Serial.println(WiFi.localIP());
//
//}
//
//void loop()
//{
//
//  WiFiClient client;
//  const int httpPort = 80;
//  if (!client.connect(host, httpPort)) {
//    Serial.println("connection failed");
//    return;
//  }
//  while (ss.available() > 0)
//    if (gps.encode(ss.read()))
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
//    Serial.print(lat_str);
//    Serial.print(",");
//    Serial.println(lng_str);
//  // Check if a client has connected
//
//  // Prepare the response
//  String s = "/api/fridge/insert.php?temp=";
//  s += lat_str;
//  s += "&hum=";
//  s += lng_str;
//
//  s += String("GET ") + s + " HTTP/1.1\r\n" +
//               "Host: " + host + "\r\n" + 
//               "Connection: close\r\n\r\n" ;
//
//  client.print(s);
// Serial.println(s);
//  delay(500);
//
//}

