

void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i <= 5; i++){
    pinMode(i, OUTPUT);
  }
}
int sig_1 = 2; //black
int sig_2 = 3; //green
int sig_3 = 4; //blue 
int sig_4 = 5; //red

  void Spole_1_stom(void){
  digitalWrite(sig_1, HIGH);
  digitalWrite(sig_2, LOW);
}
void Spole_2_stom(void){
  digitalWrite(sig_3, HIGH);
  digitalWrite(sig_4, LOW);
}

void Spole_1_inv_stom(void){
  digitalWrite(sig_1, LOW);
  digitalWrite(sig_2, HIGH);
}

void Spole_2_inv_stom(void){
  digitalWrite(sig_3, LOW);
  digitalWrite(sig_4, HIGH);
}

void All_GND(void){
  for(int i = 2; i <= 5; i++){
    digitalWrite(i, LOW);
  }
}
void loop() {
  All_GND();
  Spole_1_stom();
  delay(10);

  All_GND();
  Spole_2_stom();
  delay(10);
  
  All_GND();
  Spole_1_inv_stom();
  delay(10);

  All_GND();
  Spole_2_inv_stom();
  delay(10);
}
