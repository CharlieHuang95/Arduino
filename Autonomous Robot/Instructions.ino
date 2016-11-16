int readInstruction(){
  instructionCode[0] = readPad();
  delay(100);
  instructionCode[1] = readPad();
  delay(100);
  instructionCode[2] = readPad();
  delay(100);
  instructionCode[3] = readPad();
  delay(100);
  instructionCode[4] = readPad();
  delay(100);
  instructionCode[5] = readPad();
  delay(100);  
  instructionCode[6] = readPad();
  delay(100);
  instructionCode[7] = readPad();
  delay(100);
}

int instructionFunction(){ 
  if(instructionCode[0] == 'A' && instructionCode[1] == 'A'){
    switch(instruction){
      case 0:  // Move to the Connect4 board
        motorState = 0;
        if(time > 5){
          instruction ++;
          startTime = time;
        }
        break;
      case 1:    straight2(15); if(currentBack > 12 && currentBack != 0 && currentBack < 180){nextInstruction();} break;
      case 2:    turnRight(light);          break;   
      case 3:    stopMoving(1.5);           break;
      case 4:    straight2(60); if(currentFront < 23 && currentFront > 14 && currentFront != 0 && currentFront < 180){nextInstruction();} break;
      case 5:    halfTurnRight(light*1.5);  break;
      case 6:    backwards(1);              break;
      case 7:    armDown();                 break;
      case 8:    stopMoving(1.5);           break;
      case 9:    straight2(15);             break;
      case 10:    stopMoving(0.5);           break;
      case 11:    grabberClose();            break;
      case 12:   stopMoving(2);             break;
      case 13:    backwards2(8);           break;
      case 14:    stopMoving(0.5);          break;
      case 15:    armUp();                  break;
      case 16:    stopMoving(1);          break;
      case 17:    halfTurnLeft(light*1.5);  break;
      case 18:    backwards2(4);             break;
      case 19:    perfectLeft(light);       break;
      case 20:    stopMoving(1.5);     break;
      case 21:    adjust(turnAmount);            break;
      case 22:    straight3(200, 9);  if(currentFront < 36 && currentFront > 26 && currentFront != 0 && currentFront < 180){nextInstruction();} break;
      case 23:    perfectLeft(light);       break;
      case 24:    stopMoving(0.5);     break;
      case 25:    straight3(200, 8);  if((currentBack > 70 || currentFront < 15) && currentBack != 0 && currentBack < 180){nextInstruction();} break; //Remove
      case 26:    turnLeft(light);          break;
      case 27:    backwards(20);  if(currentBack < 5 && currentBack != 0 && currentBack < 180){nextInstruction();}    break;
      case 28:    backwards(3);             break;
      case 29:    stopMoving(0.5);          break;
      case 30:    grabberOpen();            break;
      case 31:    stopMoving(3);            break;
      case 32:    straight2(20);  if(currentBack > 14 && currentBack != 0 && currentBack < 180){nextInstruction();}   break;
      case 33:    turnRight(light);          break;
      case 34:    instructionCode[0] = instructionCode[6]; instructionCode[1] = '1'; instruction = 0; break;
    }
  }
  if(instructionCode[0] == '1' && instructionCode[1] == '1'){
    switch(instruction){
      case 0:    stopMoving(0.5);    break;
      case 1:    straight2(200); if(currentFront < (hopper1x - 17 - correctionDistance1x) && currentFront != 0 && currentFront < 180){nextInstruction();} break;
      case 2:    stopMoving(1.5);      break;
      case 3:    adjust(turnAmount);  break;
      case 4:    stopMoving(1);      break;
      case 5:    turnLeft(light);    break;
      case 6:    straight2(180 - hopper1y - 22); if(currentBack > (180 - 55 - hopper1y + correctionDistance1y) && currentBack != 0 && currentBack < 180){nextInstruction();} break;
      case 7:    instructionCode[0] = '1'; instructionCode[1] = '2'; instruction = 0; break;
    }
  }
  if(instructionCode[0] == '1' && instructionCode[1] == '2'){
    switch(instruction){
      case 0:    stopMoving(0.5);    break;
      case 1:    if(approach1 == 0){instruction = 4; startTime = time;} 
                 if(approach1 == -1){instruction++; startTime = time;}     break;
      case 2:    halfTurnLeft(light);    break;
      case 3:    stopMoving(0.5);      break;
      case 4:    armDown();                 break;
      case 5:    stopMoving(1.5);           break;
      case 6:    straight2(15);             break;
      case 7:    stopMoving(0.5);           break;
      case 8:    grabberClose();            break;
      case 9:   stopMoving(2);             break;
      case 10:    backwards2(8);           break;
      case 11:    stopMoving(0.5);          break;
      case 12:    armUp();                  break;
      case 13:    stopMoving(1);          break;
      case 14:    stopMoving(0.5); break;
      case 15:    if(approach1 == 0){instruction = 17; startTime = time;} 
                  if(approach1 == -1){instruction++; startTime = time;}     break;
      case 16:    halfTurnRight(light);      break;
      case 17:    stopMoving(0.5);      break;
      case 18:    instructionCode[0] = '1'; instructionCode[1] = '3'; instruction = 0; break;
    }
  }
  if(instructionCode[0] == '1' && instructionCode[1] == '3'){ // Hopper 1 Return
    switch(instruction){    
      case 0:    stopMoving(0.5);  break;
      case 1:    backwards2(200); if(currentBack < 18 && currentBack != 0 && currentFront < 180){nextInstruction();} break;
      case 2:    turnRight(light*1.05);    break;   
      case 3:    stopMoving(1);     break;
      case 4:    adjust(turnAmount);    break;
      case 5:    stopMoving(0.5);    break;
      case 6:    backwards3(200, 9); if((currentFront > 70 || currentBack < 15) && currentFront != 0){nextInstruction();} break; //Remove
      case 7:    turnLeft(light);          break;
      case 8:    backwards(20);  if(currentBack < 2 && currentBack != 0 && currentBack < 180){nextInstruction();}    break;
      case 9:    backwards(3);            break;
      case 10:    stopMoving(0.5);          break;
      case 11:    grabberOpen();            break;
      case 12:    stopMoving(3);            break;
      case 13:    straight2(20);  if(currentBack > 13 && currentBack != 0 && currentBack < 180){nextInstruction();}   break;
      case 14:    turnRight(light);          break;
      case 15:    ballsCollectedFromHopper++; instruction = 0;
      
                  if(ballsCollectedFromHopper == 7){ballsCollectedFromHopper = 0; instructionCode[0] = '2'; instructionCode[1] = '1';}
                  else {instructionCode[0] = '1'; instructionCode[1] = '1';}   break;
    }  
  }
  if(instructionCode[0] == '2' && instructionCode[1] == '1'){
    switch(instruction){
      case 0:    stopMoving(0.5);    break;
      case 1:    backwards2(10);      break;
      case 2:    backwards3(200, 15); if(currentBack < (180 - hopper2x - 37 + correctionDistance2x) && currentFront != 0 && currentFront < 180){nextInstruction();} break;
      case 3:    turnRight(light);    break;
      case 4:    backwards2(180 - hopper2y); if(currentBack > 13 + correctionDistance2y && currentFront != 0 && currentFront < 180){nextInstruction();} break;
      case 5:    instructionCode[0] = '1'; instructionCode[1] = '2'; instruction = 0; break;
    }
  }
  if(instructionCode[0] == '2' && instructionCode[1] == '2'){
    switch(instruction){
      case 0:    stopMoving(0.5);    break;
      case 1:    if(approach1 == 0){instruction = 4; startTime = time;} 
                 if(approach1 == -1){instruction++; startTime = time;}     break;
      case 2:    halfTurnRight(light);    break;
      case 3:    stopMoving(0.5);      break;
      case 4:    armDown();         break;
      case 5:    straight2(20);       break;
      case 6:    stopMoving(0.5);   break;
      case 7:    grabberClose();    break;
      case 8:    backwards2(9);      break;
      case 9:    stopMoving(0.5);   break;
      case 10:    armUp();        break;
      case 11:    stopMoving(0.5); break;
      case 12:    if(approach1 == 0){instruction = 15; startTime = time;} 
                  if(approach1 == -1){instruction++; startTime = time;}     break;
      case 13:    halfTurnLeft(light);      break;
      case 14:    stopMoving(0.5);      break;
      case 15:    instructionCode[0] = '2'; instructionCode[1] = '3'; instruction = 0; break;
    }
  }
  if(instructionCode[0] == '2' && instructionCode[1] == '3'){ // Hopper 2 Return
    switch(instruction){    
      case 0:    stopMoving(0.5);    break;
      case 1:    straight(200); if(currentFront < 15 && currentFront != 0 && currentFront < 180){nextInstruction();} break;
      case 2:    turnLeft(light);    break;   
      case 3:    stopMoving(0.5);     break;
      case 4:    straight3(200, 15); if(currentFront < 20 && currentFront != 0){nextInstruction();} break;
      case 5:    turnLeft(light);          break;
      case 6:    backwards(20);  if(currentBack < 5 && currentBack != 0 && currentBack < 180){nextInstruction();}    break;
      case 7:    stopMoving(0.5);          break;
      case 8:    grabberOpen();            break;
      case 9:    stopMoving(3);            break;
      case 10:    straight2(20);  if(currentBack > 10 && currentBack != 0 && currentBack < 180){nextInstruction();}   break;
      case 11:    turnRight(light);          break;
      case 12:    ballsCollectedFromHopper++; instruction = 0;
                 if(ballsCollectedFromHopper == 7){ballsCollectedFromHopper = 0; instructionCode[0] = '3'; instructionCode[1] = '1';}
                 else {instructionCode[0] = '2'; instructionCode[1] = '1';}   break;
    }  
  }
  if(instructionCode[0] == '3' && instructionCode[1] == '1'){ // Hopper 3 
    switch(instruction){    
      case 0:    stopMoving(0.5);    break;
      case 1:    straight3(200, 12); if(currentFront < 13 && currentFront != 0 && currentFront < 180){nextInstruction();} break;
      case 2:    turnLeft(light);    break; 
      case 3:    stopMoving(1);      break;
      case 4:    adjust(turnAmount);  break;
      case 5:    stopMoving(0.5);     break;
      case 6:    straight3(200, 9); if(currentFront < 80 && currentBack > 60 && currentFront != 0){nextInstruction();} break;
      case 7:    straight3(200, 15); if(currentFront < 24 && currentFront > 15 && currentFront != 0){nextInstruction();} break;
      case 8:    halfTurnRight(light*1.7);   break;
      case 9:    armDown();                 break;
      case 10:    stopMoving(1.5);           break;
      case 11:    straight2(15);             break;
      case 12:    stopMoving(0.5);           break;
      case 13:    grabberClose();            break;
      case 14:    stopMoving(2);             break;
      case 15:    backwards2(8);           break;
      case 16:    stopMoving(0.5);          break;
      case 17:    armUp();                  break;
      case 18:    stopMoving(1);          break;
      case 19:    halfTurnLeft(light*1.75);    break;
      case 20:    stopMoving(0.5);      break;
      case 21:    backwards3(200, 8); if(currentBack < 8 && currentBack != 0 && currentBack < 180){nextInstruction();} break;
      case 22:    stopMoving(1);      break;
      case 23:    adjust(turnAmount);      break;
      case 24:    turnRight(light);    break;   
      case 25:    stopMoving(0.5);     break;
      case 26:    backwards3(200, 9); if((currentFront > 70 || currentBack < 15) && currentFront != 0){nextInstruction();} break; //Remove
      case 27:    turnLeft(light);          break;
      case 28:    backwards(20);  if(currentBack < 2 && currentBack != 0 && currentBack < 180){nextInstruction();}    break;
      case 29:    backwards(3);            break;
      case 30:    stopMoving(0.5);          break;
      case 31:    grabberOpen();            break;
      case 32:    stopMoving(3);            break;
      case 33:    straight2(20);  if(currentBack > 13 && currentBack != 0 && currentBack < 180){nextInstruction();}   break;
      case 34:    turnRight(light);          break;
      case 35:    ballsCollectedFromHopper++; instruction = 0;
                 if(ballsCollectedFromHopper == 4){ballsCollectedFromHopper = 0; instructionCode[0] = '1'; instructionCode[1] = '1';}
                 else {instructionCode[0] = '3'; instructionCode[1] = '1';}   break;
    }  
  }
  if(instructionCode[0] == '4' && instructionCode[1] == '1'){ // Hopper 3 Return
    switch(instruction){    
      case 0:    stopMoving(0.5);    break;
      case 1:    backwards3(200, 15); if(currentBack < 8 && currentBack != 0 && currentBack < 180){nextInstruction();} break;
      case 2:    turnRight(light);    break;   
      case 3:    stopMoving(0.5);     break;
      case 4:    backwards3(200, 8); if(currentBack < 34 && currentBack != 0){nextInstruction();} break;
      case 5:    perfectRight(light);    break;
      case 6:    correctionFactor3 = 0; stopMoving(1);        break;
      case 7:    adjust(turnAmount);      break;
      case 8:    straight2(100); if(currentFront < 22 && currentFront != 0 && currentFront < 180){nextInstruction();}         break;
      case 9:    halfTurnRight(light*1.5);    break;
      case 10:    backwards(1);              break;
      case 11:    armDown();                 break;
      case 12:    stopMoving(1.5);           break;
      case 13:    straight2(15);             break;
      case 14:    stopMoving(0.5);           break;
      case 15:    grabberClose();            break;
      case 16:   stopMoving(2);             break;
      case 17:    backwards2(8);           break;
      case 18:    stopMoving(0.5);          break;
      case 19:    armUp();                  break;
      case 20:    stopMoving(1);          break;
      case 21:    halfTurnLeft(light*1.5);  break;
      case 22:    backwards2(4);             break;
      case 23:    perfectLeft(light);       break;
      case 24:    correctionFactor3 = 0; stopMoving(1);            break;
      case 25:    adjust(turnAmount);    break;
      case 26:    stopMoving(0.5);     break;
      case 27:    straight3(200, 9);  if(currentFront < 36 && currentFront != 0 && currentFront < 180){nextInstruction();} break;
      case 28:    perfectLeft(light);       break;
      case 29:    correctionFactor3 = 0; stopMoving(0.5);     break;
      case 30:    correctionFactor3 = 0; straight3(200, 9);  if((currentBack > 70 || currentFront < 15) && currentBack != 0 && currentBack < 180){nextInstruction();} break; //Remove
      case 31:    turnLeft(light);          break;
      case 32:    backwards2(20);  if(currentBack < 2 && currentBack != 0 && currentBack < 180){nextInstruction();}    break;
      case 33:    backwards2(3);        break;
      case 34:    stopMoving(0.5);          break;
      case 35:    grabberOpen();            break;
      case 36:    stopMoving(3);            break;
      case 37:    straight2(20);  if(currentBack > 13 && currentBack != 0 && currentBack < 180){nextInstruction();}   break;
      case 38:    turnRight(light);          break;      
      case 39:    ballsCollectedFromHopper++; instruction = 0;
                  if(ballsCollectedFromHopper == 2){ballsCollectedFromHopper = 0; instructionCode[0] = '3'; instructionCode[1] = '1';}
                  else {instructionCode[0] = '4'; instructionCode[1] = '1';}   break;
    }  
  }
  if(instructionCode[0] == '4' && instructionCode[1] == '2'){ // Hopper 3 Return
    switch(instruction){    
      case 0:    stopMoving(0.5);    break;
      case 1:    backwards3(200, 15); if(currentFront < 15 && currentFront != 0 && currentFront < 180){nextInstruction();} break;
      case 2:    turnRight(light);    break;   
      case 3:    stopMoving(0.5);     break;
      case 4:    backwards3(200, 15); if(currentFront > 70 && currentFront != 0){nextInstruction();} break;
      case 5:    turnLeft(light);          break;
      case 6:    backwards(20);  if(currentBack < 5 && currentBack != 0 && currentBack < 180){nextInstruction();}    break;
      case 7:    stopMoving(0.5);          break;
      case 8:    grabberOpen();            break;
      case 9:    stopMoving(3);            break;
      case 10:    straight2(20);  if(currentBack > 10 && currentBack != 0 && currentBack < 180){nextInstruction();}   break;
      case 11:    turnRight(light);          break;

    }  
  }  
  if(instructionCode[0] == 'A' && instructionCode[1] == 'B'){
    switch(instruction){
      case 0:  // Move to the Connect4 board
        motorState = 0;
        if(time > 5){
          instruction ++;
          startTime = time;
        }
        break;
      case 1:        armDown();         break;
      case 2:        straight2(30);       break;
      case 3:        stopMoving(0.5);   break;
      case 4:        grabberClose();  nextInstruction();  break;
      case 5:        backwards2(17);      break;
      case 6:        stopMoving(0.5);   break;
      case 7:        armUp();     nextInstruction(); blowerOn();     break;
      case 8:        stopMoving(0.5); break;
      case 9:        grabberOpen(); nextInstruction(); break;
      case 10:        stopMoving(0.5); break;
      case 11:        armDown();    nextInstruction(); blowerOff();    break;
      case 12:        straight2(30);       break;
      case 13:        stopMoving(0.5);   break;
      case 14:        grabberClose();  nextInstruction();  break;
      case 15:        backwards2(17);      break;
      case 16:        stopMoving(0.5);   break;
      case 17:        armUp();     nextInstruction(); blowerOn();     break;
      case 18:        stopMoving(0.5); break;
      case 19:        grabberOpen(); nextInstruction(); break;
      case 20:        stopMoving(0.5); break;
      case 21:        armDown();    nextInstruction(); blowerOff();    break;
      case 22:        straight2(30);       break;
      case 23:        stopMoving(0.5);   break;
      case 24:        grabberClose();  nextInstruction();  break;
      case 25:        backwards2(17);      break;
      case 26:        stopMoving(0.5);   break;
      case 27:        armUp();     nextInstruction(); blowerOn();     break;
      case 28:        stopMoving(0.5); break;
      case 29:        grabberOpen(); nextInstruction(); break;
      case 30:        stopMoving(0.5); break;      
      case 31:        armDown();    nextInstruction(); blowerOff();    break;
      case 32:        straight2(30);       break;
      case 33:        stopMoving(0.5);   break;
      case 34:        grabberClose();  nextInstruction();  break;
      case 35:        backwards2(17);      break;
      case 36:        stopMoving(0.5);   break;
      case 37:        armUp();     nextInstruction(); blowerOn();     break;
      case 38:        stopMoving(0.5); break;
      case 39:        grabberOpen(); nextInstruction(); break;
      case 40:        stopMoving(0.5); break;
      case 41:        armDown();    nextInstruction(); blowerOff();    break;
      case 42:        straight2(30);       break;
      case 43:        stopMoving(0.5);   break;
      case 44:        grabberClose();  nextInstruction();  break;
      case 45:        backwards2(17);      break;
      case 46:        stopMoving(0.5);   break;
      case 47:        armUp();     nextInstruction(); blowerOn();     break;
      case 48:        stopMoving(0.5); break;
      case 49:        grabberOpen(); nextInstruction(); break;
      case 50:        stopMoving(0.5); break;      
      case 51:        armDown();    nextInstruction(); blowerOff();    break;
      case 52:        straight2(30);       break;
      case 53:        stopMoving(0.5);   break;
      case 54:        grabberClose();  nextInstruction();  break;
      case 55:        backwards2(17);      break;
      case 56:        stopMoving(0.5);   break;
      case 57:        armUp();     nextInstruction(); blowerOn();     break;
      case 58:        stopMoving(0.5); break;
      case 59:        grabberOpen(); nextInstruction(); break;
      case 60:        stopMoving(0.5); break;
      case 61:        armDown();    nextInstruction(); blowerOff();    break;
      case 62:        straight2(30);       break;
      case 63:        stopMoving(0.5);   break;
      case 64:        grabberClose();  nextInstruction();  break;
      case 65:        backwards2(17);      break;
      case 66:        stopMoving(0.5);   break;
      case 67:        armUp();     nextInstruction(); blowerOn();     break;
      case 68:        stopMoving(0.5); break;
      case 69:        grabberOpen(); nextInstruction(); break;
      case 70:        stopMoving(0.5); break;
    }
  }
  if(instructionCode[0] == 'A' && instructionCode[1] == 'C'){
    switch(instruction){
      case 0:  // Move to the Connect4 board
        motorState = 0;
        if(time > 5){
          instruction ++;
          startTime = time;
        }
        break;
      case 1:        straight2(20);      break;
      case 2:        stopMoving(1);    break;
      case 3:        turnRight(heavy);    break;
      case 4:        stopMoving(1);    break;
      case 5:        straight(53);   break;
      case 6:        stopMoving(1);    break;
      case 7:        turnLeft(heavy);        break;
      case 8:        stopMoving(1);    break;
      case 9:        straight(130);    break;
      case 10:       stopMoving(1);    break;
      case 11:       turnLeft(heavy);        break;
      case 12:       stopMoving(1);    break;
      case 13:       straight(15);    break;
      case 14:       straight2(40);    break;
      case 15:       stopMoving(2);  break;
      case 16:       turnRight(heavy);    break;
      case 17:       stopMoving(2);  break;
      case 18:       backwards(150);  break;
      case 19:       stopMoving(1);  break;
    }
  }
  if(instructionCode[0] == 'A' && instructionCode[1] == 'D'){
    switch(instruction){
      case 0:  // Move to the Connect4 board
        motorState = 0;
        if(time > 5){
          instruction ++;
          startTime = time;
        }
        break;
      case 1:        backwards3(2000, 9);       break;
      case 2:        stopMoving(3); break;
    }
  }
  
  if(instructionCode[0] == 'B' && instructionCode[1] == 'B'){
    switch(instruction){
      case 0:  // Move to the Connect4 board
        motorState = 0;
        if(time > 5){
          instruction ++;
          startTime = time;
        }
        break;
      case 1:        stopMoving(2);          break;
      case 2:        adjust(turnAmount);       break;
      case 3:        correctionFactor3 = 0;    break;
    }
  }
  if(instructionCode[0] == 'B' && instructionCode[1] == 'C'){
    switch(instruction){
      case 0:  // Move to the Connect4 board
        motorState = 0;
        if(time > 5){
          instruction ++;
          startTime = time;
        }
        break;
      case 1:        armDown();  break;
      case 2:        stopMoving(2);    break;
      case 3:        straight2(10);  break;
      case 4:        stopMoving(1);  break;
      case 5:        grabberClose();  stopMoving(1); break;
      case 6:        backwards2(10);  break;
      case 7:        armUp();    stopMoving(1);    break;
      case 8:          stopMoving(1934);  break; 
    }
  }
  if(instructionCode[0] == 'B' && instructionCode[1] == 'D'){
    switch(instruction){  
      case 0:  // Move to the Connect4 board
        motorState = 0;
        if(time > 5){
          instruction ++;
          startTime = time;
        }
        break;
      case 1:        turnLeft(light);       break;
      case 2:        stopMoving(0.5);        break;
      case 3:        turnRight(light);        break;  
      case 4:        stopMoving(0.5);        break;  
      case 5:        turnLeft(light);       break;
      case 6:        stopMoving(0.5);        break;
      case 7:        turnRight(light);        break;  
      case 8:        stopMoving(0.5);        break;  
    }
  }
  if(instructionCode[0] == 'C' && instructionCode[1] == 'B'){}
  if(instructionCode[0] == 'C' && instructionCode[1] == 'C'){}
  if(instructionCode[0] == 'C' && instructionCode[1] == 'D'){}
  
  else if(instructionCode[0] == 'D' && instructionCode[1] == 'A'){
    switch(instruction){
      case 0:  // Move to the hoppers
        motorState = 0;
        if(time > 5){
          instruction ++;
          startTime = time;
        }
        break;
      case 1:        straight(20);              break;
      case 2:        stopMoving(1);             break;
      case 3:        turnLeft(light);                break;
      case 4:        stopMoving(1);             break;
      case 5:        straight(60);              break;
      case 6:        stopMoving(1);             break;
      case 7:        turnRight(light);               break;
      case 8:        stopMoving(1);             break;
      case 9:        straight(150 - hopper1y);  break;
      case 10:       stopMoving(1);             break;
      case 11:       turnRight(light);               break;
      case 12:       stopMoving(1);             break;
      case 13:       straight(120 - hopper1x);  break;
      case 14:       stopMoving(10);            break;
      case 15:       backwards(120 - hopper1x); break;
      case 16:       stopMoving(1);             break;
      case 17:       turnLeft(light);                break;
      case 18:       stopMoving(1);             break;
      case 19:       straight(hopper1y - hopper2y);  break;
      case 20:       stopMoving(1);                  break;
      case 21:       turnRight(light);                    break;
      case 22:       stopMoving(1);                  break;
      case 23:       straight(110 - hopper2x);       break;
      case 24:       stopMoving(100);                break;
    }  
  }
  
  else if(instructionCode[0] == 'D' && instructionCode[1] == 'B'){ // Demonstration of Movement to Hopper
    switch(instruction){
      case 0:  // Move to the Connect4 board
        motorState = 0;
        if(time - startTime > 5){
          instruction ++;
          startTime = time;
        }
        break;
      case 1:        straight2(100);          break;
    }
  }
  else if(instructionCode[0] == 'D' && instructionCode[1] == 'C'){}
  if(instructionCode[0] == 'D' && instructionCode[1] == 'D'){}
}




