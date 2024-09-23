#define BUZZER 7

void setup() {
  Serial.begin(9600);
  pinMode(A5, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void ledBlink(int speed) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(speed);
  digitalWrite(LED_BUILTIN, LOW);
}

void soundAlert(int speed, int freq) {
  tone(BUZZER, freq);
  delay(speed);
  noTone(BUZZER);
}

void loop() {
  int sensorValue = analogRead(A5);
  Serial.println(sensorValue);
  if (sensorValue < 100) {
    ledBlink(100);
    soundAlert(100, 1000);
  }
}
