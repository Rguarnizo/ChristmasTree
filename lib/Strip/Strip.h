#include <Adafruit_NeoPixel.h>


#ifndef Strip_h
#define Strip_h

class Strip
{
protected:

    uint8_t _nLeds;
    uint8_t _pin;

    

    unsigned long time = 200;
    

    
    void (Strip::*f)() = NULL;

    void print();
    
public:

    Adafruit_NeoPixel strip;



    Strip(uint8_t nLeds,uint8_t pin);
    Strip(void);

    
     
    unsigned long getPreviousMillis();
    void setPreviousMillis(unsigned long n);
    
    unsigned long getTime();
    void setTime(unsigned long n);
    
    void showSequence();
    ~Strip();
    
};
    
#endif