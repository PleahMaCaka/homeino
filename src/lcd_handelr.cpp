#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <lcd_handler.h>
#include <dht_handler.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned short page;

void initLCD()
{
    lcd.init();
    lcd.clear();
    lcd.backlight();

    Serial.println("LCD initialized");
}

void testLCD()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hello, world!");
    lcd.setCursor(0, 1);
    lcd.print("1602 lcd test");
}

void printLCD(const char *line1, const char *line2, const unsigned short delayTime)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(line1);
    lcd.setCursor(0, 1);
    lcd.print(line2);

    if (delayTime != 0)
        delay(delayTime);
}

void dntPage()
{
    printLCD(
        String("Humi: " + String(humid) + "%").c_str(),
        String("Temp: " + String(temp, 1) + "'C").c_str(),
        1000);
}

void testPage()
{
    printLCD(
        String("Hello, World!").c_str(),
        String("GoodBye, World!").c_str(),
        1000);
}

void notFoundPage()
{
    printLCD(
        String("Not found").c_str(),
        String("Not found").c_str(),
        1000);
}

void upstackPage() {
    // show dnt upstack
    printLCD(
        String("UPSTACK:").c_str(),
        String("[ " + String(UPSTACK) + " ]").c_str(),
        1000);
}

void updatePage()
{
    switch (page)
    {
    case 0:
        dntPage();
        break;
    case 1:
        upstackPage();
        break;
    case 2:
        testPage();
        break;
    default:
        page = 0;
        notFoundPage();
        break;
    }
}