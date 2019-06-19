#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define L1_COUNT    28
#define RING_COUNT  8

#define L1_PIN      3
#define S1_PIN      4 // Continuous Rotation
#define S2_PIN      5
#define S3_PIN      6
#define S4_PIN      7

#define MODE_PIN    9

#define NUM_HOUSES   12
#define NUM_LAMPS    3

struct RGB {
  byte r;
  byte g;
  byte b;
};

#endif
