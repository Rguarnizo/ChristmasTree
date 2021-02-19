#include <Strip.h>
#include <Arduino.h>


#define NUMSTRIPS 4
#define NUMSTRIPSLEDS 8

#define CLKAPP 100

unsigned long timeClock = 0;

Strip strips[NUMSTRIPS];

void setup(){   

  for(int i = 0; i < NUMSTRIPS; i++){
    strips[i] = Strip(NUMSTRIPSLEDS,i+2,200);
  }

  Serial.begin(9600);
}


void loop(){

  if((unsigned long) millis() - timeClock >= CLKAPP){
    timeClock = millis();
    
    Serial.println(timeClock);
    for(int i = 0; i < NUMSTRIPS;i++){      
      Strip* strip = &strips[i];
      
      strip->showSequence();
    }
  } 
}
  

