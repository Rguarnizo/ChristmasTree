#include <Strip.h>




Strip::Strip(uint8_t nLeds,uint8_t pin):strip(nLeds,pin,NEO_GRB + NEO_KHZ800)
{
    _nLeds =nLeds;
    _pin = pin;
    strip.begin();
    previusMillis = 0;
    time = 1000;

}

Strip::Strip()
{

}

Strip::~Strip()
{
}

unsigned long Strip::getPreviousMillis(){
    return previusMillis;
}

void Strip::setPreviousMillis(unsigned long n){
    previusMillis = n;
}
unsigned long Strip::getTime(){
    return time;
}

void Strip::setTime(unsigned long n){
    time = n;
}