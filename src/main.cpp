#include <Arduino.h>
#include <LiquidCrystal.h>
#include <dht.h>

#define DHT_PIN 2
#define DHT_TYPE DHT11

DHT dht = DHT(DHT_PIN, DHT11);

void setup()
{
    Serial.begin(9600);

    Serial.println("Booting up...");
    dht.begin();
}

void loop()
{
    
}