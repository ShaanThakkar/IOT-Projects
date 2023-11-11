#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "template_id"
#define BLYNK_DEVICE_NAME "Moisture Sensor"
#define BLYNK_AUTH_TOKEN "Auth Token"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int sensorpin=A0;
int sensorvalue=0;
int outputvalue=0;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Auth Token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "username";
char pass[] = "password";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  sensorvalue=analogRead(sensorpin);
  outputvalue=map(sensorvalue,0,1023,50,0); //100,0 
  delay(1000);

  if(outputvalue>20)
  {
       Serial.println("Stop watering your plant");
       Serial.print(outputvalue);
       Blynk.notify("Stop watering your plant");
       delay(1000); 
  }
  else if(outputvalue<20)
  {
       Serial.println("soil is not wet enough to water");
       Serial.print(outputvalue);
       Blynk.notify("soil is wet not enough to water");
       delay(1000);
  }
  
  Blynk.virtualWrite(V1,outputvalue);
  Blynk.run();
}
