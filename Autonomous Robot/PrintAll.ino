int printSerialAll(){  
  Serial.print("-- SideFrontDistance: ");
  Serial.print(currentSideFront); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.print("cm, ");
  Serial.print("FrontDistance: ");
  Serial.print(currentSideBack); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.print("cm -- ");

  Serial.print("  X-axis: ");
  Serial.print(x);
  Serial.print("  Y-axis: ");
  Serial.print(y);
    
  Serial.print("Instruction:");
  Serial.print(instruction);

  Serial.print("  Iteration: ");
  Serial.print(iteration);
  Serial.print("   ");
  time = millis()/((float)1000);
  Serial.println(time);
  
}
