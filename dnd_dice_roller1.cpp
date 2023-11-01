#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12,13);

// Define button pins
const int buttonD20 = 2;
const int buttonD12 = 3;
const int buttonD10 = 4;
const int buttonD8 = 5;
const int buttonD6 = 6;
const int buttonD4 = 7;

int state = 1;

long rand20;
long rand12;
long rand10;
long rand8;
long rand6;
long rand4;


void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));

  // Initialize LCD display
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Welcome to my");
  lcd.setCursor(0, 1);
  lcd.print("DnD DiceRoller");

  // Configure button pins
  pinMode(buttonD20, INPUT_PULLUP);
  pinMode(buttonD12, INPUT_PULLUP);
  pinMode(buttonD10, INPUT_PULLUP);
  pinMode(buttonD8, INPUT_PULLUP);
  pinMode(buttonD6, INPUT_PULLUP);
  pinMode(buttonD4, INPUT_PULLUP);
  
  delay(3000);
  lcd.clear();
  //digitalWrite(buttonD20, HIGH);
  //delay(200);
}

// Function to display dice roll result on LCD
void displayDiceRoll(const char *label, long value) {
  lcd.setCursor(0, 0);
  lcd.print(label);
  lcd.setCursor(5, 0);
  lcd.print(value);
  Serial.println(value);
  delay(2500);
  lcd.clear();
}

void loop() {
  // Read button state for D20 roll
  state = digitalRead(buttonD20);
  if (state != HIGH) {
    rand20 = random(1, 21);
    displayDiceRoll("D20:", rand20);
  }

  // Read button state for D12 roll
  state = digitalRead(buttonD12);
  if (state != HIGH) {
    rand12 = random(1, 13);
    displayDiceRoll("D12:", rand12);
  }

  // Read button state for D10 roll
  state = digitalRead(buttonD10);
  if (state != HIGH) {
    rand10 = random(1, 11);
    displayDiceRoll("D10:", rand10);
  }

  // Read button state for D8 roll
  state = digitalRead(buttonD8);
  if (state != HIGH) {
    rand8 = random(1, 9);
    displayDiceRoll("D8:", rand8);
  }

  // Read button state for D6 roll
  state = digitalRead(buttonD6);
  if (state != HIGH) {
    rand6 = random(1, 7);
    displayDiceRoll("D6:", rand6);
  }

  // Read button state for D4 roll
  state = digitalRead(buttonD4);
  if (state != HIGH) {
    rand4 = random(1, 4);
    displayDiceRoll("D4:", rand4);
  }


}
