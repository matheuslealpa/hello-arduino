#include <Adafruit_NeoPixel.h>

#define NUM_STRIPS 7
const int LED_PER_STRIP = 42;  // número de LEDs por faixa
const int LED_PIN = 2;         // pino de sinal

Adafruit_NeoPixel strips[NUM_STRIPS];

void setup() {
  Serial.begin(115200);
  
  for (int i = 0; i < NUM_STRIPS; i++) {
    strips[i] = Adafruit_NeoPixel(LED_PER_STRIP, LED_PIN + i * LED_PER_STRIP, NEO_GRB + NEO_KHZ800);
    strips[i].begin();
    strips[i].clear();
  }
}

void displayNumberZero() {
  for (int i = 0; i < NUM_STRIPS; i++) {
    for (int j = 6; j < LED_PER_STRIP; j++) {
      strips[i].setPixelColor(j, strips[i].Color(255, 0, 0));
    }
  }
}

void displayNumberOne() {
  for (int i = 0; i < NUM_STRIPS; i++) {
    for (int j = 6; j < 12; j++) {
      strips[i].setPixelColor(j, strips[i].Color(255, 0, 0));
    }
    for (int j = 36; j < 42; j++) {
      strips[i].setPixelColor(j, strips[i].Color(255, 0, 0));
    }
  }
}

void displayNumberThree() {
  for (int i = 0; i < NUM_STRIPS; i++) {
    for (int j = 6; j < 18; j++) {
      strips[i].setPixelColor(j, strips[i].Color(255, 0, 0));
    }
    for (int j = 30; j < 42; j++) {
      strips[i].setPixelColor(j, strips[i].Color(255, 0, 0));
    }
  }
}

void loop() {
  // Desligar todas as faixas
  for (int i = 0; i < NUM_STRIPS; i++) {
    strips[i].clear();
  }
  
  // Exibir o número "0"
  displayNumberZero();
  for (int i = 0; i < NUM_STRIPS; i++) {
    strips[i].show();
  }
  delay(1000);

  // Exibir o número "1"
  displayNumberOne();
  for (int i = 0; i < NUM_STRIPS; i++) {
    strips[i].show();
  }
  delay(1000);

  // Exibir o número "3"
  displayNumberThree();
  for (int i = 0; i < NUM_STRIPS; i++) {
    strips[i].show();
  }
  delay(1000);
}
