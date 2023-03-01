#include<FastLED.h>

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 255

CRGB leds[LED_AMOUNT];

float move = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

void loop() {

  for(int i=0; i<LED_AMOUNT; ++i){
    float hue = i * (255 / LED_AMOUNT);
    hue += sin(move) * LED_AMOUNT;

    float brightness = i + sin(move) * 20;
    brightness = sin(brightness);
    brightness = (brightness + 1) / 2;
    brightness *= 255;

    leds[i] = CHSV(hue, 255, brightness);
  }

  FastLED.show();

  move += 0.06;
}
