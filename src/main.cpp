#include <Strip.h>
#include <Arduino.h>


#define NUMSTRIPS 2
#define NUMSTRIPSLEDS 8
unsigned long timeClock = 0;

Strip* strips[NUMSTRIPS];

void setup(){   

  for(int i = 0; i < NUMSTRIPS; i++){
    strips[i] = new Strip(NUMSTRIPSLEDS,i+2,200);
  }

  strips[0]->changeMode(4);
  strips[0]->changePrimaryColor(50,0,0);
  strips[0]->changeSecondaryColor(0,50,0);
  strips[1]->changeMode(4);
  strips[1]->changePrimaryColor(0,0,50);
  strips[1]->changeSecondaryColor(50,0,0);
  Serial.begin(9600);
  
}


void loop(){

    
    for(int i = 0; i < NUMSTRIPS;i++){      
      Strip* strip = strips[i];
      
      strip->showSequence();
      
    }
}
  

