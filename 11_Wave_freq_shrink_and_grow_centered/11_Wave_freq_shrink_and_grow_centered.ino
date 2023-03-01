#include<FastLED.h>

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 255

CRGB leds[LED_AMOUNT];

float move = 0;
float freq = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

void loop() {

  float shrinkage = sin(freq);
  shrinkage = (shrinkage + 1) / 2;

  int midpoint = LED_AMOUNT / 2;

  for(int i=0; i< midpoint; ++i){
    float saturation = cos(i * shrinkage);
    // float saturation = sin(move - i * shrinkage);
    saturation = (saturation + 1) / 2;
    saturation *= 255;
    saturation = max(saturation, 30);

    leds[midpoint+i] = CHSV(170, saturation, 255);
    leds[midpoint-i] = CHSV(170, saturation, 255);
  }

  FastLED.show();

  move += 0.2;
  freq += 0.003;
}
