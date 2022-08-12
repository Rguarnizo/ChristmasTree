#include <Strip.h>
#include <Arduino.h>
#include <BluetoothSerial.h>
#include <ArduinoJson.h>


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

//Probables Fallas:
// ESP Nuevo Dañado
// Codigo Diferente entre ESP32
// Diferente versión de ESP32 (En el dorso dice ESP32S)
// Carga alta cuando se conectan todas las tiras.

BluetoothSerial SerialBT;

#define NUMSTRIPS 12
#define NUMLEDSSTRIPS 25 
unsigned long timeClock = 0;
bool matrix[NUMSTRIPS][NUMLEDSSTRIPS];

Strip* strips[NUMSTRIPS];


void setup(){   

   SerialBT.begin("Christmass Tree App");
  
    strips[0] = new Strip(NUMLEDSSTRIPS,2,100);
    strips[1] = new Strip(NUMLEDSSTRIPS,26,100);

    strips[0]->changeMode(Pattern::MaintainIncrese);
    strips[0]->changePrimaryColor(50,0,0);

    strips[1]->changeMode(Pattern::GoBackColors);
    strips[1]->changePrimaryColor(50,0,0);
  
  
  Serial.begin(9600);
  
}

void loop(){

  if (SerialBT.available()) {
    StaticJsonDocument<192> doc;

    DeserializationError error = deserializeJson(doc,SerialBT);

    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }

    JsonObject Colors = doc["Colors"];
    int r = Colors["Red"]; 
    int g = Colors["Green"]; 
    int b = Colors["Blue"]; 

    int Strip = doc["Strip"]; 
    int Pattern = doc["Pattern"]; 

    char data[192];

      
    snprintf(data, sizeof(data), "Colors:\n \tRed: %d\n \tGreen: %d\n \tBlue: %d\n Strip: %d\n Pattern:%d",r,g,b,Strip,Pattern);

    Serial.println(data);
  
    strips[Strip]->changePrimaryColor(r,g,b);

  }
  
    
    for(int i = 0; i < NUMSTRIPS;i++){
      strips[i]->showSequence();
    }

    for(int i = 0; i < sizeof(matrix)/sizeof(*matrix); i++){
    strips[i]->setup(matrix[i]);    
    } 
}


void matrixTransform(){
  for(int i = 0; i < sizeof(matrix)/sizeof(*matrix); i++){
      
  } 
}
  

