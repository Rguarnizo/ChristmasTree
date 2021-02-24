#include <Strip.h>




Strip::Strip(uint8_t nLeds,uint8_t pin,unsigned long time):strip(nLeds,pin,NEO_GRB + NEO_KHZ800)
{
    _nLeds =nLeds;
    _pin = pin;
    strip.begin();
    led = 0;
    primaryColor = strip.Color(0,255,0);    
    secondaryColor = strip.Color(255,0,0);    
    this->time = time;
    f = &Strip::print;
    reverse = false;

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
    
    this->strip.setPixelColor(led,primaryColor);
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

    this->strip.setPixelColor(led,primaryColor);
    this->strip.show();
    
    led--;

    
}

void Strip::print(){
    Serial.println("Is working !!!");
}

void Strip::oddPairsNotSimultaneous(){
    if(led%2 == 0){
        this->strip.setPixelColor(led,primaryColor);
        this->strip.show();
        
    } else {
        this->strip.setPixelColor(led,primaryColor);
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

void Strip::switchOneColor(){

    
    strip.clear();

    for(int i = 0; i < _nLeds;i++){
        if(i%2 == 0 && !reverse){
            strip.setPixelColor(i,primaryColor);
        }
        if(i%2 == 1 && reverse){
            strip.setPixelColor(i,primaryColor);
        }
    }
    reverse = !reverse;
    strip.show();
}

void Strip::switchColors(){

    static bool reverse = true;

    for(int i = 0; i < _nLeds;i++){
        if(i%2 == 0){
            if(reverse){
                strip.setPixelColor(i,primaryColor);
            }else{
                strip.setPixelColor(i,secondaryColor);
            }
        }
        if(i%2 == 1){
            if(reverse){
                strip.setPixelColor(i,secondaryColor);
            }else{
                strip.setPixelColor(i,primaryColor);
            }
        }
    }
    reverse = !reverse;
    strip.show();
}

void Strip::goAndBackColors(){
    static bool reverse = false;
    
    if(led <= _nLeds && !reverse){
        strip.setPixelColor(led,primaryColor);
        strip.show();
        led++;
        if(led == _nLeds){ 
            strip.clear();
            reverse = !reverse;
         }
    }else if(reverse){
        strip.setPixelColor(led,secondaryColor);
        strip.show();
        led--;
        if(led == 0){
            strip.clear();
            reverse = !reverse;
            
        } 
    }
}

void Strip::goAndBackOneColor(){
    
    static bool reverse = false;
    
    if(led <= _nLeds && !reverse){
        strip.setPixelColor(led,primaryColor);
        strip.show();
        led++;
        if(led == _nLeds){ 
            strip.clear();
            reverse = !reverse;
         }
    }else if(reverse){
        strip.setPixelColor(led,primaryColor);
        strip.show();
        led--;
        if(led == 0){
            strip.clear();
            reverse = !reverse;
            
        } 
    }
}

void Strip::rainbow(){

    static int j = 0;

    for(int i = 0; i < _nLeds;i++){
        strip.setPixelColor(i,Wheel((i+j) & 255));
    }

    strip.show();
    j++;
    if(j >= 255){
        j = 0;
    }
}

uint32_t Strip::Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


void Strip::changeMode(Pattern pattern){
    switch(pattern){
        case Pattern::GoBackOneColor: f = &Strip::goAndBackOneColor;
            break; 
        case Pattern::GoBackColors: f = &Strip::goAndBackColors;
            break;
        case Pattern::MaintainIncrese: f = &Strip::maintainIncrese;
            break;
        case Pattern::MaintainDecrese: f = &Strip::maintainDecrese;
            break;
        case Pattern::OddPairsNotSimultaneous: f = &Strip::oddPairsNotSimultaneous;
            break;
        case Pattern::Rainbow: f = &Strip::rainbow;
            break;
        default: f = &Strip::oddPairsNotSimultaneous;
    }
}

void Strip::changePrimaryColor(uint8_t r,uint8_t g,uint8_t b){
    this->primaryColor = strip.Color(r,g,b);
}

void Strip::changeSecondaryColor(uint8_t r,uint8_t g,uint8_t b){
    this->secondaryColor = strip.Color(r,g,b);
}
