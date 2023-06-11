#include <FastLED.h>
#include "Blink.h"


#define LED_AMOUNT 74
#define DATA_PIN 6
#define GLOBAL_BRIGHTNESS 255

#define MAX_BLINK_AMOUNT 4

CRGB leds[LED_AMOUNT];

LinkedList* pulses = new LinkedList();

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, LED_AMOUNT);
  FastLED.setBrightness(GLOBAL_BRIGHTNESS);

  Blink* b = new Blink(0,6);
  pulses->insert(b);

  Serial.begin(9600);
  Serial.println("Start...");
}

unsigned long prevTime = 0;

int nextBlinkWaitTime= 400;
bool createNextBlink = false;

//Blink b = Blink(0, 6);

void loop() {
  unsigned long time = millis();

  FastLED.clear();

  for(Blink* b = pulses->getHead(); b != nullptr; b = b->next){

    // Serial.println(b->position);

    blinkAnimation(b);
    b->animation += 0.3;

    // if(b->animation >= TWO_PI) {
    //   pulses->remove(b);
    //   nextBlinkWaitTime = random(0,200);
    //   //createNextBlink = true;
    // }
  }

  for(Blink* b = pulses->getHead(); b != nullptr; b = b->next){
    // if(b->next != nullptr){
    //   if(b->next)
    // }

    if(b->animation >= TWO_PI){
      pulses->remove(b);
    }
  }
  
  if(time - prevTime >= nextBlinkWaitTime){
    // Serial.println("Inserting new element");
    
    int size = 6;
    Blink* b = new Blink(random(0,LED_AMOUNT-size), size);
    pulses->insert(b);
    nextBlinkWaitTime = random(200);
    prevTime = time;

  //   for(Blink* b = pulses->getHead(); b != nullptr; b = b->next){
  //   Serial.print(b->position);
  //   Serial.print('\t');
  // }
  // Serial.println();
  } 

  FastLED.show();
  Serial.println(pulses->getLength());

  
}


void blinkAnimation(Blink *b){
  

  float sinStep = TWO_PI / (b->size - 1);


  for(int led=0; led < b->size; led++){
    

    float brightness = cos(PI + (led * sinStep));
    brightness = (brightness + 1) /2;
    brightness *= 255;
    
    brightness = max(30, brightness);

    float fade = cos(PI + b->animation);
    fade = (fade + 1) / 2;
    //fade = max(0.05,fade);

    brightness *= fade;
    leds[led + b->position] = CHSV(100,0,brightness);
  }

  

  
}
  

  /*

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

  delay(100); */
