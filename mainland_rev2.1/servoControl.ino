void moveServoTo(int servoNum, int positionDeg, int speedset) {
  moveTo[servoNum] = positionDeg;
  speeds[servoNum] = speedset;
}

void ServoUpdate() {
  servoUpdateCount++;
  for (int a = 0; a < servonum; a++) {
    if (positions[a] != moveTo[a]) {
      if (positions[a] > moveTo[a]) {
        positions[a] = positions[a] - speeds[a];
      } else if (positions[a] < moveTo[a]) {
        positions[a] = positions[a] + speeds[a];
      }
    }
    pwm.setPWM(a, 0, degToPWM(positions[a]));
  }
}

int degToPWM(int degree) {
  int maxToMin = SERVOMAX - SERVOMIN;
  float PWMPERDEGREE = maxToMin / 180;
  return (int)(SERVOMIN + (degree * PWMPERDEGREE));
}
