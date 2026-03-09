#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C display(U8G2_R0);

void setup() {
  display.begin();
}

void loop() {
  display.clearBuffer();
  display.setFont(u8g2_font_ncenB08_tr);
  display.drawStr(10,30,"HELLO");
  display.sendBuffer();
  delay(1000);
}