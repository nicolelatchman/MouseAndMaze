/*
Nicole Latchman
CS100
Spring 2017

Uses lights to simulate movement of a "mouse" through a "maze". Maze is built
using buttons and switches to show the outline of individual walls.
*/

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel ring = Adafruit_NeoPixel(10, 17);

void setup() {
    ring.begin();
    pinMode(4, INPUT);
    pinMode(19, INPUT);
    pinMode(12, INPUT);
}

void loop() {
  
  //check left wall
  if (digitalRead(19)){
    for(int i = 0; i<=5; i++){
      ring.setPixelColor(i, 255, 0, 0); //red
    }
    for(int i = 6; i<=8; i++){
      ring.setPixelColor(i, 0, 255, 0); //green
    }
    ring.setPixelColor(9,255,0,0);
  }
  
  //check right wall
  else if (digitalRead(4) && !digitalRead(19)){
    for(int i = 4; i<=9; i++){
      ring.setPixelColor(i, 255, 0, 0); //red
    }
    for(int i = 1; i<=3; i++){
      ring.setPixelColor(i, 0, 255, 0); //green
    }
    ring.setPixelColor(0, 255, 0, 0); //red
  }
  
  //check front wall
  else if(digitalRead(21)==1 && !digitalRead(19)){
    for(int i = 0; i<=3; i++){
      ring.setPixelColor(i, 255, 0, 0); //red
    }
    ring.setPixelColor(5, 0, 255, 0); //green
    ring.setPixelColor(4, 0, 255, 0); //green
    for(int i = 6; i<=9; i++){
      ring.setPixelColor(i, 255, 0, 0); //red
    }
    
  }
  
  //else turn around
  else{
    ring.setPixelColor(0, 0, 255, 0); //green
    for(int i = 1; i<=8; i++){
      ring.setPixelColor(i, 255, 0, 0); //red
    }
    ring.setPixelColor(9, 0, 255, 0); //green
  }
  
  ring.show();
}
