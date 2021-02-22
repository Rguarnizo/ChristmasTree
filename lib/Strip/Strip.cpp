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
        (*this.*f)();
    }
    
}

void Strip::maintainIncrese(){
    
    this->strip.setPixelColor(led,color);
    this->strip.show();
    
    led++;

    if(led == this->_nLeds){
        strip.clear();
        led = 0;
    }
}


void Strip::maintainDecrese(){
    

    if(led == 0){
        strip.clear();
        led = 8;
    }

    this->strip.setPixelColor(led,color);
    this->strip.show();
    
    led--;

    
}

void Strip::print(){
    Serial.println("Is working !!!");
}

void Strip::oddPairsNotSimultaneous(){
    if(led%2 == 0){
        this->strip.setPixelColor(led,color);
        this->strip.show();
        
    } else {
        this->strip.setPixelColor(led,color);
        this->strip.show();
    }

    led+=2;

    if(led == _nLeds){
        led= 1;
        this->strip.clear();
    }else if(led == _nLeds+1){
        led = 0;
        this->strip.clear();
    }
}


void Strip::changeMode(int mode){
    switch(mode){
        case 1:
            f = &Strip::maintainIncrese;
            break;
        case 2:
            f = &Strip::maintainDecrese;
            break; 
        case 3:
            f = &Strip::oddPairsNotSimultaneous;
            break;
        case 4: 
            f = &Strip::print;
            break;
        default: 
            f = &Strip::print;
            break;
        
    }
}

void Strip::changeColor(uint8_t r,uint8_t g,uint8_t b){
    this->color = strip.Color(r,g,b);
}
