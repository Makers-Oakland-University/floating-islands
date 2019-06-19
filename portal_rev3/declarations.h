#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define L1_COUNT    33
#define RING_COUNT  32

#define L1_PIN      3
#define S1_PIN      4 // Continuous Rotation
#define S2_PIN      5

#define TRIG_PIN    7
#define ECHO_PIN    8
#define MODE_PIN    9

#define NUM_HOUSES   1
#define NUM_LAMPS    0

#define DISTANCE_THRESHOLD       40

#define RING_DIVIDER    5

struct RGB {
  byte r;
  byte g;
  byte b;
};

//        for (int i = 1; i <= RING_COUNT; i++) {
//          if (i == chaseFocus) {
//            colorsL1[i] = blue;
//          }
//          else {
//            colorsL1[i] = white;
//          }
//        }
//        chaseFocus += 1;
//        if (chaseFocus > (RING_COUNT)) {
//          chaseFocus = 1;
//        }


#endif
