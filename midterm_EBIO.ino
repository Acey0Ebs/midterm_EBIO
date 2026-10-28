/*======================================================
                     Counter
========================================================
Description:
Using the 1 Ir Sensor to count the objects detected, 1
Ir sensor for subtracting and display it on a 7 segment.
Per request the reset should display 9 on the counter.

Designer Engineer:
Ebio, Ann Clarise

Date:
Oct. 14, 2026
======================================================*/

#include "decoder.h"

// GPIOS
const byte IrAdd = 36;
const byte IrSub = 39;
const byte Rst = 34;

// Variables
int counter = 0;
int inputAdd = 0;
int inputSub = 0;
int RstIn = 0;

void setup() {
  pinMode(IrAdd, INPUT);
  pinMode(IrSub, INPUT);
  pinMode(Rst, INPUT_PULLUP);
  // Initialize 7-segment display pins
  initDisplay();

  Serial.begin(9600);
}

void loop() {
RstIn = digitalRead(Rst);
if (RstIn == HIGH){

  inputAdd = digitalRead(IrAdd);
  if (inputAdd == 0) {
    if (counter < 99) {
      counter++;
    }
    delay(300);
  }

  inputSub = digitalRead(IrSub);
  if (inputSub == 0) {
    if (counter > 0) {
      counter--;
    }
    delay(300);
  }

  displayCounter(counter);
} else {
  counter = 9;
  }
  delay(50);
}