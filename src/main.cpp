#include <Strip.h>
#include <Arduino.h>

 Strip* strips[1];
 int i = 0;

void setup(){   
  strips[0] = new Strip(8,2);
  Serial.begin(9600);
}


void loop(){

  

  if((unsigned long) (millis()-strips[0]->getPreviousMillis()) >= strips[0]->getTime()){
    strips[0]->setPreviousMillis(millis());    
    Serial.println(strips[0]->getPreviousMillis());
    strips[0]->strip.setPixelColor(i,strips[0]->strip.Color(0,50,0));
    strips[0]->strip.show();
    i++;
    if(i == 7){
      strips[0]->strip.clear();
      i = 0;
    }
  }   
}
  

