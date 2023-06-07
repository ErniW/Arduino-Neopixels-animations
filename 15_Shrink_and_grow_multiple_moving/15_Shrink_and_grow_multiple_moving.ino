#include<FastLED.h>

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 255

#define FRAGMENT_AMOUNT   4
#define FRAGMENT_SIZE     (LED_AMOUNT / FRAGMENT_AMOUNT)
#define FRAGMENT_MIDPOINT (FRAGMENT_SIZE / 2)

CRGB leds[LED_AMOUNT];

float move = 0;

float midpoints[FRAGMENT_AMOUNT];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);

  for(int fragment = 0; fragment < FRAGMENT_AMOUNT; fragment++){
    midpoints[fragment] = FRAGMENT_MIDPOINT + (fragment * FRAGMENT_SIZE);
  }
}

void loop() {

  FastLED.clear();

  float spread = FRAGMENT_MIDPOINT * ((sin(move) + 1) / 2);
  float step = PI / spread;


  /*
    TODO: rewrite for lesser complexity. 
    
    Now it computes cosine for each led in each fragment.
    It can compute once and then place the computation for
    each fragment by multiplying index.
  */

  for(int fragment = 0; fragment < FRAGMENT_AMOUNT; fragment++){
    midpoints[fragment] += 0.05;

    if(midpoints[fragment] > LED_AMOUNT) midpoints[fragment] = 0;
    
    int pos = midpoints[fragment];

    for(int i=0; i<= spread; ++i){
      
      float brightness = cos(i * step);
      brightness = (brightness + 1) / 2;
      brightness *= 255;

      leds[(pos+i) % LED_AMOUNT] = CHSV(0, 0, brightness);

      if( pos - i < 0) {
        leds[pos - i + LED_AMOUNT] = CHSV(0, 0, brightness);
      }
      else leds[pos - i] = CHSV(0, 0, brightness);

    }
  }

  FastLED.show();

  move += 0.05;
}
