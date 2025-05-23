#define trigPin 9
#define echoPin 10

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  float distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Water Distance: ");
  Serial.print(distance);
  Serial.print(" cm\t");

  if (distance < 10) {
    Serial.println("⚠️ HIGH Water Level!");
  } else if (distance < 20) {
    Serial.println("⚠️ MEDIUM Water Level.");
  } else {
    Serial.println("✅ LOW Water Level.");
  }

  delay(1000);
}
