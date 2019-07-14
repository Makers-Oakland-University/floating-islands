#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>
#include <avr/io.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#include "declarations.h"
#include "variables.h"

Adafruit_NeoPixel stripL1 = Adafruit_NeoPixel(L1_COUNT, L1_PIN);

//I2C PWM Control Board
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


void setup() {

  Serial.begin(9600);

  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  randomSeed(analogRead(0));

  stripL1.begin();

  //begin the connection to the I2C servo control board
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  stripL1.setBrightness(255);
  stripL1.show();
  updateLEDs();
  //  updateServos();
  delay(1000);

}

void loop() {
  currentTime = millis();
  ServoUpdate();
  Serial.print(distance);

  // Sensor for triggered animation
  calcDistance2();

  // Serial.print(distance);

  /*the event requires a specified number of triggers in order to occur. this was added to
     prevent the solar panels from almost constantly being in the event state
     REQUIRED_EVENT_TRIGGERS of 25 works ok, the ultrasonic sensor has way too much noise
  */
  if (distance > 0 && (distance <= DISTANCE_THRESHOLD)) {
    consecutiveEventTriggers++;
    if (consecutiveEventTriggers > REQUIRED_EVENT_TRIGGERS) {
      wiggleCount = 0;
      triggerAnimation = true;
    }

  } else {
    consecutiveEventTriggers = 0;
  }

  Serial.print(" | ");
  Serial.println(triggerAnimation);
  if (dayMode == true) {
    //    servoPos[0] = 92;
    moveTo[0] = 186;
  }
  else if (dayMode == false) {
    //servoPos[0];
    moveTo[0] = 180;
  }

  // Write values to spin servos
  if ((currentTime - lastServoWriteTime) > servoWriteDelay) {
    if (triggerAnimation == true) {
      // s4 - 140 to 180
      // s3 - 140 to 180
      // s2 - 140 to 180
      if (positions[1] < 170) {
        servoPositive = true;
      }
      else if ((positions[1] == 170) && (servoPositive == false)) {
        servoPositive = true;
      }
      else if ((positions[1] == 180)) {
        servoPositive = false;
        wiggleCount += 1;
      }
      if (wiggleCount > WIGGLE_MAX) {
        // break at 180
        servoPositive = false;
        triggerAnimation = false;
      }
    }

    else if (triggerAnimation == false) {
      if (positions[1] == 0) {
        servoPositive = true;
      }
      else if (positions[1] == 180) {
        servoPositive = false;
      }
    }
    if (servoPositive == true) {
      //      servoPos[1] += 1;
      //      servoPos[2] += 1;
      //      servoPos[3] += 1;
      moveTo[1] += 1;
      moveTo[2] += 1;
      moveTo[3] += 1;
    }
    else if (servoPositive == false) {
      //      servoPos[1] -= 1;
      //      servoPos[2] -= 1;
      //      servoPos[3] -= 1;

      moveTo[1] -= 1;
      moveTo[2] -= 1;
      moveTo[3] -= 1;
    }
    updateServos();
    lastServoWriteTime = currentTime;

  }

  // Rainbow ring animation
  if ((currentTime - lastRainbowTime) >= rainbowDelay) {
    for (uint16_t i = 0; i < RING_COUNT; i++) {
      colorsL1[i] = Wheel(i + rainbowFocus & 255);
    }
    rainbowFocus += 1;
    if (rainbowFocus > 255) {
      rainbowFocus = 0;
    }
    lastRainbowTime = currentTime;
    updateLEDs();
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

  if ((currentTime - lastFlickerTimer) >= flickerTimer) {
    if (dayMode == true) {
      for (int i = 0; i < NUM_LAMPS; i++) {
        int currentLamp = lamps[i];
        flickerDecider = random(0, 101);
        if (flickerReps == (flickerRepsMax - i)) {
          if ((flickerDecider >= 80) && (colorsL1[currentLamp].r == 255)) {
            flickerIncrement = random(0, 256);
            colorsL1[currentLamp].r = flickerIncrement;
          }
        }
        else {
          if ((flickerDecider >= 70) && (colorsL1[currentLamp].r != 255)) {
            colorsL1[currentLamp].r = 255;
          }
        }
      }
      updateLEDs();
      flickerReps += 1;
      if (flickerReps > flickerRepsMax) {
        flickerReps = 0;
      }
      lastFlickerTimer = currentTime;
    }
  }





}
