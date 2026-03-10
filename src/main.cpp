#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <Keypad.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, 22, 21);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {13, 12, 14, 27};
byte colPins[COLS] = {26, 25, 33, 32};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String input = "";

void updateDisplay() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.drawStr(0, 20, "Key Pressed:");
  u8g2.setFont(u8g2_font_ncenB24_tr);
  u8g2.drawStr(40, 55, input.c_str());
  u8g2.sendBuffer();
}

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  u8g2.begin();
  u8g2.setContrast(255);
  updateDisplay();
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.println(key);
    input = String(key); // shows last pressed key
    updateDisplay();
  }
}