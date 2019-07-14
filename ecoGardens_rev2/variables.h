#ifndef VARIABLES_H
#define VARIABLES_H

bool dayMode = true;

volatile int distance;
bool triggerAnimation = false;
int wiggleCount = 0;

RGB red = {255, 0, 0};
RGB blue = {0, 0, 255};
RGB green = {0, 255, 0};
RGB yellow = {255, 255, 0};
RGB purple = {255, 0, 255};
RGB white = {255, 255, 255};
RGB orange = {255, 140, 0};
RGB off = {0, 0, 0};

RGB colorsL1[L1_COUNT] = {
  {white.r, white.g, white.b}, // 0   RING START
  {white.r, white.g, white.b}, // 1
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
  {white.r, white.g, white.b}, // 15   RING END
  {orange.r, orange.g, orange.b}, // 16, house
  {orange.r, orange.g, orange.b}, // 17, house
  {orange.r, orange.g, orange.b}, // 18, house
  {red.r, red.g, red.b}, // 19, lamp
  {red.r, red.g, red.b}, // 20, lamp
  {red.r, red.g, red.b}, // 21, lamp
  {red.r, red.g, red.b}, // 22, lamp
};

//variables for servo control using adafruit pwm board
//int servoPos[4] = {85, 0, 0, 0};
uint8_t servonum = 4;
int positions[] = {0, 0, 0, 0};
int moveTo[] = {186, 0, 0, 0};
int speeds[] = {2, 2, 2, 2};
int servoUpdateCount = 0;

int consecutiveEventTriggers = 0; 


long currentTime;

long lastRainbowTime;
int rainbowDelay = 500;
uint16_t rainbowFocus = 0;

long lastServoWriteTime;
long servoWriteDelay = 10;
bool servoPositive = true;

int houses[NUM_HOUSES] = {16, 17, 18};
long houseDecider;
int houseTimer = 5000;
long lastHouseTimer;

int lamps[NUM_LAMPS] = {19, 20, 21, 22};
long flickerDecider;
long flickerIncrement;
int flickerTimer = 500;
long lastFlickerTimer; 
int flickerReps;
int flickerRepsMax = 7;

int restoreTimer = 15;
long lastRestoreTime;
long restoreDecider;
long restoreIncrement;

#endif
