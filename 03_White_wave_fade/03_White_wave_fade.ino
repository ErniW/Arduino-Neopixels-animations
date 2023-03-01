#include<FastLED.h>

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 255

CRGB leds[LED_AMOUNT];

float animation = 0;
float fadeAnimation = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

void loop() {

  float fadeEffect = (sin(fadeAnimation) + 1) / 2;

  FastLED.setBrightness(fadeEffect * 255);

  for(int i=0; i<LED_AMOUNT; ++i){
    
    float brightness = sin(animation + i * 0.3);
    brightness = (brightness + 1) / 2;
    brightness *= 255;

    leds[i] = CHSV(0, 0, brightness);
  }

  FastLED.show();

  animation += 0.08;
  fadeAnimation += 0.08;
}
