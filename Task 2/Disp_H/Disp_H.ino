//Program to display H on the led matrix

#define latchPin D1
#define clockPin D0
#define dataPin D2

byte leds = 0;
//Array to define a sequence for row multiplexing
byte h[] = { B01101000, B01100100, B00000010, B01100001 };

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  //Loop through each row
  for (int i = 0; i < 4; i++) {
    leds = h[i];
    updateShiftRegister();
    delay(2);
  }
}

//Function to update shift register values
void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}