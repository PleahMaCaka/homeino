#ifndef DHT_HANDLER_H
#define DHT_HANDLER_H

#define DHT_PIN 2
#define DHT_TYPE DHT11

extern unsigned char humid; // humidity
extern float temp;          // temperature

extern unsigned int UPSTACK;

void initDHT();
void tickDHT();
void printDHTInfoWithTick(unsigned short delayTime = 1000);

#endif