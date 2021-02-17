#include <Adafruit_NeoPixel.h>


#ifndef Strip_h
#define Strip_h

class Strip
{
private:

    uint8_t _nLeds;
    uint8_t _pin;
    unsigned long time = 200;
    unsigned long previusMillis;

    
public:

    Adafruit_NeoPixel strip;



    Strip(uint8_t nLeds,uint8_t pin);
    Strip();
    unsigned long getPreviousMillis();
    void setPreviousMillis(unsigned long n);
    unsigned long getTime();
    void setTime(unsigned long n);
    ~Strip();
};
#endif