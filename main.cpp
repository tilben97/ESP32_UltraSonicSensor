#include <Arduino.h>

#define TRIG 12
#define ECHO 14

long duration = 0;
uint8_t distance = 0;
void ultra_callback()
{
  digitalWrite(LED_BUILTIN, LOW);
}
void ultra_callback1()
{
  digitalWrite(LED_BUILTIN, HIGH);
}
void setup() 
{
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  digitalWrite(TRIG, LOW);
  delayMicroseconds(10);
}

void loop() 
{
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance < 10 && distance != 0)
  {
    ultra_callback1();
  }
  else if(distance > 10)
  {
    ultra_callback();
  }
}