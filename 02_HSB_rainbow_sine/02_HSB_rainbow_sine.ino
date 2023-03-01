#include<FastLED.h>

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 30

CRGB leds[LED_AMOUNT];

float animation = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

void loop() {

  for(int i=0; i<LED_AMOUNT; ++i){
    float hue = sin(animation + (i+1) * 0.1);
    hue = (hue + 1) / 2;
    hue *= 255;
    leds[i] = CHSV(hue, 255, 255);
  }

  FastLED.show();
  animation += 0.05;
}
