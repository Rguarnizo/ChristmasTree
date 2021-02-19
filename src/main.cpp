#include <Strip.h>
#include <Arduino.h>


#define NUMSTRIPS 2
#define NUMSTRIPSLEDS 8
unsigned long timeClock = 0;

Strip* strips[NUMSTRIPS];

void setup(){   

  for(int i = 0; i < NUMSTRIPS; i++){
    strips[i] = new Strip(NUMSTRIPSLEDS,i+2,400);
  }

  strips[0]->changeMode(1);
  strips[1]->changeMode(3);
  Serial.begin(9600);
}


void loop(){

    
    for(int i = 0; i < NUMSTRIPS;i++){      
      Strip* strip = strips[i];
      
      strip->showSequence();
      
    }
}
  

