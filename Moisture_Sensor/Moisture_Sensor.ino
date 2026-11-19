#include <Servo.h>
#include <LiquidCrystal.h>

Servo myServo;
const int rs = 2;
const int en = 3;
const int digi4 = 4;
const int digi5 = 5;
const int digi6 = 6;
const int digi7 = 7;
LiquidCrystal lcd(rs, en, digi4, digi5, digi6, digi7);

#define BUZZER_PIN 9
#define NOTE_E5 200
#define NOTE_F5 600
#define NOTE_G5 800

const int servoPin = 10;
const int sensorPin = A0;
const int melody = NOTE_E5;
const int melody2 = NOTE_F5;
const int melody3 = NOTE_G5;

bool hasSounded1 = false;
bool hasSounded2 = false;
bool hasSounded3 = false;

byte waterDrop[8] = {
  B00100,
  B00100,
  B01110,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110
};

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

   
  lcd.begin(16, 2);
  lcd.createChar(0, waterDrop);

  myServo.attach(servoPin);
  
  
}

void superexhaustBlink() {
 
    digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(500);
    digitalWrite(13, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(11, HIGH);
   delay(500);
   digitalWrite(13, LOW);
   digitalWrite(12, LOW);
   digitalWrite(11, LOW);
}
void hyperexhaustBlink() {
  tone(BUZZER_PIN, melody, 500);
    
  
    digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(200);
    digitalWrite(13, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(11, HIGH);
   delay(200);
   digitalWrite(13, LOW);
   digitalWrite(12, LOW);
   digitalWrite(11, LOW);
}


void loop() {



  int inicialMoisture = analogRead(sensorPin);
  int inicialAngle = map(inicialMoisture, 1023, 0, 0,
   180);
  int moistDisplay = map(inicialMoisture, 1023, 0, 0, 100);
  myServo.write(inicialAngle);
 
  lcd.setCursor(0, 0);

  lcd.write((uint8_t)0);
  lcd.print("Humedad:");
  lcd.setCursor(12, 0);
  lcd.print(moistDisplay);
  lcd.print("%"); 
  int moisture = analogRead(sensorPin);
  Serial.println(moisture); 

  int servoAngle = map(moisture, 1023, 0, 0, 180);
  myServo.write(servoAngle);

  
  
  
  if (moisture > 683) { 
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  
    if (moisture >= 995 && moisture <= 1010 && !hasSounded1) {
      tone(BUZZER_PIN, melody, 500);
      hasSounded1 = true;
    }
    hasSounded2 = false;
    hasSounded3 = false;
  }
  else if (moisture <= 683 && moisture > 341) { 
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    
    if (moisture >= 690 && moisture <= 684 && !hasSounded2) {
      tone(BUZZER_PIN, melody2, 500);
      hasSounded2 = true;
    }
    hasSounded1 = false;
    hasSounded3 = false;
  } 
  else { 
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    
    if (moisture >= 67 && moisture <= 0 && !hasSounded3) {
      tone(BUZZER_PIN, melody3, 500);
      hasSounded3 = true;
    }
    hasSounded1 = false;
    hasSounded2 = false;
  }

 if (moisture < 200){
    superexhaustBlink();
 }
 if (moisture < 95){
    hyperexhaustBlink();
 }

  if (moisture <= 341) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  delay(500);
    }
