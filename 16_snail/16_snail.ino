#include<FastLED.h>

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
  else snailSize = LED_AMOUNT - (int)snailBegin + (int)snailEnd;

  int spread = snailSize;
  float step = TWO_PI / (float)spread;

 FastLED.clear();

  for(int i=0; i< spread; ++i){

    float brightness = cos(PI + (i * step));
    brightness = (brightness + 1) / 2;
    brightness *= 255;

    int index = ((int)snailBegin + i) % LED_AMOUNT;
    leds[index] = CHSV(0, 0, brightness);
  }

  FastLED.show();

  if(!isShrinking){
    snailEnd += 0.08;
    if(snailEnd >= LED_AMOUNT) snailEnd = 0;
    if(snailSize > FRAGMENT_SIZE) isShrinking = true;
  }
  else{
    snailBegin += 0.08;
    if(snailBegin >= LED_AMOUNT) snailBegin = 0;
    if(snailSize < SNAIL_MINIMUM_SIZE) isShrinking = false;   
  }
}
