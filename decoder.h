// Safe digital output pins for Tens digit (Segments: a, b, c, d, e, f, g)
const byte tensPins[7] = {13, 12, 14, 27, 26, 25, 33};

// Safe digital output pins for Ones digit (Segments: a, b, c, d, e, f, g)
const byte onesPins[7] = {23, 22, 21, 19, 18, 5, 4};

// Segment patterns for digits 0-9 (Common Cathode: HIGH = ON, LOW = OFF)
const byte digitSegments[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void initDisplay() {
  for (int i = 0; i < 7; i++) {
    pinMode(tensPins[i], OUTPUT);
    pinMode(onesPins[i], OUTPUT);
  }
}

void showDigit(const byte pins[7], int digit) {
  if (digit < 0 || digit > 9) return;
  for (int i = 0; i < 7; i++) {
    digitalWrite(pins[i], digitSegments[digit][i]);
  }
}

void displayCounter(int num) {
  if (num > 99) num = 99;
  if (num < 0) num = 0;

  int tens = num / 10;
  int ones = num % 10;

  showDigit(tensPins, tens);
  showDigit(onesPins, ones);
}
