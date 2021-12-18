#include <Servo.h>

// constants won't change
const int sensorpin = 7; // Arduino pin connected to touch sensor's pin
const int motorpin  = 9; // Arduino pin connected to servo motor's pin
int pos;

Servo Myservo; // create servo object to control a servo

int lastTouchState;    // the previous state of touch sensor
int currentTouchState; // the current state of touch sensor

void setup() {
  Serial.begin(9600);               // initialize serial
  pinMode(sensorpin, INPUT); // set arduino pin to input mode
  Myservo.attach(motorpin);          // attaches the servo on pin 9 to the servo object

}

void loop() {
  lastTouchState    = currentTouchState;             // save the last state
  currentTouchState = digitalRead(sensorpin); // read new state

  if(lastTouchState == LOW && currentTouchState == HIGH) {
    Serial.println("gate opening");
    for(pos=0;pos<=90;pos++){
        Myservo.write(pos);
        delay(250);
    }
  }
  

}
