#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN A0
#define DHTTYPE DHT11
#define MICPIN A1

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  dht.begin();
  lcd.begin(16, 2);
}

void loop() {
  delay(1000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int soundRaw = analogRead(MICPIN);
  int soundLevel = abs(soundRaw - 512);  // deviation from midpoint

  lcd.clear();

  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("C H:");
  lcd.print(humidity);

  lcd.setCursor(0, 1);
  lcd.print("S:");
  lcd.print(soundLevel);
}