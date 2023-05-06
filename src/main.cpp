#include <Arduino.h>
#include <dht_handler.h>

void setup()
{
    Serial.begin(9600);

    Serial.println("Booting up...");
    initDHT();
}

void loop()
{
    printDHTInfoWithTick(1000);
}