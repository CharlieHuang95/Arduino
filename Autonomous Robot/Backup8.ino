#include <NewPing.h> //Ultrasonic sensor library
#include <Servo.h>
#include <Keypad.h>

/* Pin Declarations **********************************************************************************************************/

#define TRIGGER_PIN_SideFront  42  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_SideFront     43  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN_SideBack 39  
#define ECHO_PIN_SideBack 38
#define TRIGGER_PIN_Front 50
#define ECHO_PIN_Front 51
#define TRIGGER_PIN_Back 47
#define ECHO_PIN_Back 46
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

#define timeconstant 9
#define North 1
#define South 2
#define West 3
#define East 4

const int windBlower = 4;
const int boardMotorRotationPin1 = 15;
const int boardMotorRotationPin2 = 16;
const int boardMotorRotationEnablePin = 17;

/* Variable Declarations *****************************************************************************************************/

char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[4] = { 23, 25, 27, 29 }; // Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[4] = { 31, 33, 35, 37 }; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, 4, 4); // Create the Keypad

int connectBoard[6][7] = {
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0}
};	

int pointsNextMove[7] = {0,0,0,0,0,0,0};
int pointsNextTwoMove[7][7] = {
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0}
};

char firstMiddleHopper;

float hopperXs[5] = {55.0, 67.2, 79.9, 92.1, 105.0};
float hopperYs[6] = {65.5, 72.5, 86.7, 93.7, 108.47, 115.74};
float light = 1.22;
float heavy = 2.6;
int correctionFactor3 = 0;
int column;
int bestColumn;  
int inputColumn;
char colour;
int blackColumns;
int blackRows;
int blackDiagonals;
int totalBlackConnects = 0;
int totalBlackBalls = 0;
int totalBlackPoints = 0;
int whiteColumns;
int whiteRows;
int whiteDiagonals;
int totalWhiteConnects = 0;
int totalWhiteBalls = 0;
int totalWhitePoints = 0;
int ballsCollectedFromHopper = 0;
float hopper1x;
float hopper1y;
int approach1;
float hopper2x;
float hopper2y;
int approach2;

float time;
float turnAmount;
float startTime;
int num = 0; 
int ballHasBeenPutIn = 0;
float currentSideAve;

int repeatedSideFront;
float previousSideFront[3];
float currentSideFront;
float currentSideFrontAve;

int repeatedSideBack;
float previousSideBack[3];
float currentSideBack;
float currentSideBackAve;

float previousFront;
float currentFront;
int repeatedFront;

float previousBack;
float currentBack;
int repeatedBack;

int repeatedGameboard;
float previousGameboard;
float currentGameboard;

int correctionFactor = 0;
int correctionFactor2 = 0;
int PIDenabled = 1;

int instruction = 0;
char instructionCode[8] = {'0','0','0','0','0','0','0','0'};

int motorEnabled = 1;
int motorSpeed = 0;
int motorState = 0;
int clampState = 0;

int recentlySwitched;
int iteration = 0;

float correctionDistance1x;
float correctionDistance2x;
float correctionDistance1y;
float correctionDistance2y;

int x;
int y;
int heading = North;

NewPing SideFront(TRIGGER_PIN_SideFront, ECHO_PIN_SideFront, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing SideBack(TRIGGER_PIN_SideBack, ECHO_PIN_SideBack, MAX_DISTANCE);
NewPing Front(TRIGGER_PIN_Front, ECHO_PIN_Front, MAX_DISTANCE);
NewPing Back(TRIGGER_PIN_Back, ECHO_PIN_Back, MAX_DISTANCE);

Servo leftMotor;
Servo rightMotor;
Servo GrabberServo;  // create servo object to control a servo 
Servo ArmServo;
int pos = 0;    // variable to store the servo position 
 
/* Mode Declarations *****************************************************************************************************/

void setup(){
  Serial.begin(9600);
  
  leftMotor.attach(8);
  rightMotor.attach(10);
  ArmServo.attach(13);  // attaches the servo on pin 9 to the servo object
  GrabberServo.attach(6);
  
  pinMode(windBlower, OUTPUT);
  pinMode(boardMotorRotationPin1, OUTPUT);
  pinMode(boardMotorRotationPin2, OUTPUT);
  pinMode(boardMotorRotationEnablePin, OUTPUT);
  
  ArmServo.write(50);
  GrabberServo.write(90);
}
void loop(){
  if(num == 0){ // Initial Run of the Loop
    readInstruction();
    ultrasonicFunction();
    previousSideFront[0] = currentSideFront;
    previousSideBack[0] = currentSideBack;
    previousFront = currentFront;
    previousBack = currentBack;
    ballsCollectedFromHopper = instructionCode[7];
  }
  if(num == 0){
    hopperLocation();
    startTime = millis()/((float)1000);
    time = 0;
  }
  /*if(ballHasBeenPutIn == 1){
    bestColumn = gameState(inputColumn);
    ballHasBeenPutIn = 0;
  } */
  ultrasonicFunction();
  if(PIDenabled == 1){PID();}
  num ++; // Count for main loop of sensors
  iteration ++; // Vital count for instructions
  motorStateFunction(correctionFactor);
  // selfLocalization(currentFront, currentSideFront);
  // clampFunction();
  instructionFunction();
  printSerialDemo(); 
}
