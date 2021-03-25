#include <Servo.h>
//#include "Adafruit_VL53L0X.h"

const int dirPin = 4;
const int stepPin = 3;

int m;

const int delayy = 1000;

//Adafruit_VL53L0X lox = Adafruit_VL53L0X();

Servo servo1;
const int servoPin = 9;

String pos = "123.345,1.23\n";

void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);

  servo1.attach(servoPin);

  //if(!lox.begin()){
    //Serial.println(F("Failed to boot VL53L0X"));
  //}
  Serial.begin(9600);
}

void loop() {
  double* data;
  data[0] = 5;
  data[1] = 60;
  
  int state = 2;
  switch(state){
    case(0):
      while(data == NULL){
        data = receiveData();
      }
      state = 1;
      break;

    case(1):
      //convert cm to steps
      m = abs(int(100 * data[0]));
      if(data[0] < 0){
        moveStep(m,0);
        moveStep(m,1);
      }
      else{
        moveStep(m,1);
        moveStep(m,0);
      }
      state = 2;
      break;

    case(2):
      //rotate camera
      moveCamera(data[1]);
      state = 0;
      break;

    default:
      state = 0;
      
  }
  
}

double* receiveData(){
  if(Serial.available() > 0){
    pos = Serial.readStringUntil('\n');
  }
  String xpos;
  String angle;
  int c = 0;
  for(int i = 0; i < pos.length()-2; i++){
    if(pos[i] != ',' and c == 0){
      xpos += pos[i];
    }
    else if(pos[i] != ',' and c == 1){
      angle += pos[i];
    }
  }

  double data[2] = {xpos.toFloat(),angle.toFloat()};
  return data;
}

void moveStep(int s, int dir){
  if(dir == 0){
    digitalWrite(dirPin, HIGH);
  }
  else{
    digitalWrite(dirPin, LOW);
  }
  // Enables the motor to move in a particular direction
  // Makes 400 pulses for making one full cycle rotation
  for(int x = 0; x < s; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(delayy); 
    digitalWrite(stepPin,LOW);
    delayMicroseconds(delayy); 
  }
}

void moveCamera(int angle){
  servo1.write(angle);
}
