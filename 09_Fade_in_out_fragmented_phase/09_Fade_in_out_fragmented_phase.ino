#include<FastLED.h>

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 255

int fragmentsAmount = 1;
int fragmentSize = LED_AMOUNT / fragmentsAmount;

CRGB leds[LED_AMOUNT];

float fade = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);
}

void loop() {
  for(int i=0; i<fragmentsAmount; i++){

    float brightness = cos(fade + (HALF_PI)*(i));
    
    brightness = (brightness + 1) / 2;
    brightness *= 255;

    //if(brightness < 10) brightness = 0;

    int begin = i * fragmentSize;
    int end = (i+1) * fragmentSize;
    
    for(int j=begin; j<end; j++){
      leds[j] = CHSV(0, 0, (int)brightness);
    }
  }

  fade += 0.03;

  if(fade > 20) {
    fade = 0;
    if(fragmentsAmount >= 8) fragmentsAmount = 1;

    fragmentsAmount *= 2;
    fragmentSize = LED_AMOUNT / fragmentsAmount;
    FastLED.clear();
  }

  FastLED.show();
}
