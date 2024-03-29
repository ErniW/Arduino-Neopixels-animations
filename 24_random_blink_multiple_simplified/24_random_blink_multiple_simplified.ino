#include <FastLED.h>

#define LED_AMOUNT 74
#define DATA_PIN 6
#define GLOBAL_BRIGHTNESS 255

#define BLINK_AMOUNT 5

CRGB leds[LED_AMOUNT];

struct Blink{
  Blink(int size, int pos,  float value){
    this->size = size;
    this->position = pos;
    this->value = value;
  }
  int position;
  int size;
  long count = 0;
  float value;
};

Blink* blinks[BLINK_AMOUNT];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT);
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);

  for(int i=0; i<BLINK_AMOUNT; i++){

    int size = 5;
    int position = random(0, LED_AMOUNT - size);
    int value = random(0, 628) / 100; //To get random between 0 and TWO_PI. Arduino random function returns integers.

    blinks[i] = new Blink(size, position, value);
  }

}

void loop() {

  FastLED.clear();

  for(int i=0; i<BLINK_AMOUNT; i++){

    if(!blinks[i]->count){
      blinkAnimation(blinks[i]);
    }
    else {
      blinks[i]->count--;
      continue;
    }

    blinks[i]->value += 0.05;

    if(blinks[i]->value >= TWO_PI){
      blinks[i]->position = random(0, LED_AMOUNT - blinks[i]->size);
      blinks[i]->value = 0;
      blinks[i]->count = random(500);
    }
    
  }

  FastLED.show();
}


void blinkAnimation(Blink *b){

  float sinStep = TWO_PI / (b->size - 1);

  float fade = cos(PI + b->value);
  fade = (fade + 1) / 2;

  for(int led=0; led < b->size; led++){
    float brightness = cos(PI + (led * sinStep));
    brightness = (brightness + 1) /2;
    brightness *= 255;
    
    brightness = max(30, brightness);
    brightness *= fade;
    
    if(leds[led + b->position].b < brightness){
      leds[led + b->position] = CHSV(0, 0, brightness);
    }

  }

}
