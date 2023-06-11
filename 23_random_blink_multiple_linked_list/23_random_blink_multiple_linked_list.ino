#include <FastLED.h>
#include "Blink.h"

#define LED_AMOUNT 74
#define DATA_PIN 6
#define GLOBAL_BRIGHTNESS 255

#define MAX_BLINK_AMOUNT 5

CRGB leds[LED_AMOUNT];

LinkedList* pulses = new LinkedList();

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT);
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

unsigned long prevTime = 0;

int nextBlinkWaitTime = 0;

void loop() {
  unsigned long time = millis();

  FastLED.clear();

  for(Blink* b = pulses->getHead(); b != nullptr; b = b->next){

    blinkAnimation(b);
    b->animation += b->speed;

    if(b->animation >= TWO_PI){
      pulses->remove(b);
    }
  }

  if(time - prevTime >= nextBlinkWaitTime){

    if(!pulses->isFull()){

      int size = random(3, 6);
      int position = random(0, LED_AMOUNT-size);
      //float speed = (float)random(1, 100) / 1000;
      float speed = 0.1;

      Blink* b = new Blink(position, size, speed);
      pulses->insert(b);

    }

    nextBlinkWaitTime = random(100); 
    prevTime = time;
  }

  FastLED.show();
}


void blinkAnimation(Blink *b){

  float sinStep = TWO_PI / (b->size - 1);

  float fade = cos(PI + b->animation);
  fade = (fade + 1) / 2;

  for(int led=0; led < b->size; led++){
    float brightness = cos(PI + (led * sinStep));
    brightness = (brightness + 1) /2;
    brightness *= 255;
    
    brightness = max(30, brightness);
    //fade = max(0.05,fade);

    brightness *= fade;
    
    if(leds[led + b->position].b < brightness){
      leds[led + b->position] = CHSV(0, 0, brightness);
    }

  }

}
