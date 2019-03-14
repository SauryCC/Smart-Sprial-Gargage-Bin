#include <LiquidCrystalFast.h>
#define trigPin A1
#define echoPin A0
#define fullAlart A2
#define setHigh1 39
#define setHigh2 41
#define setHigh3 43
#define setLow1 A12
#define setLow2 A13
#define setLow3 A14
#define setLow4 A15

LiquidCrystalFast lcd(12, 8, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(fullAlart, OUTPUT);
  pinMode(setHigh1, OUTPUT);
  pinMode(setHigh2, OUTPUT);
  pinMode(setHigh3, OUTPUT);
  pinMode(setLow1, OUTPUT);
  pinMode(setLow2, OUTPUT);
  pinMode(setLow3, OUTPUT);
  pinMode(setLow4, OUTPUT);

  digitalWrite(setHigh1, HIGH);
  digitalWrite(setHigh2, HIGH);
  digitalWrite(setHigh3, HIGH);
  digitalWrite(setLow1, LOW);
  digitalWrite(setLow2, LOW);
  digitalWrite(setLow3, LOW);
  digitalWrite(setLow4, LOW);

  

}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 40 || distance <= 2){
    lcd.setCursor(0, 0);
    lcd.print("Out of range");
    digitalWrite(fullAlart, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Lid error");
    delay(500);
  }
  else if (distance <10){
    lcd.setCursor(0, 0);
    lcd.print("Battery: 64%");
    lcd.setCursor(0, 1);
    lcd.print("Full  ");
    lcd.print(distance);
    lcd.print(" cm");
    digitalWrite(fullAlart, HIGH);
    delay(500);
    
  }
  else if (distance >20){
    lcd.setCursor(0, 0);
    lcd.print("Battery: 64%");
    lcd.setCursor(0, 1);
    lcd.print("Empty  ");
    lcd.print(distance);
    lcd.print(" cm");
    digitalWrite(fullAlart, LOW);
    delay(500);
  }
  else if (distance >10 && distance <= 20){
    lcd.setCursor(0, 0);
    lcd.print("Battery: 64%");
    lcd.setCursor(0, 1);
    lcd.print("Medium  ");
    lcd.print(distance);
    lcd.print(" cm");
     digitalWrite(fullAlart, LOW);
    delay(500);
  }
  
  
  
  delay(800);
  lcd.clear();
}
