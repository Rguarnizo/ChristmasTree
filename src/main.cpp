#include <Strip.h>
#include <Arduino.h>


#define NUMSTRIPS 2
#define NUMSTRIPSLEDS 25
unsigned long timeClock = 0;

Strip* strips[NUMSTRIPS];

void setup(){   

  
    strips[0] = new Strip(NUMSTRIPSLEDS,2,100);
    strips[1] = new Strip(NUMSTRIPSLEDS,26,100);

    strips[0]->changeMode(Pattern::Rainbow);
    strips[0]->changePrimaryColor(50,0,0);

    strips[1]->changeMode(Pattern::GoBackColors);
    strips[1]->changePrimaryColor(50,0,0);
  
  
  Serial.begin(9600);
  
}


void loop(){

    
    for(int i = 0; i < NUMSTRIPS;i++){      
      
      
      strips[i]->showSequence();
      
    }
}
  

