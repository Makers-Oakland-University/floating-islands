#ifndef VARIABLES_H
#define VARIABLES_H

bool dayMode = true;

int distance;
bool triggerAnimation = false;

RGB red = {255, 0, 0};
RGB blue = {0, 0, 255};
RGB green = {0, 255, 0};
RGB yellow = {255, 255, 0};
RGB purple = {255, 0, 255};
RGB white = {255, 255, 255};
RGB dullWhite = {50, 50, 50};
RGB orange = {255, 140, 0};
RGB off = {0, 0, 0};

RGB colorsL1[L1_COUNT] = {
  {orange.r, orange.g, orange.b}, // 0   house
  {white.r, white.g, white.b}, // 1   RING START
  {white.r, white.g, white.b}, // 2
  {white.r, white.g, white.b}, // 3
  {white.r, white.g, white.b}, // 4
  {white.r, white.g, white.b}, // 5
  {white.r, white.g, white.b}, // 6
  {white.r, white.g, white.b}, // 7
  {white.r, white.g, white.b}, // 8
  {white.r, white.g, white.b}, // 9
  {white.r, white.g, white.b}, // 10
  {white.r, white.g, white.b}, // 11
  {white.r, white.g, white.b}, // 12
  {white.r, white.g, white.b}, // 13
  {white.r, white.g, white.b}, // 14
  {white.r, white.g, white.b}, // 15
  {white.r, white.g, white.b}, // 16
  {white.r, white.g, white.b}, // 17
  {white.r, white.g, white.b}, // 18
  {white.r, white.g, white.b}, // 19
  {white.r, white.g, white.b}, // 20
  {white.r, white.g, white.b}, // 21
  {white.r, white.g, white.b}, // 22
  {white.r, white.g, white.b}, // 23
  {white.r, white.g, white.b}, // 24
  {white.r, white.g, white.b}, // 25
  {white.r, white.g, white.b}, // 26
  {white.r, white.g, white.b}, // 27
  {white.r, white.g, white.b}, // 28
  {white.r, white.g, white.b}, // 29
  {white.r, white.g, white.b}, // 30
  {white.r, white.g, white.b}, // 31
  {white.r, white.g, white.b}, // 32   RING END
};

int servoPos[1] = {90};

long currentTime;
long lastServoWriteTime;
long servoWriteDelay = 15;
bool servoPositive = true;

int houses[NUM_HOUSES] = {0};
long houseDecider;
int houseTimer = 5000;
long lastHouseTimer;

int ringState = 0;
long lastRingUpdate;
bool transition = false;
/* 0 = pulsing ring
 * 1 = warning light
 * 2 = initializing rotor
 * 3 = steady spin
 * 4 = ending rotor
 * 5 = warning light
 * Back to pulsing ring
 */

int state2DelayLimit = 20;
int state3DelayLimit = 100;
long timings[4] = {20000, 10000, 20000, 10000};
long stateStart[4] = {0};
int chaseDelays[4] = {10, 100, 100, 20};
int originalDelays[4] = {10, 100, 100, 20};
int limitDelays[4] = {10, 100, 20, 100};

// state 0
int pulseMod = white.r;
bool pulsePositive = false;

// state 1
bool ringWhite = true;
int chaseFocus = 0;

// state 2, still uses chase focus

RGB transitionBit = blue;
long lastIncrement = 0;

int rotorRefresh = 100;
long lastRotorRefresh;

#endif
