#include <Arduino.h>
#include <LiquidCrystal.h>
#include <dht.h>

#define DHT_PIN 2
#define DHT_TYPE DHT11

DHT dht = DHT(DHT_PIN, DHT11);

unsigned char humid = 0; // humidity
float temp = 0;          // temperature

unsigned int UPSTACK = 0;

void setup()
{
    Serial.begin(9600);

    Serial.println("Booting up...");
    dht.begin();
}

void loop()
{
    UPSTACK += 1;

    humid = dht.readHumidity();
    temp = dht.readTemperature();

    Serial.print("Humidity: " + String(humid) + "%\t");
    Serial.print("Temperature: " + String(temp, 1) + "°C");
    Serial.println("\t[ " + String(UPSTACK) + " ]");

    delay(10000);
}