int chooseColumn(int columnNumber){
  float columnDistance[8] = {0.5, 5.6, 10.7, 15.8, 20.9, 26.0, 31.1, 36.2};
  if(columnDistance[columnNumber - 1] < currentGameboard){
    clampState = 1;
  }
  else if(columnDistance[columnNumber] > currentGameboard){
    clampState = 2;
  }
  else {clampState = 0;}
}

int clampFunction(){
  if(clampState == 0){
    digitalWrite(boardMotorRotationEnablePin, LOW);
  }
  else if(clampState == 1){
    digitalWrite(boardMotorRotationPin1, LOW);
    digitalWrite(boardMotorRotationPin2, HIGH);
  }
  else if(clampState == 2){
    digitalWrite(boardMotorRotationPin1, HIGH);
    digitalWrite(boardMotorRotationPin2, LOW);
  }
}
