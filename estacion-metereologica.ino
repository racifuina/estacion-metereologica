#include <LiquidCrystal.h>
#include <SimpleDHT.h>

int pinDHT11 = 2;
SimpleDHT11 dht11;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);
  lcd.print(" >_   ESTACION");
  lcd.setCursor(0, 1);
  lcd.print(" METEREOLOGICA");
  delay(2000);
  lcd.clear();
  lcd.print("   Temp:");
  lcd.setCursor(0, 1);
  lcd.print("Humedad:");
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    return;
  }
  lcd.setCursor(10, 0);
  lcd.print((int)temperature); 
  lcd.print(" *C");
  lcd.setCursor(10, 1);
  lcd.print((int)humidity); 
  lcd.print(" %");
  delay(1000);
}
