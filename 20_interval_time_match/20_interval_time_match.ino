#include<FastLED.h>

#define LED_AMOUNT        74
#define DATA_PIN          6
#define GLOBAL_BRIGHTNESS 127

CRGB leds[LED_AMOUNT];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT); 
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);

  Serial.begin(115200);
}

int currentStep = 0;
long prevTime = 0;

void loop() {

  long time = millis();

  int cycleTime = 2000;
  int steps = 100;
  int interval = cycleTime / steps;

  if(time - prevTime >= interval){

    // currentStep += 1;
    // currentStep %= steps;

    int elapsedSteps = (time - prevTime) / interval;
    prevTime += elapsedSteps * interval;

    currentStep += elapsedSteps;
    currentStep %= steps;

    float brightness = (float)currentStep / steps;

    brightness = cos(PI + (TWO_PI * brightness) );
    brightness = (brightness + 1) / 2;
    brightness *= 255;

    if(brightness < 10) brightness = 0;

    for(int i =0; i< LED_AMOUNT; i++){
      leds[i] = CHSV(0, 0, brightness);
    }

    // prevTime = time;
    
    if (currentStep == 0) Serial.println(time);

    FastLED.show();
  }
}
