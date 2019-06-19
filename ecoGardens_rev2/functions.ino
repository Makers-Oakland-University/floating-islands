void updateLEDs() {
  for (int i = 0; i < L1_COUNT; i++) {
    stripL1.setPixelColor(i, colorsL1[i].r, colorsL1[i].g, colorsL1[i].b);
  }
  stripL1.show();
}


void updateServos() {
  S1.write(servoPos[0]);
  delay(5);
  S2.write(servoPos[1]);
  delay(5);
  S3.write(servoPos[2]);
  delay(5);
  S4.write(servoPos[3]);
}
void calcDistance() {
  // Start Ranging -Generating a trigger of 10us burst
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Distance Calculation
  distance = pulseIn(ECHO_PIN, HIGH);
  distance = distance / 58;
  /* The speed of sound is 340 m/s or 29 us per cm.
     The Ultrasonic burst travels out & back.
     So to find the distance of object we divide by 58  */
}

void colorWipe(Adafruit_NeoPixel &strip, uint32_t c, uint8_t wait) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

RGB Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return {(255 - WheelPos * 3), 0, (WheelPos * 3)};
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return {0, (WheelPos * 3), (255 - WheelPos * 3)};
  }
  WheelPos -= 170;
  return {(WheelPos * 3), (255 - WheelPos * 3), 0};
}
