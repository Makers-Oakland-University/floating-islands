#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define L1_COUNT    23
#define RING_COUNT  16

#define L1_PIN      3

//switched to servo PWM Board
//#define S1_PIN      10 // Continuous Rotation
//#define S2_PIN      4
//#define S3_PIN      5
//#define S4_PIN      6

//new servo declarations
//cont. rotation servo on 0, solar pannels on 1-3
//also to save your sanity the cont. rotation servo stops rotating around an angle value of 186


#define SERVOMIN  150
#define SERVOMAX  450

#define REQUIRED_EVENT_TRIGGERS 25


#define TRIG_PIN    7
#define ECHO_PIN    8
#define MODE_PIN    9

#define NUM_HOUSES   3
#define NUM_LAMPS    4

#define DISTANCE_THRESHOLD       40
#define WIGGLE_MAX                3

struct RGB {
  byte r;
  byte g;
  byte b;
};

#endif
