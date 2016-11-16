int printSerial(){
  time = millis()/((float)1000);
  Serial.print(time);
  Serial.print(" ");
  Serial.print(currentSideFront);
  Serial.print(" ");
  Serial.print(currentSideBack);
  Serial.print(" ");
  Serial.print(currentFront);
  Serial.print(" ");
  Serial.print(currentBack);
  Serial.print(" Ave: ");
  Serial.print(currentSideFrontAve);
  Serial.print(" ");
  
  Serial.print(" Ave: ");
  Serial.print(currentSideBackAve);
  Serial.print(" AAve: ");
  Serial.print(currentSideAve);
  Serial.print(" C1: ");
  Serial.print(correctionFactor);
  Serial.print(" C2: ");
  Serial.print(correctionFactor2);
  Serial.print(" ");
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" Instruction:");
  Serial.print(instruction);
  Serial.print(" ");
  Serial.println(turnAmount);
  Serial.print(" ");
  Serial.println(motorState);
  /*
  Serial.print("Hopper 1: (");
  Serial.print(hopper1x);
  Serial.print(", ");
  Serial.print(hopper1y);
  Serial.print(") Hopper 2: (");
  Serial.print(hopper2x);
  Serial.print(", ");
  Serial.print(hopper2y);
  Serial.print(")  Code:");
  
  Serial.print(instructionCode[0]);
  Serial.print(instructionCode[1]);
  Serial.print(instructionCode[2]);
  Serial.print(instructionCode[3]);
  Serial.print(instructionCode[4]);
  Serial.print(instructionCode[5]);
  Serial.println(instructionCode[6]);
  */
}

int printSerialDemo(){

  time = millis()/((float)1000);
}
