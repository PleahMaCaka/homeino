#include <Arduino.h>
#include <dht_handler.h>
#include <lcd_handler.h>

#define BEFORE_BUTTON_PIN 5
#define AFTER_BUTTON_PIN 6

bool beforeButton = false;
bool afterButton = false;

void setup()
{
    Serial.begin(9600);

    Serial.println("Booting up...");

    initDHT();
    initLCD();

    printLCD("Booting up...", "Please wait...", 0);
}

// TODO counter
void loop()
{
    tickDHT();
    delay(2000);

    // button handling
    if (digitalRead(BEFORE_BUTTON_PIN) != 0x1) beforeButton = false;
    else beforeButton = true;

    if (digitalRead(AFTER_BUTTON_PIN) != 0x1) afterButton = false;
    else afterButton = true;


    if (beforeButton) page--;
    if (afterButton) page++;
    
    updatePage();

    delay(50);
}