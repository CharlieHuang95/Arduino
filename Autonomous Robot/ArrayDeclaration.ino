int hopperLocation(){
  hopper1x = hopperXs[(int)instructionCode[2]-49];
  hopper1y = hopperYs[(int)instructionCode[3]-49];
  hopper2x = hopperXs[(int)instructionCode[4]-49];
  hopper2y = hopperYs[(int)instructionCode[5]-49];
}

int approachPosition(){
  // Must either approach at vertical, 30 degrees west, 30 degrees east
  if(instructionCode[2] == 1 && instructionCode[3] == 1){approach1 = -1;}
  if(instructionCode[2] == 1 && instructionCode[3] == 2){approach1 = 0;}
  if(instructionCode[2] == 2 && instructionCode[3] == 1){approach1 = -1;}
  if(instructionCode[2] == 2 && instructionCode[3] == 2){approach1 = 0;}
  
  if(instructionCode[2] == 1 && instructionCode[3] == 3){approach1 = -1;}
  if(instructionCode[2] == 1 && instructionCode[3] == 4){approach1 = 0;}
  if(instructionCode[2] == 2 && instructionCode[3] == 3){approach1 = -1;}
  if(instructionCode[2] == 2 && instructionCode[3] == 4){approach1 = 0;}
  if(instructionCode[2] == 1 && instructionCode[3] == 5){approach1 = -1;}
  if(instructionCode[2] == 1 && instructionCode[3] == 6){approach1 = 0;}
  if(instructionCode[2] == 2 && instructionCode[3] == 5){approach1 = -1;}
  if(instructionCode[2] == 2 && instructionCode[3] == 6){approach1 = 0;}
  
  if(instructionCode[4] == 4 && instructionCode[5] == 5){approach2 = 1;}
  if(instructionCode[4] == 4 && instructionCode[5] == 6){approach2 = 0;}
  if(instructionCode[4] == 5 && instructionCode[5] == 5){approach2 = 1;}
  if(instructionCode[4] == 5 && instructionCode[5] == 6){approach2 = 0;}
  
  if(instructionCode[4] == 4 && instructionCode[5] == 3){approach2 = 1;}
  if(instructionCode[4] == 4 && instructionCode[5] == 4){approach2 = 0;}
  if(instructionCode[4] == 5 && instructionCode[5] == 3){approach2 = 1;}
  if(instructionCode[4] == 5 && instructionCode[5] == 4){approach2 = 0;}
  if(instructionCode[4] == 4 && instructionCode[5] == 1){approach2 = 1;}
  if(instructionCode[4] == 4 && instructionCode[5] == 2){approach2 = 0;}
  if(instructionCode[4] == 5 && instructionCode[5] == 1){approach2 = 1;}
  if(instructionCode[4] == 5 && instructionCode[5] == 2){approach2 = 0;}
  
  if(approach1 == 0){correctionDistance1x = 0; correctionDistance1y = 0;}
  if(approach2 == 0){correctionDistance2x = 0; correctionDistance2y = 0;}
  if(approach1 == -1){correctionDistance1x = 32; correctionDistance2y = 27;}
  if(approach2 == 1){correctionDistance2x = 32; correctionDistance2y = 27;}
  
  if(approach2 == 0){firstMiddleHopper = 2;}
  if(approach1 == 0){firstMiddleHopper = 1;}
}
  

