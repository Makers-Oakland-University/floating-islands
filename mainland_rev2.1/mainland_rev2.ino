#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#include "declarations.h"
#include "variables.h"
Adafruit_NeoPixel stripL1 = Adafruit_NeoPixel(L1_COUNT, L1_PIN);

Servo S1;
Servo S2;
Servo S3;
Servo S4;


//Variables For Servo Control Board
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
int servoUpdateCount = 0;
#define SERVOMIN  150
#define SERVOMAX  450
uint8_t servonum = 5;
int positions[] = {0, 0, 0, 0, 0};
int moveTo[] = {50, 50, 0, 181, 5};
int speeds[] = {1, 1, 1, 10, 1};
//observatory on 0
//tree closest to wheel on 1
//tree furthest on 3
//continuous rotation on 4




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pwm.begin();
  Serial.println("moveTo(int servoNum, int PositionDeg, Speed)");
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //deactivated due to implementation of PWM Control Board
  //  S1.attach(S1_PIN);
  //  S2.attach(S2_PIN);
  //  S3.attach(S3_PIN);
  //  S4.attach(S4_PIN);
  //  S1.write(80);
  //  S2.write(80);
  //  S3.write(70);
  //  S4.write(110);

  ServoUpdate();

  randomSeed(analogRead(0));

  stripL1.begin();
  stripL1.setBrightness(25);
  stripL1.show();
  updateLEDs();
}

void loop() {
  currentTime = millis();
  // Foliage animation
  if ((currentTime - lastServoWriteTime) >= servoWriteDelay) {
    if (servoPositive == true) {
      moveTo[1] += 1;
      moveTo[4] += 1;
    }
    else if (servoPositive == false) {
      moveTo[1] -= 1;
      moveTo[4] -= 1;
    }
    if (moveTo[1] == 105) {
      servoPositive = false;
    }
    else if (moveTo[1] == 75) {
      servoPositive = true;
    }
    lastServoWriteTime = currentTime;
    ServoUpdate();
    //    Serial.print(servoPos[2]);
    //    Serial.print(" | ");
    //    Serial.println(servoPos[3]);
  }

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

  if ((currentTime - lastZiplineTime) >= ziplineDelay) {
    if (dayMode == true) {
      switch (ziplineStatus) {
        case 0:
          moveTo[3] = 210;  //98
          break;
        case 1:
          moveTo[3]  = 202; //95
          break;
        case 2:
          moveTo[3]  = 175; //89
          break;
        case 3:
          moveTo[3]  = 180; //95
          break;
      }
      ziplineStatus += 1;
      if (ziplineStatus > 3) {
        ziplineStatus = 0;
      }
      lastZiplineTime = currentTime;
      ServoUpdate();
    }
  }

  if ((currentTime - lastObservatoryTime) >= observatoryDelay) {
    if (dayMode == true) {
      switch (observatoryStatus) {
        case 0: // to 120
          moveTo[0] += 5;
          if ( moveTo[0] == 120) {
            observatoryStatus = 1;
          }
          break;
        case 1:
          observatoryDelayCycles += 1;
          if (observatoryDelayCycles == 120) {
            observatoryStatus = 2;
            observatoryDelayCycles = 0;
          }
          break;
        case 2:
          moveTo[0] -= 1;
          if ( moveTo[0] == 0) {
            observatoryStatus = 3;
          }
          break;
        case 3:
          observatoryDelayCycles += 1;
          if (observatoryDelayCycles == 120) {
            observatoryStatus = 0;
            observatoryDelayCycles = 0;
          }
          break;
      }
      lastObservatoryTime = currentTime;
    }
  }
}
