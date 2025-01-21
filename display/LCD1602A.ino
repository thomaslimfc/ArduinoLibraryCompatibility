// GND - GND
// VCC - 5V
// SDA - A4
// SCL - A5

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Update address and size as needed

void setup() {
  lcd.init();
  delay(100);
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0); // Line 1
  lcd.print("THOMAS COMONICS");

  lcd.setCursor(0, 1); // Line 2
  lcd.print("TECHNOLOGY");
}

void loop() {}
