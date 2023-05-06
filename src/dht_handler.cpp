#include <Arduino.h>
#include <DHT.h>
#include <dht_handler.h>

DHT dht = DHT(DHT_PIN, DHT_TYPE);

unsigned char humid;
float temp;
unsigned int UPSTACK = 0;


void initDHT()
{
    dht.begin();
    Serial.println("DHT initialized");
}

void tickDHT()
{
    humid = dht.readHumidity();
    temp = dht.readTemperature();
    UPSTACK += 1;
}

void printDHTInfoWithTick(unsigned short delayTime)
{
    tickDHT();

    Serial.print("Humidity: " + String(humid) + "%\t");
    Serial.print("Temperature: " + String(temp, 1) + "°C");
    Serial.println("\t[ " + String(UPSTACK) + " ]");

    if (delayTime != 0)
        delay(delayTime);
}
