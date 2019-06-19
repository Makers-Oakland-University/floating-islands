#ifndef VARIABLES_H
#define VARIABLES_H

bool dayMode = true;

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
  {purple.r, purple.g, purple.b}, // 0   
  {purple.r, purple.g, purple.b}, // 1 
  {purple.r, purple.g, purple.b}, // 2
  {purple.r, purple.g, purple.b}, // 3
  {blue.r, blue.g, blue.b}, // 4
  {blue.r, blue.g, blue.b}, // 5
  {blue.r, blue.g, blue.b}, // 6
  {blue.r, blue.g, blue.b}, // 7
  {green.r, green.g, green.b}, // 8
  {green.r, green.g, green.b}, // 9
  {green.r, green.g, green.b}, // 10
  {green.r, green.g, green.b}, // 11
  {orange.r, orange.g, orange.b}, // 12
  {orange.r, orange.g, orange.b}, // 13
  {orange.r, orange.g, orange.b}, // 14
  {orange.r, orange.g, orange.b}, // 15
  {orange.r, orange.g, orange.b}, // 16
  {orange.r, orange.g, orange.b}, // 17
  {orange.r, orange.g, orange.b}, // 18
  {orange.r, orange.g, orange.b}, // 19
  {orange.r, orange.g, orange.b}, // 20
  {orange.r, orange.g, orange.b}, // 21
  {orange.r, orange.g, orange.b}, // 22
  {orange.r, orange.g, orange.b}, // 23
  {red.r, red.g, red.b}, // 24
  {red.r, red.g, red.b}, // 25
  {red.r, red.g, red.b}, // 26
  {red.r, red.g, red.b}, // 27
};

int servoPos[4] = {0, 89, 90, 90};

long currentTime;
long lastServoWriteTime;
long servoWriteDelay = 100;
bool servoPositive = true;

int houses[NUM_HOUSES] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
long houseDecider;
int houseTimer = 5000;
long lastHouseTimer;

long lastZiplineTime;
long ziplineDelay = 10000;
int ziplineStatus = 0;


long lastObservatoryTime;
long observatoryDelay = 50;
int observatoryStatus = 0;
int observatoryDelayCycles = 0;
#endif
