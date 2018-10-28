#include <AccelStepper.h>
#include <MultiStepper.h>

// pins frist driver
const int STEP_PIN = 10;
const int DIRECTION_PIN = 9;

// pins second driver
const int STEP_PIN_2 = 3;
const int DIRECTION_PIN_2 = 5;

//pins third driver
const int STEP_PIN_3 = 11;
const int DIRECTION_PIN_3 = 6;

// const int LEFT_PIN  0;
// const int RIGHT_PIN 0;

//initial vulues
const float VOLT_OUT = 3; // Change voltage of output pin, max 5 = HIGH
const int PWM_OUT_VOLTAGE_LEVEL = 255/5*VOLT_OUT; 
int BUTTON_INITITAL_STATE = 0;

// motors initialization 
AccelStepper motor(AccelStepper::DRIVER, STEP_PIN, DIRECTION_PIN);
AccelStepper motor2(AccelStepper::DRIVER, STEP_PIN_2, DIRECTION_PIN_2);
AccelStepper motor3(AccelStepper::DRIVER, STEP_PIN_3, DIRECTION_PIN_3);

MultiStepper steppers;

//Test without buttons
int spd = 10.0;    // The current speed in steps/second
int sign = 1;      // Either 1, 0 or -1

void setup() {

motor.setMaxSpeed(101.0);
motor.setSpeed(0.0);

motor2.setMaxSpeed(101.0);
motor2.setSpeed(0.0);

motor3.setMaxSpeed(101.0);
motor3.setSpeed(0.0);

steppers.addStepper(motor);
steppers.addStepper(motor2);
steppers.addStepper(motor3);

 // Set up the three button inputs, with pullups
//pinMode(LEFT_PIN, INPUT_PULLUP);
//pinMode(RIGHT_PIN, INPUT_PULLUP);


Serial.begin(9600);
Serial.println("Stepper test!");
}

void loop() {
  
  char c;
  int currPos;
  long positions[3];

//  // switch states
//  if (digitalRead(LEFT_PIN) == 0) {
//    sign = 1;
//  }
//  else if (digitalRead(RIGHT_PIN) == 0) {    
//    sign = -1;
//  }
  
  // move values .... toDo
  // positions[0] = 200;
  // positions[1] = 200;
  // positions[2] = 200
  // steppers.moveTo(positions);
  // steppers.runSpeedToPosition(); // Blocks until all are in position
  // delay(1000);
  
  //console conrol comands
  if(Serial.available()) {
    c = Serial.read();
    if (c == 'a') {  // forward
      motor.setCurrentPosition(0);
      positions[0] = 20;
      positions[1] = 0;      
      positions[2] = 0;      
      steppers.moveTo(positions);
      steppers.runSpeedToPosition(); // Blocks until all are in position
      delay(1000);
      Serial.println("Now is MOTOR1 LEFT position");
    }
    if (c == 'b') {  // reverse
      motor.setCurrentPosition(0);
      positions[0] = -20;
      positions[1] = 0;      
      positions[2] = 0; 
      steppers.moveTo(positions);
      steppers.runSpeedToPosition(); // Blocks until all are in position
      delay(1000);
      Serial.println("Now is MOTOR1 RIGHT position");
    }
    if (c == 'c') {  // forward
      motor2.setCurrentPosition(0);
      positions[0] = 0;
      positions[1] = 20;      
      positions[2] = 0;      
      steppers.moveTo(positions);
      steppers.runSpeedToPosition(); // Blocks until all are in position
      delay(1000);
      Serial.println("Now is MOTOR1 LEFT position");
    }
    if (c == 'd') {  // reverse
      motor2.setCurrentPosition(0);
      positions[0] = 0;
      positions[1] = -20;      
      positions[2] = 0; 
      steppers.moveTo(positions);
      steppers.runSpeedToPosition(); // Blocks until all are in position
      delay(1000);
      Serial.println("Now is MOTOR1 RIGHT position");
    }
    if (c == 'e') {  // forward
      motor3.setCurrentPosition(0);
      positions[0] = 0;
      positions[1] = 0;      
      positions[2] = 20;      
      steppers.moveTo(positions);
      steppers.runSpeedToPosition(); // Blocks until all are in position
      delay(1000);
      Serial.println("Now is MOTOR3 LEFT position");
    }
    if (c == 'f') {  // reverse
      motor3.setCurrentPosition(0);
      positions[0] = 0;
      positions[1] = 0;      
      positions[2] = -20; 
      steppers.moveTo(positions);
      steppers.runSpeedToPosition(); // Blocks until all are in position
      delay(1000);
      Serial.println("Now is MOTOR3 RIGHT position");
    }

    // speed 
    // if (c == 's') {  // stop
    //   sign = 0;
    //   Serial.println("STOP!");
    // }
    // if (c == '1') {  // super slow
    //   spd = 10.0;
    //   Serial.println("Now is super slow speed");
    // }
    // if (c == '2') {  // medium 
    //   spd = 100.0;
    //   Serial.println("Now is medium speed");
    // }
    // //steppers.setSpeed(sign * spd); // simple steppers movements
  }
  // steppers.runSpeedToPosition();
}
