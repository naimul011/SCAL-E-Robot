#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <Wire.h>

SoftwareSerial Bluetooth(0, 1);
char Data;
void sendData(String transmitData){
Bluetooth.println(transmitData);}
const int trigPin = 8;
const int echoPin = 9;
const int laser = 10;
// defining variables
long duration;
int distance;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position
/*
  SoftwareSerial Bluetooth(0, 1);
  char Data;
  void sendData(String transmitData){
  Bluetooth.println(transmitData);}
*/

int input1 = 3; // Arduino'nun 3. digital pinine bağlanmıştır.
int input2 = 4; // Arduino'nun 4. digital pinine bağlanmıştır.
int input3 = 5; // Arduino'nun 5. digital pinine bağlanmıştır.
int input4 = 6; // Arduino'nun 6. digital pinine bağlanmıştır.



void setup() {
  Bluetooth.begin(9600);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(laser,OUTPUT);
  myservo.attach(11);
  Serial.begin(9600); // Starts the serial communication
 
  //Motorları sürmek için input pinleri çıkış olarak ayarlandı.
  //Motors have been set up to drive the input to the output pins.
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);

}

void moveForward() {
  //MOtorlar İleri //forward
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  digitalWrite(input4, LOW);
  digitalWrite(input3, HIGH);

}

void turnRight() {
  //MOtorlar İleri //forward
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);

  digitalWrite(input4, LOW);
  digitalWrite(input3, HIGH);

}

void turnLeft() {
  //MOtorlar İleri //forward
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);

  digitalWrite(input4, LOW);
  digitalWrite(input3, LOW);

}

void stopMovement() {
  //  Motorlar DURSUN // stop
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  digitalWrite(input3, LOW);
  digitalWrite(input4, LOW);


}

void moveBackward() {
  //Motorlar Geri // back
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  digitalWrite(input4, HIGH);
  digitalWrite(input3, LOW);
}

void setToInitialPos() {
  pos = 90;
  myservo.write(pos);              // tell servo to go to position in variable 'pos'
  delay(15);
}

void turnServoLeft() {
  pos += 1;
  if(pos>180) pos = 180;
  myservo.write(pos);              // tell servo to go to position in variable 'pos'
  delay(15);
}

void turnServoRight() {
  pos -= 1;

  if(pos < 0) pos = 0;
  myservo.write(pos);              // tell servo to go to position in variable 'pos'
  delay(15);
}

void loop() {// Clears the trigPin
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  // Sets the trigPin on HIGH state for 10 micro seconds
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  // Reads the echoPin, returns the sound wave travel time in microseconds
//  duration = pulseIn(echoPin, HIGH);
//  // Calculating the distance
//  distance = duration * 0.034 / 2;
//  // Prints the distance on the Serial Monitor
//  Serial.print("Distance: ");
//  Serial.println(distance);
//
//  
//  digitalWrite(trigPin, LOW);
//  turnRight();
//  delay(1000);
//
//  stopMovement();
//  delay(5000);
  
    if(Bluetooth.available()){
        Data=Bluetooth.read();
        if(Data==('1')){
            digitalWrite(laser, HIGH);
            turnServoRight();
            sendData("Moving forward");
            //Data = 'a';
        }
        if(Data==('0')){
            digitalWrite(laser, LOW);
            turnServoLeft();
            sendData("Moving stopped");
            //Data = 'a';
        }
        
    }
  

}
