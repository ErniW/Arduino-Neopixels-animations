#include<FastLED.h>

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 127

int fragments = 6;
int fragmentSize = LED_AMOUNT / fragments;

CRGB leds[LED_AMOUNT];

float fade = 0;
float color = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

int fragment = 0;


void loop() {

  // for(int i=fragment * fragmentSize; i<fragmentSize * (fragment+1); ++i){
  //   float brightness = cos(fade + QUARTER_PI * i);
  //   brightness = (brightness + 1) / 2;
  //   brightness *= 255;
  //   leds[i] = CHSV(color, 255, brightness);

  //   if(brightness == 0) color
  // }

  for(int i=fragment * fragmentSize; i<fragmentSize * (fragment+1); ++i){
    float brightness = cos(fade + PI);
    brightness = (brightness + 1) / 2;
    brightness *= 255;
    leds[i] = CHSV(color, 255, brightness);
  }

  if(fade >= TWO_PI) {
    fade = 0;
    color = random(255);
    fragment++;
    fragment = fragment % fragments;
  }

  FastLED.show();

  fade += 0.08;
}
