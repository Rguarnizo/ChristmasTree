#include <Adafruit_NeoPixel.h>


#ifndef Pattern_h
#define Pattern_h
enum class Pattern {
    GoBackOneColor,
    GoBackColors,
    MaintainIncrese,
    MaintainDecrese,
    OddPairsNotSimultaneous,

};
#endif


#ifndef Strip_h
#define Strip_h

#include <Arduino.h>

class Strip
{
protected:

    uint8_t _nLeds;
    uint8_t _pin;
    uint8_t led;
    bool reverse;

    uint32_t primaryColor;
    uint32_t secondaryColor;

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
    

    void changeMode(Pattern pattern);

    void  maintainIncrese();
    void  maintainDecrese();
    void oddPairsNotSimultaneous();
    void switchColors();
    void switchOneColor();
    void goAndBackOneColor();   
    void goAndBackColors();   




    void changePrimaryColor(uint8_t r,uint8_t g,uint8_t b);
    void changeSecondaryColor(uint8_t r,uint8_t g,uint8_t b);
    
    
    void showSequence();
    ~Strip();
    
};
    
#endif