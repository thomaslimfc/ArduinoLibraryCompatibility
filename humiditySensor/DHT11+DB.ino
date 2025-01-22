// DHT_sensor_library-1.4.6
// Adafruit Unified Sensor

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Define the DHT sensor type and pin
#define DHTPIN 2      // Pin where the DHT sensor is connected
#define DHTTYPE DHT11 // Define sensor type (DHT11)

// Initialize the DHT sensor and LCD
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Update address and size as needed

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Display a startup message
  lcd.setCursor(0, 0); // Line 1
  lcd.print("THOMAS COMONICS");
  lcd.setCursor(0, 1); // Line 2
  lcd.print("TECHNOLOGY");
  delay(2000); // Wait for 2 seconds

  lcd.clear();

  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Read temperature and humidity values
  float humidity = dht.readHumidity();       // Read humidity
  float temperature = dht.readTemperature(); // Read temperature in Celsius

    if (!isnan(temperature) && !isnan(humidity)) {
        Serial.print(temperature);
        Serial.print(",");
        Serial.println(humidity);
    }

  // Check if the readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    lcd.setCursor(0, 1);
    lcd.print("Check DHT");
  } else {
    // Display temperature
    lcd.setCursor(0, 0); // Line 1
    lcd.print("Temp: ");
    lcd.print(temperature, 1); // Show 1 decimal place
    lcd.print((char)223);      // Degree symbol
    lcd.print("C");

    // Display humidity
    lcd.setCursor(0, 1); // Line 2
    lcd.print("Hum: ");
    lcd.print(humidity, 1); // Show 1 decimal place
    lcd.print("%");
  }

  delay(2000); // Update every 2 seconds
}




// CREATE TABLE sensor_data (
//     id INT AUTO_INCREMENT PRIMARY KEY,
//     temperature FLOAT NOT NULL,
//     humidity FLOAT NOT NULL,
//     timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
// );