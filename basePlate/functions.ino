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

void sparkle(Adafruit_NeoPixel &strip, uint8_t wait) {
  long sparklePoint1 = random(L1_COUNT);
  long sparklePoint2 = random(L1_COUNT);
  for (int i = 0; i < L1_COUNT; i++) {
    if (i == sparklePoint1 || i == sparklePoint2) {
      stripL1.setPixelColor(i, white.r, white.g, white.b);
    }
    else {
      stripL1.setPixelColor(i, blue.r, blue.g, blue.b);
    }
  }
  stripL1.show();
  delay(wait);
}

