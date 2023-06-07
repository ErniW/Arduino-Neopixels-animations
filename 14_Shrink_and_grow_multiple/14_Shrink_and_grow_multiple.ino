#include<FastLED.h>

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 255

#define FRAGMENT_AMOUNT   4
#define FRAGMENT_SIZE     (LED_AMOUNT / FRAGMENT_AMOUNT)
#define FRAGMENT_MIDPOINT (FRAGMENT_SIZE / 2)

CRGB leds[LED_AMOUNT];

float move = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

void loop() {

  float spread = FRAGMENT_MIDPOINT * ((sin(move) + 1) / 2);
  float step = PI / spread;

  FastLED.clear();

  for(int fragment = 0; fragment < FRAGMENT_AMOUNT; fragment++){
    int pos = (fragment * FRAGMENT_SIZE);
    int midpoint = pos + FRAGMENT_MIDPOINT;

    for(int i=0; i<= spread; ++i){
      float brightness = cos(i * step);
      brightness = (brightness + 1) / 2;
      brightness *= 255;
      
      leds[midpoint+i] = CHSV(0, 0, brightness);
      leds[midpoint-i] = CHSV(0, 0, brightness);
    }

  }

  FastLED.show();

  move += 0.05;

  if(move >= TWO_PI) move = 0;
}
