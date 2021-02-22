#include <Strip.h>
#include <Arduino.h>


#define NUMSTRIPS 2
#define NUMSTRIPSLEDS 8
unsigned long timeClock = 0;

Strip* strips[NUMSTRIPS];

void setup(){   

  for(int i = 0; i < NUMSTRIPS; i++){
    strips[i] = new Strip(NUMSTRIPSLEDS,i+2,200+(i*300));
  }

  strips[0]->changeMode(1);
  strips[0]->changeColor(50,0,0);
  strips[1]->changeMode(3);
  strips[1]->changeColor(0,0,50);
  Serial.begin(9600);
  
}


void loop(){

    
    for(int i = 0; i < NUMSTRIPS;i++){      
      Strip* strip = strips[i];
      
      strip->showSequence();
      
    }
}
  

