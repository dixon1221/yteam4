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
   if (Serial.available() > 0) {
    IncomingVal = Serial.read();
    Serial.print(IncomingVal);
    Serial.println("\n");
    do {
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);

      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
    } while (IncomingVal == 1);

    do {
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);
    } while (IncomingVal == 2);

    do {
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);
    } while (IncomingVal == 3);

    do {
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);

      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
    } while (IncomingVal == 4);
   }
}

 
