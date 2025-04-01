
#include <servo.h>
Servo servoNumber1;
const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
   servoNumber1.attach(2);
  servoNumber1.write(0);
}
servoNumber1;
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
    // put your main code here, to run repeatedly
  servoNumber1.write(90);
  delay(1000);
  servoNumber1.write(0);
  delay(1000);
}
