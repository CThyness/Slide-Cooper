/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
// defines pins numbers
const int stepPin = 3; 
const int dirPin = 4; 
 

void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  
}
void loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
    for(int x = 0; x < 1000; x++) {
    
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(1000); 
      digitalWrite(stepPin,LOW);
      delayMicroseconds(1000); 
    }
    delay(5000); 
}
  //delay(100); // One second delay
