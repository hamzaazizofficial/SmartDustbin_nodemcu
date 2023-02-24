#include <Servo.h> // servo library  
Servo s1;  

const int trigPin = 12;
const int echoPin = 14;
const int ledPin = 5;

//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(9600); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(ledPin, OUTPUT);
  s1.attach(0);  // servo attach D3 pin of arduino  
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;

  if(distanceCm < 20){
    Serial.println("Dustbin Open");
    digitalWrite(ledPin, HIGH);
    s1.write(0); 
    delay(1000);
  } else {

    Serial.println("Dustbin Close");
    digitalWrite(ledPin, LOW);
    s1.write(180);
  }
}
