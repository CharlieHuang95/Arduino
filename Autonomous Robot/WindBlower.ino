int blowerOn(){
  digitalWrite(windBlower,HIGH);
  if(time - startTime > 3){
    instruction++;
    startTime = time;
  } 
}

int blowerOff(){
  digitalWrite(windBlower,LOW);
  if(time - startTime > 0.5){
    instruction++;
    startTime = time;
  }
} 
