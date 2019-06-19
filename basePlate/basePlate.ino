#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#include "declarations.h"
#include "variables.h"

Adafruit_NeoPixel stripL1 = Adafruit_NeoPixel(L1_COUNT, L1_PIN);
Adafruit_NeoPixel stripL2 = Adafruit_NeoPixel(L2_COUNT, L2_PIN);


void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(0));
  stripL1.begin();
  stripL2.begin();
  stripL1.setBrightness(100);
  stripL2.setBrightness(25);
  stripL1.show();
  stripL2.show();

  colorWipe(stripL1, stripL1.Color(blue.r, blue.g, blue.b), 10);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  currentTime = millis();
  if ((currentTime - lastWaveUpdate) > waveAnimationDelay) {
    for (int i = 0; i < L2_COUNT; i++) {
      if (i == focusWave) {
        stripL2.setPixelColor(i, 0, 255, 255);
      }
      else if (abs(focusWave - i) <= 1) {
        stripL2.setPixelColor(i, 0, 120, 120);
      }
      else {
        stripL2.setPixelColor(i, 0, 0, 83);
      }
    }
    stripL2.show();

    focusWave -= 1;
    if (focusWave <= -2) {
      focusWave = 20;
      lastTime = currentTime;
    }
    lastWaveUpdate = currentTime;
  }

  sparkle(stripL1, 40);
}

