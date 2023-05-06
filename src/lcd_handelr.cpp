#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

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

void printLCD(const char *line1, const char *line2, const unsigned short delayTime = 0)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(line1);
    lcd.setCursor(0, 1);
    lcd.print(line2);

    if (delayTime != 0)
        delay(delayTime);
}