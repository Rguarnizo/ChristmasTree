#include <Strip.h>
#include <Arduino.h>

 Strip strip = Strip(8,2);

void setup(){   

}


void loop(){
  for(int i = 0; i < 8; i++){
    if(millis()-strip.getPreviousMillis() >= strip.getTime()){
      strip.setPreviousMillis(millis());
      strip.strip.setPixelColor(i,strip.strip.Color(0,155,0));
      strip.strip.show();
      
    }    
  }
  
  }

