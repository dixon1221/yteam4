#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 4);
int enA = 6;
int enB = 7;
int motor1pin1 = 8;
int motor1pin2 = 2;

int motor2pin1 = 9;
int motor2pin2 = 5;
char IncomingVal = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  Serial.begin(38400);
  Serial.println("ready");
  mySerial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}