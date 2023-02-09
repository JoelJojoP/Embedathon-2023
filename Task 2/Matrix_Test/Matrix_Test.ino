//Program to test led matrix by glowing each row

#define latchPin D1
#define clockPin D0
#define dataPin D2

byte leds = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  //Loop through each row
  for (int i = 0; i < 4; i++) {
    leds = 1 << (3 - i);
    updateShiftRegister();
    delay(500);
  }
}

//Function to update shift register value
void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}