
void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT); 
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT); 

}

void loop() {
    int state = 1;
    switch (state){
    case 1:
      digitalWrite(5, HIGH);
      delay(1000);
      digitalWrite(5, LOW);
    case 2:
      digitalWrite(6, HIGH);
      delay(1000);
      digitalWrite(6, LOW);
    case 3:
      digitalWrite(7, HIGH);
      delay(1000);
      digitalWrite(7, LOW);
    default:
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(1000);
    }

}
