void updateLEDs() {
  for (int i = 0; i < L1_COUNT; i++) {
    stripL1.setPixelColor(i, colorsL1[i].r, colorsL1[i].g, colorsL1[i].b);
  }
  stripL1.show();
}


void updateServos() {
  //look, i already wrote this code before this saves me like 10 minutes of hunting down useless references
  ServoUpdate();
}

void calcDistance() {
  cli();
  int totalDistance = 0; 

/*the solar pannels kept getting stuck in their loop due to inconsistent reads from the ultrasonic sensor 
 * 
 */
  
  // Start Ranging -Generating a trigger of 10us burst
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Distance Calculation
  distance = pulseIn(ECHO_PIN, HIGH);
  distance = (int) distance / 58;
  Serial.println(distance);

  /* The speed of sound is 340 m/s or 29 us per cm.
     The Ultrasonic burst travels out & back.
     So to find the distance of object we divide by 58  */
    sei();

 
}


/*OH MY GOD its like exactly the same thing as the last one
 * except this one works so we add the number 2 at the end, nobody will ever notice
 */
void calcDistance2() {
  cli();
  // Clears the trigPin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  int duration = pulseIn(ECHO_PIN, HIGH);
  // Calculating the distance
  int  d = (int) duration * 0.034 / 2;
  if (d > 0 && d < 200) {
    distance = d;
  }
  // Prints the distance on the Serial Monitor
  sei();
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
