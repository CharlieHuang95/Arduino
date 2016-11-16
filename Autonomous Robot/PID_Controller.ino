  while(0){
    if(revolutionCountLeft > revolutionCountRight){
    analogWrite(enablePin2, 255 - 10*abs(revolutionCountRight-revolutionCountLeft));}
    if(revolutionCountRight > revolutionCountLeft){
    analogWrite(enablePin, 255 - 10*abs(revolutionCountRight-revolutionCountLeft));}
  }
