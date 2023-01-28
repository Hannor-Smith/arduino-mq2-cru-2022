#include <TM1637Display.h>
int redLed = 8;
int buzzer = 10;
int smokeA0 = A5;
int CLK = 9;
int DIO = 13;
int GND2 = 5;
TM1637Display display = TM1637Display(CLK, DIO);

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(GND2,OUTPUT); //define a digital pin as output
  digitalWrite(GND2, LOW);
  display.clear();
  display.setBrightness(7); // set the brightness to 7 (0:dimmest, 7:brightest)
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  display.showNumberDec(analogSensor); 
  if (analogSensor >= 2000)
  {
    digitalWrite(redLed, HIGH);
    tone(buzzer, 1000, 200);
  }
  else if (analogSensor < 2000 && analogSensor >= 1200)
  {
    digitalWrite(redLed, HIGH);
    tone(buzzer, 1000, 200);
    delay(200);
    digitalWrite(redLed, LOW);
    noTone(buzzer);
    delay(200);
  }
  else if (analogSensor < 1200 && analogSensor >= 400)
  {
    digitalWrite(redLed, HIGH);
    tone(buzzer, 1000, 200);
    delay(500);
    digitalWrite(redLed, LOW);
    noTone(buzzer);
    delay(500);
  }
  else if (analogSensor < 400 && analogSensor >= 200)
  {
    digitalWrite(redLed, HIGH);
    tone(buzzer, 1000, 200);
    delay(1000);
    digitalWrite(redLed, LOW);
    noTone(buzzer);
    delay(1000);
  }
  else
  {
    digitalWrite(redLed, LOW);
    noTone(buzzer);
  }
  delay(500);
}
