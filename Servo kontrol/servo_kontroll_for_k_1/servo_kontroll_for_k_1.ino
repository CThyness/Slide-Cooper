// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 9; 
// Create a servo object 
Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
}
void loop(){ 
   // Make servo go to 0 degrees 
   for(double i=180; i>0; i-=0.05){
    Servo1.write(i);
    delay(1); 
   }

   for(double i=0; i<180; i+=0.05){
     Servo1.write(i);
     delay(1); 
   }
   delay(1000); 
   
}
