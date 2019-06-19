void updateLEDs() {
  for (int i = 0; i < L1_COUNT; i++) {
    stripL1.setPixelColor(i, colorsL1[i].r, colorsL1[i].g, colorsL1[i].b);
  }
  stripL1.show();
  for (int i = 0; i < L4_COUNT; i++) {
    stripL4.setPixelColor(i, colorsL4[i].r, colorsL4[i].g, colorsL4[i].b);
  }
  stripL4.show();

  for (int i = 0; i < L5_COUNT; i++) {
    stripL5.setPixelColor(i, colorsL5[i].r, colorsL5[i].g, colorsL5[i].b);
  }
  stripL5.show();

  for (int i = 0; i < L6_COUNT; i++) {
    stripL6.setPixelColor(i, colorsL6[i].r, colorsL6[i].g, colorsL6[i].b);
  }
  stripL6.show();
}

void colorWipe(Adafruit_NeoPixel &strip, uint32_t c, uint8_t wait) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void calcDistance() {
  // Start Ranging -Generating a trigger of 10us burst
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Distance Calculation
  int distance = pulseIn(ECHO_PIN, HIGH);
  distance = distance / 58;
  /* The speed of sound is 340 m/s or 29 us per cm.
     The Ultrasonic burst travels out & back.
     So to find the distance of object we divide by 58  */
}


