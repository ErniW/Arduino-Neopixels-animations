#include<FastLED.h>

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 255

CRGB leds[LED_AMOUNT];

float animation = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

void loop() {

  for(int i=0; i<LED_AMOUNT; ++i){
    
    float saturation = sin(animation + i * 0.04);
    saturation = (saturation + 1) / 2;
    saturation *= 255;
    saturation = max(saturation, 30);

    leds[i] = CHSV(0, saturation, 255);
  }

  FastLED.show();

  animation += 0.2;
}
