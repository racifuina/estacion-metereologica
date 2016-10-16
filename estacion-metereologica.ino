#include <LiquidCrystal.h>
#include <SimpleDHT.h>

int pinDHT11 = 2;
SimpleDHT11 dht11;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int analogPin = 0;
int soil_moisture = 0;
int led_pin = 13;

void setup() {
  lcd.begin(16, 2);
  pinMode(led_pin, OUTPUT);
  lcd.print(" >_   ESTACION");
  lcd.setCursor(0, 1);
  lcd.print(" METEREOLOGICA");
  delay(2000);
  digitalWrite(led_pin, LOW);
 }

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  soil_moisture = analogRead(analogPin);
  
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    return;
  }
  digitalWrite(led_pin, HIGH);
  delay(20);
  digitalWrite(led_pin, LOW);
  lcd.clear();
  lcd.print("   Temp:");
  lcd.setCursor(0, 1);
  lcd.print("Humedad:");
  lcd.setCursor(10, 0);
  lcd.print((int)temperature); 
  lcd.print(" *C");
  lcd.setCursor(10, 1);
  lcd.print((int)humidity); 
  lcd.print(" %");
  delay(5000);
  
  lcd.clear();
  digitalWrite(led_pin, HIGH);
  delay(20);
  digitalWrite(led_pin, LOW);
  
  lcd.print("   Info Suelo");
  if (soil_moisture < 300) {
    lcd.setCursor(0, 1);
    lcd.print("SECO ->   ");
    lcd.print(soil_moisture);
  } else if ((soil_moisture>300)&&(soil_moisture<700)) {
    lcd.setCursor(0, 1);
    lcd.print(" HUMEDO -> ");
    lcd.print(soil_moisture);
  } else if ((soil_moisture>700)&&(soil_moisture<950)) {
    lcd.setCursor(0, 1);
    lcd.print("MUY HUMEDO -> ");
    lcd.print(soil_moisture);
  } else {
    lcd.setCursor(0, 1);
    lcd.print("     ERROR");
    lcd.print(soil_moisture);
  }
  delay(5000);
  
}
