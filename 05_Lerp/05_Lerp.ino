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

    float interpolation = sin(animation + i * 0.5);
    interpolation = (interpolation + 1) / 2;
    interpolation *= 255;

    CRGB c1 = CRGB(255, 216,0);
    CRGB c2 = CRGB(0,150,255);

    leds[i].r = lerp8by8(c1.r, c2.r, interpolation);
    leds[i].g = lerp8by8(c1.g, c2.g, interpolation);
    leds[i].b = lerp8by8(c1.b, c2.b, interpolation);
  }

  FastLED.show();

  animation += 0.1;
}
