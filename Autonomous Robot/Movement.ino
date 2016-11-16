int motorStateFunction(float correctionFactor){
  int left1, right1, left2, right2;

/*
  if(correctionFactor == 0){left1 = 150; right1 = 10; left2 = 10; right2 = 150;}
  if(correctionFactor2 == 0){left1 = 150; right1 = 10; left2 = 10; right2 = 150;}
  if(correctionFactor3 == 0){left1 = 150; right1 = 10; left2 = 10; right2 = 150;}
  if(correctionFactor == 1){left1 = 121; right1 = 10; left2 = 10; right2 = 118;}
  if(correctionFactor == -1){left1 = 150; right1 = 63; left2 = 67; right2 = 150;}
  if(correctionFactor2 == 1){left1 = 121; right1 = 10; left2 = 70; right2 = 150;}
  if(correctionFactor2 == -1){left1 = 150; right1 = 63; left2 = 10; right2 = 118;}
  if(correctionFactor3 == 1){left1 = 102; right1 = 0; left2 = 84; right2 = 180;}
  */

  if(correctionFactor == 0){left1 = 150; right1 = 10; left2 = 10; right2 = 150;}
  if(correctionFactor2 == 0){left1 = 150; right1 = 10; left2 = 10; right2 = 150;}
  if(correctionFactor3 == 0){left1 = 150; right1 = 10; left2 = 10; right2 = 150;}
  if(correctionFactor == 1){left1 = 115; right1 = 10; left2 = 10; right2 = 114;}
  if(correctionFactor == -1){left1 = 150; right1 = 70; left2 = 67; right2 = 150;}
  if(correctionFactor2 == 1){left1 = 121; right1 = 10; left2 = 70; right2 = 150;}
  if(correctionFactor2 == -1){left1 = 150; right1 = 70; left2 = 10; right2 = 118;}
  if(correctionFactor3 == 1){left1 = 102; right1 = 0; left2 = 84; right2 = 180;}
  if(motorState == 0){ // Stop Moving
    rightMotor.write(90);
    leftMotor.write(90);
  }
  else if(motorState == 1){ // Go forward
    rightMotor.write(right1);
    leftMotor.write(left1);
  }
  else if(motorState == 2){ // Go Backwards
    rightMotor.write(right2);
    leftMotor.write(left2);
  }
  else if(motorState == 3){ // Turn Right
    rightMotor.write(180);
    leftMotor.write(180);
  }    
  else if(motorState == 4){ // Turn Left
    rightMotor.write(0);
    leftMotor.write(0);
  }
  else if(motorState == 5){
    rightMotor.write(110);
    leftMotor.write(110);
  }
  else if(motorState == 6){
    rightMotor.write(70);
    leftMotor.write(70);
  }
}

int adjust(float turnAmount){
   if(turnAmount < 0){motorState = 6;}
   else if(turnAmount > 0){motorState = 5;}
  if(time - startTime > abs(turnAmount/10.8)){
    instruction ++;
    startTime = time;
    motorState = 0;
  }
}

int halfTurnLeft(float turntime){
  motorState = 4;
  if(time - startTime > turntime/3){
    instruction ++;
    startTime = time;
    motorState = 0;
  }
}

int halfTurnRight(float turntime){
  motorState = 3;
  if(time - startTime > turntime/1.02/3){
    instruction ++;
    startTime = time;
    motorState = 0;
  }
}

int turnLeft(float turntime){
  motorState = 4;
  if(time - startTime > turntime/1.01){
    instruction ++;
    startTime = time;
    motorState = 0;
  }
}

int perfectLeft(float turntime){
  motorState = 1;
  correctionFactor3 = 1;
  if(time - startTime > 2.85*turntime){
    instruction ++;
    startTime = time;
    motorState = 0;
    correctionFactor3 = 0;
  } 
}

int perfectRight(float turntime){
  motorState = 2;
  correctionFactor3 = 1;
  if(time - startTime > 2.85*turntime){
    instruction ++;
    startTime = time;
    motorState = 0;
    correctionFactor3 = 0;
  } 
}

int turnRight(float turntime){
  motorState = 3;
  if(time - startTime > turntime){
    instruction ++;
    startTime = time;
    motorState = 0;
  }
}

int turn(){
  motorState = 4;
  if(time - startTime > 0.9){
    instruction ++;
    startTime = time;
    motorState = 0;
  }
}

int stopMoving(float stopTime){
  motorState = 0; 
  if(time - startTime > stopTime){
    instruction ++;
    startTime = time;
  }
}

int straight(float timemax){
  PIDenabled = 1;
  motorState = 1;
  if(time - startTime > (float)timemax/timeconstant){
    instruction++;
    startTime = time;
    motorState = 0;
  }
}

int straight3(float timemax, float rightDistance){
  PIDenabled = 1;
  motorState = 1;
  if(rightDistance - currentSideAve < 0.8 && rightDistance - currentSideAve > -0.8){correctionFactor2 = 0;};
  if(rightDistance - currentSideAve > 0.8){correctionFactor2 = 1;}
  if(rightDistance - currentSideAve < -0.8){correctionFactor2 = -1;}
  if(abs(currentSideFront - currentSideBack) > 5){correctionFactor2 = 0;}
  if(time - startTime > (float)timemax/timeconstant){
    instruction++;
    startTime = time;
    motorState = 0;
  }
}

int straight2(float timemax){
  PIDenabled = 0;
  motorState = 1;
  correctionFactor = 0;
  if(time - startTime > (float)timemax/timeconstant){
    instruction++;
    startTime = time;
    motorState = 0;
  }
}

int backwards(float timemax){  
  PIDenabled = 1;
  motorState = 2;
  if(time - startTime > (float)timemax/timeconstant){
    instruction++;
    startTime = time;
    motorState = 0;
  }
}

int backwards2(float timemax){  
  PIDenabled = 0;
  motorState = 2;
  if(time - startTime > (float)timemax/timeconstant){
    instruction++;
    startTime = time;
    motorState = 0;
  }
}

int backwards3(float timemax, float rightDistance){
  PIDenabled = 1;
  motorState = 2;
  if(rightDistance - currentSideAve < 0.8 && rightDistance - currentSideAve > -0.8){correctionFactor2 = 0;};
  if(rightDistance - currentSideAve > 0.8){correctionFactor2 = 1;}
  if(rightDistance - currentSideAve < -0.8){correctionFactor2 = -1;}
  if(abs(currentSideFront - currentSideBack) > 7){correctionFactor2 = 0;}
  if(time - startTime > (float)timemax/timeconstant){
    instruction++;
    startTime = time;
    motorState = 0;
  }
}

int selfLocalization(float FrontDistance, float RightDistance){
  switch(heading){
      case North:       x = 160 - RightDistance; y = 180 - FrontDistance;        break;
      case South:       x = RightDistance; y = FrontDistance;        break;
      case West:        x = FrontDistance; y = 180 - RightDistance;        break;
      case East:        x = 160 - RightDistance; y = FrontDistance;        break;
  }
}

