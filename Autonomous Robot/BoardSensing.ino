#include <NewPing.h>

#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     10  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define address 0x1E //0011110b, I2C 7bit address of HMC5883

NewPing sonar1(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int i;
int timeOfObstruction;
int distance;
int column;
int connectBoard[7][6] = {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};

void setup(){
  Serial.begin(9600);
}

void loop(){
  ultrasonicFunction(); // Continuously update
  if(distance < 40){ // An obstruction has been placed at the top of the board
    timeOfObstruction++;
    if(timeOfObstruction > 10){ // The obstruction is not just a temporary error
      updateBoard();
      timeOfObstruction = 0;
    }
  }
  printState();
}

int updateBoard(){
  if(distance > 30 && distance < 32){updateColumn(1);}
  else if(distance > 25 && distance < 30){updateColumn(2);}
  else if(distance > 20 && distance < 25){updateColumn(3);}
  else if(distance > 15 && distance < 20){updateColumn(4);}
  else if(distance > 10 && distance < 15){updateColumn(5);}
  else if(distance > 5 && distance < 10){updateColumn(6);}
  else if(distance > 0 && distance < 5){updateColumn(7);}
}

int updateColumn(int column){
  while(1){
    if(connectBoard[column][i] == 0){
      connectBoard[column][i] = 1;
      break;
    }
    else{i++;}
  }
}

void printState(){
  for(int i = 0; i <= 6; i++){
    for (int j = 0; j <= 7; j++){
      Serial.print(connectBoard[j][i]);
    }
    Serial.println(" ");
  }
  Serial.println("-------------------------");
}

int ultrasonicFunction(){
  unsigned int uS = sonar1.ping(); // Send ping, get ping time in microseconds (uS).
  distance = uS / US_ROUNDTRIP_CM;
}
