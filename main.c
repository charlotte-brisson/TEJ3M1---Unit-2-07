
#include <Servo.h>

Servo servoNumber1;
const int SERVO_CONTROL_PIN = 2;
const int TRIG_PIN = 10;
const int ECHO_PIN = 9;
long distance;
long duration;

void setup() {
  servoNumber1.attach(SERVO_CONTROL_PIN);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * 0.0343) / 2;
  
  Serial.print("Distance: ");  
  Serial.println(distance);  
  
  if (distance <= 50) {
    servoNumber1.write(90);
  } else {
    servoNumber1.write(0);
  }
    
  
  delay(3000);
}
		
