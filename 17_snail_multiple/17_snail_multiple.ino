#include<FastLED.h>

/*

  TODO:
  fix parameters because last two led remain dark.

*/

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 255

#define FRAGMENT_AMOUNT    4
#define FRAGMENT_SIZE      (LED_AMOUNT / FRAGMENT_AMOUNT)
#define SNAIL_MINIMUM_SIZE 6

bool isShrinking = false;

float snailBegin = 0;
float snailEnd = 0;

CRGB leds[LED_AMOUNT];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

void loop() {

  int snailSize = 0;

  if(snailEnd >= snailBegin) snailSize = (int)snailEnd - (int)snailBegin;
  else snailSize = FRAGMENT_SIZE - (int)snailBegin + (int)snailEnd;

  int spread = snailSize;
  float step = TWO_PI / (float)spread;

 FastLED.clear();

  for(int i=0; i < spread; ++i){

    float brightness = cos(PI + (i * step));
    brightness = (brightness + 1) / 2;
    brightness *= 255;

    for(int j=0; j < FRAGMENT_AMOUNT; ++j){
      int index = ((int)snailBegin + i) % FRAGMENT_SIZE;
      index += j * FRAGMENT_SIZE;
      leds[index] = CHSV(0, 0, brightness);
    }
  }

  FastLED.show();

  if(!isShrinking){
    snailEnd += 0.1;
    if(snailSize >= FRAGMENT_SIZE-1) isShrinking = true;
    if(snailEnd > FRAGMENT_SIZE) snailEnd = 0;
  }
  else{
    snailBegin += 0.1;
    if(snailBegin >= FRAGMENT_SIZE) snailBegin = 0;
    if(snailSize < SNAIL_MINIMUM_SIZE) isShrinking = false;   
  }
}
