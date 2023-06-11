#include <FastLED.h>

#define LED_AMOUNT 74
#define DATA_PIN 6
#define GLOBAL_BRIGHTNESS 255

CRGB leds[LED_AMOUNT];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT);
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

void loop() {

  int blinkSize = 6;
  int position = random(0, LED_AMOUNT - blinkSize);

  float spreadStep = TWO_PI / (blinkSize);
  float animation = 0;

  /*
    Variant 1 - Start from dark:
    
    animation < TWO_PI
    cos(PI + animation)

    Variant 2 - Start from bright and fade away:
    
    animation < PI
    cos(animation)
  */

  while (animation < TWO_PI) { // TWO_PI * 3 will blink three times in same place
    FastLED.clear();

    float fade = (cos(PI + animation) + 1) / 2;
    //fade = max(0.05, fade);

    for (int i = 0; i < blinkSize; i++) {
      float brightness = cos(PI + (i * spreadStep));
      brightness = (brightness + 1) / 2;
      brightness *= 255;

      //brightness = max(20, brightness);
      brightness *= fade;
      
      leds[position + i] = CHSV(0, 0, brightness);

    }

    FastLED.show();
    animation += 0.15;
    
    delay(3); // speed of blink
  }

  FastLED.clear();
  FastLED.show();

  //delay(100); // wait time for next blink
}
