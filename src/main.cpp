#include <Arduino.h>
#include <dht_handler.h>
#include <lcd_handler.h>

void setup()
{
    Serial.begin(9600);

    Serial.println("Booting up...");

    initDHT();
    initLCD();

    printLCD("Booting up...", "Please wait...");
}

void loop()
{
    printDHTInfoWithTick(1000);
    printLCD(
        String("Humi: " + String(humid) + "%").c_str(),
        String("Temp: " + String(temp, 1) + "'C").c_str(),
        1000
    );
}