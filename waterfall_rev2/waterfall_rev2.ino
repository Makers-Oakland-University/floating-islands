#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#include "declarations.h"
#include "variables.h"


Adafruit_NeoPixel stripL1 = Adafruit_NeoPixel(L1_COUNT, L1_PIN);
Adafruit_NeoPixel stripL4 = Adafruit_NeoPixel(L4_COUNT, L4_PIN);
Adafruit_NeoPixel stripL5 = Adafruit_NeoPixel(L5_COUNT, L5_PIN);
Adafruit_NeoPixel stripL6 = Adafruit_NeoPixel(L6_COUNT, L6_PIN);

void setup() {
  // put your setup code here, to run once:

  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  randomSeed(analogRead(0));

  stripL1.begin();
  stripL4.begin();
  stripL5.begin();
  stripL6.begin();

  stripL1.setBrightness(255);
  stripL4.setBrightness(70);
  stripL5.setBrightness(70);
  stripL6.setBrightness(70);

  updateLEDs();
}

void loop() {
  currentTime = millis();
  // Wave Animation
  if ((currentTime - lastTime) >= waveDelay) {
    waveAnimation = true;
    waveDelay = random(500, 5000);
  }

  if (waveAnimation == true) {
    if ((currentTime - lastWaveUpdate) > waveAnimationDelay) {
      for (int i = 0; i < L4_COUNT; i++) {
        if (i == focusWave) {
          colorsL4[i] = {0, 255, 255};
          colorsL5[i] = {0, 255, 255};
          colorsL6[i] = {0, 255, 255};
        }
        else if (abs(focusWave - i) <= 1) {
          colorsL4[i] = {0, 180, 180};
          colorsL5[i] = {0, 180, 180};
          colorsL6[i] = {0, 180, 180};
        }
        else {
          colorsL4[i] = {0, 50, 50};
          colorsL5[i] = {0, 50, 50};
          colorsL6[i] = {0, 50, 50};
        }
      }
      updateLEDs();

      focusWave += 1;
      if (focusWave >= L4_COUNT + 2) {
        focusWave = 0;
        waveAnimation = false;
        lastTime = currentTime;
      }
      lastWaveUpdate = currentTime;
    }
  }

  if ((currentTime - lastHouseTimer) >= houseTimer) {
    if (dayMode == true) {
      for (int i = 0; i < NUM_HOUSES; i++) {
        houseDecider = random(0, 101);
        int houseDecided = (houseDecider);
        int currentHouse = houses[i];
        if (colorsL1[currentHouse].r == orange.r) {
          if (houseDecided >= 70) {
            colorsL1[currentHouse].r = 0;
            colorsL1[currentHouse].g = 0;
            colorsL1[currentHouse].b = 0;
          }
        }
        else if (colorsL1[currentHouse].r == 0) {
          if (houseDecided >= 30) {
            colorsL1[currentHouse].r = orange.r;
            colorsL1[currentHouse].g = orange.g;
            colorsL1[currentHouse].b = orange.b;
          }
        }
      }
      lastHouseTimer = currentTime;
      updateLEDs();
    }
  }

}



//  currentTime = millis();
//  if ((currentTime - lastChaseTime) >= chaseDelay) {
//    for (int i = 0; i < RING_COUNT; i++) {
//      if (i == chaseFocus) {
//        colorsL1[i] = red;
//      }
//      else {
//        colorsL1[i] = white;
//      }
//    }
//    chaseFocus += 1;
//    if (chaseFocus > (RING_COUNT - 1)) {
//      chaseFocus = 0;
//    }
//    lastChaseTime = currentTime;
//    updateLEDs();
//  }
// For portal

//  if ((currentTime - lastServoWriteTime) > servoWriteDelay) {
//    if (servoDirection == 0) {
//      servoPos[0] = 80;
//      servoPositive = true;
//    }
//    else if (servoDirection == 1) {
//      servoPos[0] = 88;
//    }
//    else if (servoDirection == 2) {
//      servoPos[0] = 95;
//      servoPositive = false;
//    }
//
//    if (servoPositive == true) {
//      servoDirection += 1;
//    }
//    else {
//      servoDirection -= 1;
//    }
//} Continuous rotation, spins stops then changes directions, spins then stops

