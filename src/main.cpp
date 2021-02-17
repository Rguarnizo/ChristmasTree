#include <Strip.h>
#include <Arduino.h>

 Strip strip = Strip(8,2);
 int i = 0;

void setup(){   
  Serial.begin(9600);
}


void loop(){

  

  if((unsigned long) (millis()-strip.getPreviousMillis()) >= strip.getTime()){
    strip.setPreviousMillis(millis());    
    Serial.println(strip.getPreviousMillis());
    strip.strip.setPixelColor(i,strip.strip.Color(0,50,0));
    strip.strip.show();
    i++;
    if(i == 7){
      strip.strip.clear();
      i = 0;
    }
  }   
}
  

