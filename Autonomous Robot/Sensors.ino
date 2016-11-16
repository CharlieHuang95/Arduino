int ultrasonicFunction(){
    float SideFrontDistance = SideFront.ping(); // Send ping, get ping time in microseconds (uS).
    float SideBackDistance = SideBack.ping();
    float FrontDistance = Front.ping();
    float BackDistance = Back.ping();
    currentSideFront = SideFrontDistance / US_ROUNDTRIP_CM - 0.6;
    currentSideBack = SideBackDistance / US_ROUNDTRIP_CM;
    currentFront = FrontDistance / US_ROUNDTRIP_CM;
    currentBack = BackDistance / US_ROUNDTRIP_CM;
    if(abs(previousBack - currentBack) > 8){
      repeatedBack ++;
      currentBack = previousBack;
      if(repeatedBack > 8){
        repeatedBack = 0;
        currentBack = BackDistance / US_ROUNDTRIP_CM;
      }
    }
    if(abs(currentSideFrontAve - currentSideFront) > 8){
      repeatedSideFront ++;
      currentSideFront = previousSideFront[0];
      if(repeatedSideFront > 8){
        repeatedSideFront = 0;
        currentSideFront = SideFrontDistance / US_ROUNDTRIP_CM;
      }
    }
      
    if(abs(currentSideBackAve - currentSideBack) > 8){
      repeatedSideBack ++;
      currentSideBack = previousSideBack[0];
      if(repeatedSideBack > 8){
        repeatedSideBack = 0;
        currentSideBack = SideBackDistance / US_ROUNDTRIP_CM;
      }
    }
      
    if(abs(previousFront - currentFront) > 8){
      repeatedFront ++;
      currentFront = previousFront;
      if(repeatedFront > 8){
        repeatedFront = 0;
        currentFront = FrontDistance / US_ROUNDTRIP_CM;
      }
    }
      
    previousSideFront[0] = currentSideFront;
    currentSideFrontAve = (previousSideFront[0] + previousSideFront[1] + previousSideFront[2])/3;
    currentSideBackAve = (previousSideBack[0] + previousSideBack[1] + previousSideBack[2])/3;
    currentSideAve = (currentSideFrontAve + currentSideBackAve)/2;
    previousSideBack[0] = currentSideBack;
    previousFront = currentFront;
    previousBack = currentBack;
    turnAmount = currentSideFrontAve - currentSideBackAve;
    correctionFactor = 0;
    shiftArray();
}

int shiftArray(){
  previousSideFront[2] = previousSideFront[1];
  previousSideFront[1] = previousSideFront[0];
  previousSideBack[2] = previousSideBack[1];
  previousSideBack[1] = previousSideBack[0];
}

int PID(){
    if(currentSideBack - currentSideFront < 0.6 && currentSideBack - currentSideFront > -0.6){ correctionFactor = 0;} 
    if(currentSideBack - currentSideFront > 0.6){ correctionFactor = 1;}
    if(currentSideBack - currentSideFront < -0.6){ correctionFactor = -1;}
}

char readPad(){
  char key = ' ';
  while(key != '1' && key != '2' && key != '3' && key != '4' && key != '5' && key != '6' && key != '7' && key != '8' && key != '9' && key != '0' && key != 'A' && key != 'B' && key != 'C' && key != 'D' && key != '*' && key != '#'){key = kpd.getKey();}
  return key;
}
