void moveServoTo(int servoNum, int positionDeg, int speedset) {
  moveTo[servoNum] = positionDeg;
  speeds[servoNum] = speedset;
}


/*servo update function for the adafruit pwm board, utilizes a moveTo array and servo num. just call
 * this function somewhere in the loop at a regular interval and all your servo's will move smoothly at whatever
 * speed you want. */
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


/*  to add the PWM control board to this project almost all the code regarding the servo's had to be changed. 
 * 
 * servo.write has been replaced with moveTo() which can be found in servoControl.ino
 * servo positions can be accessed in the positions[] array and the servo's speed is also accessable in the speeds[] array
 * 
 * the ServoUpdate() function changes the positions of the servos very slightly everytime it is called according to the values
 * added to the moveTo[] array. I recomend calling ServoUpdate() in the loop at regular intervals as was done in this project. 
 *  
 * also don't forget adding the pwm.begin() function found in the setup.
 * 
 * hope that helped you with whatever it was you're doing looking at this code
 */
