
int rotaryEncoderLeft = 2;
int rotaryEncoderRight = 3;
int countLeft;
int countRight;
int num;
int blackLeft;
int blackRight;
int blackLeft2;
int blackRight2;
int numberOfTurnsLeft;
int numberOfTurnsRight;
int revolutionCountLeft;
int revolutionCountRight;

void setup() {
  Serial.begin(9600);
  pinMode(rotaryEncoderLeft, INPUT);
  pinMode(rotaryEncoderRight, INPUT);
}

void loop() {
  int stateLeft = digitalRead(rotaryEncoderLeft);
  int stateRight = digitalRead(rotaryEncoderRight);
  Serial.print(stateLeft);
  Serial.println(stateRight);
  
}



