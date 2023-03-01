#include<FastLED.h>

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 255

CRGB leds[LED_AMOUNT];

float move = 0;
float period = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

void loop() {

  int midpoint = LED_AMOUNT / 2;
 

  float spread = midpoint * ((sin(move) + 1) / 2);
  float step = PI / (spread);

  FastLED.clear();

  for(int i=0; i<= spread; ++i){
    float brightness = cos(((i) * step));
    brightness = (brightness + 1) / 2;
    brightness *= 255;
    leds[midpoint+i] = CHSV(0, 0, brightness);
    leds[midpoint-i] = CHSV(0, 0, brightness);
  }

  FastLED.show();

  move += 0.05;

  if(move >= TWO_PI) move = 0;
}
