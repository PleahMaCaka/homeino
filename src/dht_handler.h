#define DHT_PIN 2
#define DHT_TYPE DHT11


void initDHT();

void tickDHT();

void printDHTInfoWithTick(unsigned short delayTime = 1000);