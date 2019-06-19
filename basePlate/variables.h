#ifndef VARIABLES_H
#define VARIABLES_H

bool dayMode = true;

RGB red = {255, 0, 0};
RGB blue = {0, 0, 155};
RGB dullBlue = {0, 0, 127};
RGB green = {0, 255, 0};
RGB yellow = {255, 255, 0};
RGB purple = {255, 0, 255};
RGB white = {255, 255, 255};
RGB dullWhite = {50, 50, 50};
RGB orange = {255, 140, 0};
RGB off = {0, 0, 0};

int focusWave = 20;
long waveDelay = 1000;

long lastWaveUpdate = 0;
int waveAnimationDelay = 10;

long currentTime = 0;
long lastTime = 0;

#endif

