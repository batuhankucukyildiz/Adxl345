#include <Wire.h>
#include <Adafruit_Sensor.h> 
#include <Adafruit_ADXL345_U.h>
#define BUZZER 26 

float x = 0; 
float y = 0;
float z = 0;

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();
void buzzerFunc(void);

void setup(void) 
{
   pinMode(BUZZER,OUTPUT);
   Serial.begin(9600);  
   if(!accel.begin())
   {
      Serial.println("");
      while(1);
   }
   sensors_event_t event; 
   accel.getEvent(&event);
   x = event.acceleration.x; 
   y = event.acceleration.y; 
   z = event.acceleration.z;
   
}
void loop(void) 
{

   sensors_event_t event; 
   accel.getEvent(&event);
   Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
   Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
   Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");
   Serial.println("m/s^2 ");
   if ( event.acceleration.x >= (x+0.60) || event.acceleration.x <= (x-0.60) || event.acceleration.y >= (y+0.60) || event.acceleration.y <= (y-0.60) || event.acceleration.z >= (z+0.60) || event.acceleration.z <= (z-0.60)) {
         buzzerFunc();
   }
}



void buzzerFunc(void){

  digitalWrite(BUZZER,HIGH);
  delay(200);
  digitalWrite(BUZZER,LOW);
  delay(200);
  digitalWrite(BUZZER,HIGH);
  delay(200);
  digitalWrite(BUZZER,LOW);
  delay(200);
  digitalWrite(BUZZER,HIGH);
  delay(400);
  digitalWrite(BUZZER,LOW);
  
}
