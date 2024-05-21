const int laserPin = 2;
const int ldrPin = A0;
const int buzzerPin = 3;

void setup() {
  pinMode(laserPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(laserPin, HIGH);
  delay(100);
  
  int ldrValue = analogRead(ldrPin);
  
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);
  
  if (ldrValue < 500) {
    Serial.println("Intruder detected! Activating alarm...");
    activateAlarm();
  }
  
  delay(500);
}

void activateAlarm() {
  digitalWrite(buzzerPin, HIGH);
  delay(2000);
  digitalWrite(buzzerPin, LOW);
}
