#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#include "declarations.h"
#include "variables.h"

Adafruit_NeoPixel stripL1 = Adafruit_NeoPixel(L1_COUNT, L1_PIN);
Servo S1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  S1.attach(S1_PIN);
  updateServos();

  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  randomSeed(analogRead(0));

  stripL1.begin();
  stripL1.setBrightness(100);
  stripL1.show();
  updateLEDs();

}

void loop() {
  // put your main code here, to run repeatedly:
  currentTime = millis();

  // House animation
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

  if ((currentTime - lastRingUpdate) >= chaseDelays[ringState]) {

    //    // state 0
    switch (ringState) {
      case 0:
        if (transition == true) {
          // do transition state animation
          bool allOff = true;
          for (int i = 1; i <= RING_COUNT; i++) {
            if (colorsL1[i].r != 0) {
              colorsL1[i].r -= 1;
              allOff = false;
            }
            if (colorsL1[i].g != 0) {
              colorsL1[i].g -= 1;
              allOff = false;
            }
            if (colorsL1[i].b != 0) {
              colorsL1[i].b -= 1;
              allOff = false;
            }
          }
          if (allOff == true) {
            transition = false;
            pulseMod = white.r;
            pulsePositive = false;
            stateStart[0] = currentTime;
            for (int i = 0; i < 4; i++) {
              chaseDelays[i] = originalDelays[i];
            }
          }
        }
        else if (transition == false) {
          for (int i = 1; i <= RING_COUNT; i++) {
            colorsL1[i].r = (white.r - pulseMod);
            colorsL1[i].g = (white.g - pulseMod);
            colorsL1[i].b = (white.b - pulseMod);
          }
          if (pulsePositive == true) {
            pulseMod += 1;
          }
          else if (pulsePositive == false) {
            pulseMod -= 1;
          }
          if (pulseMod == white.r) {
            pulsePositive = false;
          }
          else if (pulseMod == 0) {
            pulsePositive = true;
            if ((currentTime - stateStart[ringState]) >= timings[ringState]) {
              // move onto next state
              ringState = 1;
              transition = true;
            }
          }
        }
        break;

      case 1:
        if (transition == true) {
          chaseFocus = 0;
          chaseDelays[2] = chaseDelays[1];
          if (colorsL1[1].r != dullWhite.r) {
            for (int i = 1; i <= RING_COUNT; i++) {
              colorsL1[i].r -= 3;
              colorsL1[i].g -= 3;
              colorsL1[i].b -= 3;
            }
          }
          else if (colorsL1[1].r == dullWhite.r) {
            transition = false;
            stateStart[1] = currentTime;
          }
        }
        else if (transition == false) {
          if ((currentTime - lastRotorRefresh) >= (8 * rotorRefresh)) {
            if (servoPos[0] != 80) {
              servoPos[0] -= 1;
            }
            updateServos();
            lastRotorRefresh = currentTime;
          }
          for (int i = 1; i <= RING_COUNT; i++) {
            if (i == chaseFocus) {
              colorsL1[i] = blue;
            }
            else {
              if (ringWhite == true) {
                colorsL1[i] = dullWhite;
                if (((currentTime - stateStart[ringState]) >= timings[ringState]) && (servoPos[0] == 80)) {
                  // move onto next state
                  ringState = 2;
                  transition = true;
                  transitionBit = blue;
                }
              }
              else if (ringWhite == false) {
                colorsL1[i] = off;
              }
            }
          }
          chaseFocus += 1;
          if (chaseFocus > (RING_COUNT)) {
            chaseFocus = 1;
          }
          if (chaseFocus % 8 == 0) {
            ringWhite = !ringWhite;
          }
        }
        break;

      case 2:
        if (transition == true) {
          // put transition code
          for (int i = 1; i <= RING_COUNT; i++) {
            if (i == chaseFocus) {
              colorsL1[i] = transitionBit;
            }
            else {
              colorsL1[i] = dullWhite;
            }
          }
          chaseFocus += 1;
          if (chaseFocus > (RING_COUNT)) {
            chaseFocus = 1;
          }
          if ((chaseDelays[2] != limitDelays[2]) && ((currentTime - lastIncrement) >= 30)) {
            lastIncrement = currentTime;
            chaseDelays[2] -= 1;
          }
          if (transitionBit.g != green.g) {
            transitionBit.g += 1;
          }
          if (transitionBit.b != green.b) {
            transitionBit.b -= 1;
          }
          if ((currentTime - lastRotorRefresh) >= (4 * rotorRefresh)) {
            if (servoPos[0] != 20) {
              servoPos[0] -= 2;
            }
            updateServos();
            lastRotorRefresh = currentTime;
          }
          if ((chaseDelays[2] == limitDelays[2]) && (transitionBit.g == green.g) && (transitionBit.b == green.b) && (servoPos[0] == 20)) {
            transition = false;
            stateStart[ringState] = currentTime;
          }
        }
        else if (transition == false) {
          for (int i = 1; i <= RING_COUNT; i++) {
            if (i == chaseFocus) {
              colorsL1[i] = green;
            }
            else {
              colorsL1[i] = dullWhite;
            }
          }
          chaseFocus += 1;
          if (chaseFocus > (RING_COUNT)) {
            chaseFocus = 1;
          }
          if ((currentTime - stateStart[ringState]) >= timings[ringState]) {
            // move onto next state
            ringState = 3;
            transition = true;
            transitionBit = green;
          }
        }
        break;

      case 3:
        if (transition == true) {
          // put transition code
          for (int i = 1; i <= RING_COUNT; i++) {
            if (i == chaseFocus) {
              colorsL1[i] = transitionBit;
            }
            else {
              colorsL1[i] = dullWhite;
            }
          }
          chaseFocus += 1;
          if (chaseFocus > (RING_COUNT)) {
            chaseFocus = 1;
          }
          if (transitionBit.g != red.g) {
            transitionBit.g -= 1;
          }
          if (transitionBit.r != red.r) {
            transitionBit.r += 1;
          }
          if ((chaseDelays[3] != limitDelays[3]) && ((currentTime - lastIncrement) >= 30) && (transitionBit.g == red.g) && (transitionBit.r == red.r)) {
            lastIncrement = currentTime;
            chaseDelays[3] += 1;
          }
          if ((currentTime - lastRotorRefresh) >= (4 * rotorRefresh)) {
            if (servoPos[0] != 80) {
              servoPos[0] += 2;
            }
            updateServos();
            lastRotorRefresh = currentTime;
          }
          if ((chaseDelays[3] == limitDelays[3]) && (transitionBit.g == red.g) && (transitionBit.r == red.r) && (servoPos[0] == 80)) {
            transition = false;
            stateStart[3] = currentTime;
          }
        }
        else if (transition == false) {
          for (int i = 1; i <= RING_COUNT; i++) {
            if (i == chaseFocus) {
              colorsL1[i] = red;
            }
            else {
              if (ringWhite == true) {
                colorsL1[i] = dullWhite;
                if (((currentTime - stateStart[3]) >= timings[3]) && (servoPos[0] == 90)) {
                  // move onto next state
                  ringState = 0;
                  transition = true;
                  transitionBit = red;
                }
              }
              else if (ringWhite == false) {
                colorsL1[i] = off;
              }
            }
          }
          chaseFocus += 1;
          if (chaseFocus > (RING_COUNT)) {
            chaseFocus = 1;
          }
          if (chaseFocus % 8 == 0) {
            ringWhite = !ringWhite;
          }
          if ((currentTime - lastRotorRefresh) >= (8 * rotorRefresh)) {
            if (servoPos[0] != 90) {
              servoPos[0] += 1;
            }
            updateServos();
            lastRotorRefresh = currentTime;
          }
        }
        break;
    }
    lastRingUpdate = currentTime;
    updateLEDs();
    updateServos();
    Serial.print(ringState);
    Serial.print("  |  ");
    Serial.print(transition);
    Serial.print("  |  ");
    Serial.println(servoPos[0]);
  }
}
