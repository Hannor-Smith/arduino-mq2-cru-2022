int redLed = 8;
// int greenLed = 11;
int buzzer = 10;
int smokeA0 = A5;
// Your threshold value
// int sensorThres = 2500;

void setup() {
  pinMode(redLed, OUTPUT);
//  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
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
  else if (analogSensor < 400 && analogSensor >= 100)
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
