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
RGB orange = {255, 140, 0};
RGB off = {0, 0, 0};

RGB colorsL1[L1_COUNT] = {
  {red.r, red.g, red.b},
  {orange.r, orange.b, orange.b},
  {red.r, red.g, red.b}
};

RGB colorsL4[L4_COUNT] = {
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127}
};

RGB colorsL5[L5_COUNT] = {
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127}
};

RGB colorsL6[L6_COUNT] = {
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127},
  {0, 127, 127}
};

int focusWave = 0;
long waveDelay = 1000;
bool waveAnimation = false;

long lastWaveUpdate = 0;
int waveAnimationDelay = 100;

long currentTime = 0;
long lastTime = 0;

int houses[NUM_HOUSES] = {1};
long houseDecider;
int houseTimer = 5000;
long lastHouseTimer;

int lamps[NUM_LAMPS] = {0, 2};

#endif
