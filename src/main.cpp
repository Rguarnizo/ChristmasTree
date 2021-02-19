#include <Strip.h>
#include <Arduino.h>


#define NUMSTRIPS 1
#define NUMSTRIPSLEDS 8

#define CLKAPP 100

unsigned long timeClock = 0;

Strip strips[NUMSTRIPS];

void setup(){   

  for(int i = 0; i < NUMSTRIPS; i++){
    strips[i] = Strip(NUMSTRIPSLEDS,i+2,1000);
  }

  Serial.begin(9600);
}


void loop(){

  
    
    Serial.println(timeClock);
    for(int i = 0; i < NUMSTRIPS;i++){      
      Strip* strip = &strips[i];
      
      strip->showSequence();
    }
  
}
  

