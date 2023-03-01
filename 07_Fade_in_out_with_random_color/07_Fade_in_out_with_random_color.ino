#include<FastLED.h>

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 127

CRGB leds[LED_AMOUNT];

float fade = 0;
float color = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

void loop() {

  for(int i=0; i<LED_AMOUNT; ++i){
    float brightness = cos(fade + PI);
    brightness = (brightness + 1) / 2;
    brightness *= 255;
    leds[i] = CHSV(color, 255, brightness);
  }

  if(fade >= TWO_PI) {
    fade = 0;
    color = random(255);
  }

  FastLED.show();

  fade += 0.08;
}
