#include <Strip.h>
#include <Arduino.h>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

#define NUMSTRIPS 2
#define NUMSTRIPSLEDS 25
unsigned long timeClock = 0;

Strip* strips[NUMSTRIPS];

void setup(){   

   SerialBT.begin("ESP32test");
  
    strips[0] = new Strip(NUMSTRIPSLEDS,2,100);
    strips[1] = new Strip(NUMSTRIPSLEDS,26,100);

    strips[0]->changeMode(Pattern::Rainbow);
    strips[0]->changePrimaryColor(50,0,0);

    strips[1]->changeMode(Pattern::GoBackColors);
    strips[1]->changePrimaryColor(50,0,0);
  
  
  Serial.begin(9600);
  
}


void loop(){

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  
    
    for(int i = 0; i < NUMSTRIPS;i++){      
      
      
      strips[i]->showSequence();
      
    }
}
  

