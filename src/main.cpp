#include <Adafruit_NeoPixel.h>

const int LED_PER_STRIP = 42;  // número de LEDs
const int LED_PIN = 2;         // pino de sinal

Adafruit_NeoPixel pixels(LED_PER_STRIP, LED_PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 1000

const byte zero[] = {B000000, B111111, B111111, B111111, B111111, B111111, B111111}; 
const byte one[] = {B000000, B111111, B000000, B000000, B000000, B000000, B111111}; 
const byte two[] = {B111111, B111111, B111111, B000000, B111111, B111111, B000000}; 
const byte three[] = {B111111, B111111, B111111, B000000, B000000, B111111, B111111}; 
const byte four[] = {B111111, B111111, B000000, B111111, B000000, B000000, B111111};
const byte five[] = {B111111, B000000, B111111, B111111, B000000, B111111, B111111};
const byte six[] = {B111111, B000000, B111111, B111111, B1111111, B111111, B111111};
const byte seven[] = {B000000, B111111, B111111, B000000, B000000, B000000, B111111}; 
const byte eight[] = {B111111, B111111, B111111, B111111, B111111, B111111, B111111}; 
const byte nine[] = {B111111, B111111, B111111, B111111, B000000, B111111, B111111}; 

void setup() {
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif

  pixels.begin();
}

void loop() {
  printNumber(zero, sizeof(zero) / sizeof(zero[0]), pixels.Color(255, 0, 0));
  printNumber(one, sizeof(one) / sizeof(one[0]), pixels.Color(0, 255, 0));
  printNumber(two, sizeof(two) / sizeof(two[0]), pixels.Color(0, 0, 255));
  printNumber(three, sizeof(three) / sizeof(three[0]), pixels.Color(255, 255, 0));
  printNumber(four, sizeof(four) / sizeof(four[0]), pixels.Color(0, 255, 255));
  printNumber(five, sizeof(five) / sizeof(five[0]), pixels.Color(255, 0, 255));
  printNumber(six, sizeof(six) / sizeof(six[0]), pixels.Color(255, 165, 0));
  printNumber(seven, sizeof(seven) / sizeof(seven[0]), pixels.Color(0, 128, 0));
  printNumber(eight, sizeof(eight) / sizeof(eight[0]), pixels.Color(128, 0, 128));
  printNumber(nine, sizeof(nine) / sizeof(nine[0]), pixels.Color(150, 0, 150));
}

void printNumber(const byte* number, int length, uint32_t color) {
  pixels.clear();

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < 6; j++) {
      if (bitRead(number[i], j)) {
        pixels.setPixelColor(i * 6 + j, color);
      }
    }
  }

  pixels.show();
  delay(DELAYVAL);
}
