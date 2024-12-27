// Using MQ2 sensor to read the hydrogen gas concentration
#include <LiquidCrystal.h>
#include <MQ2.h>
#define MINDELAY 50
#define MAXDELAY 1000
float hydrogenSensor = A1; // mq2 sensor
int redLed = 13;
int buzzer = 7;

// include the lcd display module
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

MQ2 mq2(hydrogenSensor);
// Set the sensor's threshold value
float sensorThresh = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // begin serial communication
  mq2.begin();
  while(!Serial)
  {
    ;
  }
  pinMode(hydrogenSensor, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.print("Begin sensor's reading");
  Serial.println("...");
  Serial.println();

  lcd.begin(16,2);

  digitalWrite(redLed, HIGH);
  delay(MINDELAY);
  digitalWrite(redLed, LOW);
  digitalWrite(buzzer, HIGH);
  delay(MINDELAY);
  digitalWrite(buzzer, LOW);

  lcd.print("Welcome");
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
   float hydrogenGas = mq2.readLPG();
  Serial.print("The sensor's value is: ");
  Serial.println(hydrogenGas);
  lcd.setCursor(1,0);
  lcd.print("LPG output: ");
  lcd.print(hydrogenGas);
  // Let's start taking the data 
    if (hydrogenGas > sensorThresh)
    {
      digitalWrite(buzzer, HIGH);
      delay(MAXDELAY);
      digitalWrite(buzzer, LOW);
      digitalWrite(redLed, HIGH);
    }
    else
    {
      Serial.println("No sensor reading");
      Serial.println("...");
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Danger!!!");
    }
}
