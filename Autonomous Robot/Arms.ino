int armDown(){ 
  for(pos = 10; pos < 125; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    ArmServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  nextInstruction();
}

int grabberClose(){
  for(pos = 90; pos >= 50; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    GrabberServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(30);                       // waits 15ms for the servo to reach the position 
  } 
  nextInstruction();
}

int armUp(){
  for(pos = 125; pos > 10; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    ArmServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(20);                       // waits 15ms for the servo to reach the position 
  } 
  nextInstruction();
}

int grabberOpen(){
  for(pos = 50; pos < 90; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    GrabberServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(30);                       // waits 15ms for the servo to reach the position 
  } 
  nextInstruction();
}

int nextInstruction(){
  instruction ++;
  startTime = time;
}

