#include<FastLED.h>

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 255

CRGB leds[LED_AMOUNT];
float phase = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

void loop() {

  float step = TWO_PI / LED_AMOUNT;

  FastLED.clear();

  for(int i=0; i<LED_AMOUNT; i++){
    float brightness = cos(PI + (i * step));
    brightness *= cos(PI+ phase);
    brightness = (brightness + 1) / 2;
    brightness *= 255;

    
    brightness = max(brightness, 20);

    leds[i] = CHSV(0,0, brightness);
  }

  FastLED.show();
  phase += 0.08;
}
