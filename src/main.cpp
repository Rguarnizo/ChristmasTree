#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel listPixels[2];


void setup(){

    for(int i = 0; i < 2;i++){
      listPixels[i] = Adafruit_NeoPixel(8,i+2,NEO_GRB + NEO_KHZ800);
      listPixels[i].begin();
    }
}


void loop(){
  

  for(int i = 0;i < 2;i++){
    for(int j =0; j < 8;j++){
      listPixels[i].setPixelColor(j,listPixels[i].Color(0,150,0));
      listPixels[i].show();
      delay(200);
    }
    listPixels[i].clear();
  }
}