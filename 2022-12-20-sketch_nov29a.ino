int redLed = 8;
// int greenLed = 11;
int buzzer = 10;
int smokeA0 = A5;
// Your threshold value

int sensorThresVLow = 300;
int sensorThresLow = 1200;
int sensorThresMid = 2000;
int sensorThresHig = 5001;


int sensorThres = 150;

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
/*
  if (analogSensor > sensorThres)
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
  delay(100);
}
*/
  switch(analogSensor)
  {
    case (analogSensor>sensorThresHig)
      digitalWrite(redLed, HIGH);
      tone(buzzer, 1000, 200);
    case (analogSensor>sensorThresMid)
      digitalWrite(redLed, HIGH);
      tone(buzzer, 1000, 200);
      delay(250);
      digitalWrite(redLed, LOW);
      noTone(buzzer);
      delay(250);
    case (analogSensor>sensorThresLow)
      digitalWrite(redLed, HIGH);
      tone(buzzer, 1000, 200);
      delay(500);
      digitalWrite(redLed, LOW);
      noTone(buzzer);
      delay(500);
    case (analogSensor>sensorThresVLow)
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
