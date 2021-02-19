#include <Strip.h>




Strip::Strip(uint8_t nLeds,uint8_t pin,unsigned long time):strip(nLeds,pin,NEO_GRB + NEO_KHZ800)
{
    _nLeds =nLeds;
    _pin = pin;
    strip.begin();
    led = 0;
    color = strip.Color(0,255,0);    
    this->time = time;
    f = &Strip::print;

}

Strip::Strip()
{

}

Strip::~Strip()
{
}

unsigned long Strip::getTime(){
    return time;
}

void Strip::setTime(unsigned long n){
    time = n;
}

void Strip::showSequence(){

    if(millis() - previusMillis >= time){        
        previusMillis = millis();
        Serial.print("Print in time: " );
        Serial.println(previusMillis);
        print();
    }
    
}

void Strip::print(){
    
    this->strip.setPixelColor(led,color);
    this->strip.show();
    
    led++;

    if(led == this->_nLeds){
        strip.clear();
        led = 0;
    }
}
