// defines pins numbers
const int stepPin = 3; 
const int dirPin = 4; 
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int state = 0;
  while(true){
    // State-machine
    switch(state){
      
      // Idle - wait for position and camera-angle
      case (0):
        //Read serial
        break;
        
      // Positioning - move to position
      case (1):
        //convert length to number of steps and direction
        bool dir = true;
        int steps = 0;
        step(steps, true, 1000);
        break;
        
      // Camera
      case (2):
        break;
        
      // Calib
      case (3):
        break;
  
      default:
        state = NULL;
        break;
    }
    if (state == NULL) break;
  }
}

void step(int s, bool dir, int d){
  // INPUT
  //  s - number of pulses
  //  dir - direction of pulses
  //  d - delay / 2 between  pulses
  if(dir){
    digitalWrite(dirPin,HIGH);
  }
  else{
    digitalWrite(dirPin,LOW);
  }
  for(int x = 0; x < s; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(d); 
    digitalWrite(stepPin,LOW);
    delayMicroseconds(d); 
  }
}
  
