#include<FastLED.h>

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 255

#define SCANNER_SIZE      10

CRGB leds[LED_AMOUNT];

int position = 0;
bool dir = false;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

void loop() {

  float step = TWO_PI / SCANNER_SIZE;

  FastLED.clear();

  for(int i=0; i<SCANNER_SIZE; i++){
    float brightness = cos(PI + (i * step));
    brightness = (brightness + 1) / 2;
    brightness *= 255;

    brightness = max(brightness, 30);

    leds[position + i] = CHSV(255, 255, brightness);
  }

  FastLED.show();

  if(position == LED_AMOUNT - SCANNER_SIZE || position == 0) dir = !dir;

  if(dir) position += 1;
  else position -= 1;
  delay(100);
}
