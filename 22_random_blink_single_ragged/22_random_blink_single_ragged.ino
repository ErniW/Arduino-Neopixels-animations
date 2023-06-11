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

  /*
    Blink pulsesAmount time and move each pulse by positionMove.
  */

  int pulse = 0;
  int pulsesAmount = 3;
  int positionMove = 2;
  int blinkSize = 6;
  int position = random(0, LED_AMOUNT - blinkSize - (positionMove * pulsesAmount));

  float spreadStep = TWO_PI / (blinkSize);
  float animation = 0;

  while (pulse < pulsesAmount) {
    FastLED.clear();

    float fade = (cos(animation) + 1) / 2;

    for (int i = 0; i < blinkSize; i++) {
      float brightness = cos(PI + (i * spreadStep));
      brightness = (brightness + 1) / 2;
      brightness *= 255;

      brightness *= fade;
      
      leds[position + i] = CHSV(0, 0, brightness);

    }

    FastLED.show();
    animation += 0.15;

    if(animation >= PI){
      animation = 0;
      position += positionMove;
      pulse++;
    }
    
    delay(1);
  }

  FastLED.clear();
  FastLED.show();

  delay(100);
}
