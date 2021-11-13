#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial mySerial(12, 11);

#define echoPin 5
#define trigPin 6 

void setup () {
Serial.begin (9600);
mySerial.begin (9600);
mp3_set_serial (mySerial);
delay(10);

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

mp3_set_volume (25);
delay(50);


}

float ultrasonic()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);

  float distance = duration * 0.034 / 2; 
  return distance;
}
bool kondisi = false;
void loop () {

  float jarak = ultrasonic();

  if(jarak <10 && kondisi == false)
  {
    kondisi = true;
    mp3_play (2);
    delay(1000);
  }
  else if(jarak >= 10)
  {
    kondisi = false;
  }


  
  Serial.println(jarak);
  delay(100);

}
