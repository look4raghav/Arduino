#include <SoftwareSerial.h>
#include <TinyGPS++.h>
float lattitude,longitude; // create variable for latitude and longitude object 
SoftwareSerial gpsSerial(8,9);//tx,rx
SoftwareSerial gsmm(2,3);//tx,rx
TinyGPSPlus gps;// create gps object
void setup()
{
  Serial.begin(9600); 
  gpsSerial.begin(9600);
  gpsSerial.listen();
  textgps();
  gsmm.begin(9600);
  gsmm.print("\r");
  delay(1000);                  
  gsmm.print("AT+CMGF=1\r");    
  delay(1000);
  gsmm.print("AT+CMGS=\"+917357151892\"\r");    
  delay(1000); 
  gsmm.print("https://www.google.com/maps/place/");
  gsmm.print(lattitude, 6);
  gsmm.print(",");
  gsmm.print(longitude, 6);
  delay(1000);
  gsmm.write(0x1A);
  delay(1000); 
}
void loop()
{ 
  
}

void textgps()
{
  while(1)  
  {
    while (gpsSerial.available() > 0)
    { 
      gps.encode(gpsSerial.read()); 
    }

    if (gps.location.isUpdated())
    {
      Serial.print("LAT=");  Serial.println(gps.location.lat(), 6);
      Serial.print("LONG="); Serial.println(gps.location.lng(), 6);
      lattitude=gps.location.lat();
      longitude=gps.location.lng();
      break;
     }  
  }
Serial.print("LATTITUDE="); Serial.println(lattitude,6);
Serial.print("LONGITUDE="); Serial.println(longitude,6);
delay(1000);
}
