#include <ESP8266WiFi.h>


int smoke_sensor_pin = A0;
int Buzzer = D1;

void setup()

{

  Serial.begin(9600);
  pinMode(smoke_sensor_pin, INPUT);
  pinMode(Buzzer,OUTPUT);

}

void loop()

{

  int analogSensor = analogRead(smoke_sensor_pin);
  Serial.println(analogSensor);

  if (analogSensor > 500)

  {

    Serial.println("Smoke detected in the room.");
    digitalWrite(Buzzer, HIGH);


  }

  else

  {
    Serial.println("There is no Smoke in the room.");
    digitalWrite(Buzzer, LOW);


  }
}
