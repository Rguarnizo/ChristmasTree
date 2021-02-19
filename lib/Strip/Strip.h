#include <Adafruit_NeoPixel.h>


#ifndef Strip_h
#define Strip_h

#include <Arduino.h>



class Strip
{
protected:

    uint8_t _nLeds;
    uint8_t _pin;
    uint8_t led;

    uint32_t color;

    unsigned long time = 200;
    unsigned long previusMillis = 0;
    

    void (Strip::*f)() = NULL;

    void print();
    
public:

    Adafruit_NeoPixel strip;
    String stripName;
    

    Strip(uint8_t nLeds,uint8_t pin,unsigned long time);
    Strip(void);

    
     
    unsigned long getPreviousMillis();
    void setPreviousMillis(unsigned long n);
    
    unsigned long getTime();
    void setTime(unsigned long n);
    

    void changeMode(int mode);

    void  maintainIncrese();
    void  maintainDecrese();
    void oddPairs();
    
    void showSequence();
    ~Strip();
    
};
    
#endif