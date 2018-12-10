#include <AccelStepper.h>
#include <MultiStepper.h>

// motor speed values
const float MOTOR_SPEED = 101.1;

// pins first driver
const int STEP_PIN = 10;
const int DIRECTION_PIN = 9;

// pins second driver
const int STEP_PIN_2 = 3;
const int DIRECTION_PIN_2 = 5;

// pins third driver
const int STEP_PIN_3 = 11;
const int DIRECTION_PIN_3 = 6;

// pins switches
const int MOTOR1_SWITCH_PIN = 4;
const int MOTOR2_SWITCH_PIN = 7;
const int MOTOR3_SWITCH_PIN = 8;

// pins buttons
const int MOTOR1_BUTTON_PIN = 2;
const int MOTOR2_BUTTON_PIN = 12;
const int MOTOR3_BUTTON_PIN = 13;

// init values for buttons and switches
int button1State = 0;
int switch1State = 0;
int button2State = 0;
int switch2State = 0;
int button3State = 0;
int switch3State = 0;

/**
 * ToDO init position
 * 
 */
// void init (long positions[]) {
 
// }

/**
 * ToDO draw function 
 * add el to array
 * 
 */

void moveToPos(AccelStepper& obj, int dir, int buttonState, bool maxPosEnable = false, long maxPos = 230)  
{
    if(maxPosEnable == false){
        obj.setCurrentPosition(0);
    }

    if (dir == LOW)
    {
        if (buttonState == HIGH && obj.currentPosition() != 250 && obj.currentPosition() <= 0)
        {
            maxPos = -maxPos;
            obj.moveTo(maxPos);
            obj.setSpeed(MOTOR_SPEED);
            obj.runSpeedToPosition();
            Serial.println(obj.currentPosition());
        }
    }
    else if (dir == HIGH)
    {
        if (buttonState == HIGH && obj.currentPosition() != 250 && obj.currentPosition() <= 0)
        {
            obj.moveTo(maxPos);
            obj.setSpeed(MOTOR_SPEED);
            obj.runSpeedToPosition();
            Serial.println(obj.currentPosition());
        } 
    }
}

// motors initialization 
AccelStepper motor(AccelStepper::DRIVER, STEP_PIN, DIRECTION_PIN);
AccelStepper motor2(AccelStepper::DRIVER, STEP_PIN_2, DIRECTION_PIN_2);
AccelStepper motor3(AccelStepper::DRIVER, STEP_PIN_3, DIRECTION_PIN_3);

// multiple motor controlling
MultiStepper steppers;

void setup() {

    // Set up the three button inputs, with pullups
    pinMode(MOTOR1_BUTTON_PIN, INPUT_PULLUP);
    pinMode(MOTOR2_BUTTON_PIN, INPUT_PULLUP);
    pinMode(MOTOR3_BUTTON_PIN, INPUT_PULLUP);

    // Set up the three button inputs, with pullups
    pinMode(MOTOR1_SWITCH_PIN, INPUT_PULLUP);
    pinMode(MOTOR2_SWITCH_PIN, INPUT_PULLUP);
    pinMode(MOTOR3_SWITCH_PIN, INPUT_PULLUP);

    // Set up init @motor properties
    motor.setMaxSpeed(MOTOR_SPEED);
    motor.setSpeed(0.0);
    motor.setCurrentPosition(0);

    // Set up init @motor2 properties
    motor2.setMaxSpeed(MOTOR_SPEED);
    motor2.setSpeed(0.0);
    motor.setCurrentPosition(0);

    // Set up init @motor3 properties
    motor3.setMaxSpeed(MOTOR_SPEED);
    motor3.setSpeed(0.0);
    motor.setCurrentPosition(0);

    // sync tree motors for leater use
    steppers.addStepper(motor);
    steppers.addStepper(motor2);
    steppers.addStepper(motor3);
    
    // start serial monitoring
    Serial.begin(9600);
    Serial.println("Stepper test!");
    
}

void loop() {
    //for later use
    //long positions[3];

    //button state values 1 or 0, HIGH or LOW
    button1State = digitalRead(MOTOR1_BUTTON_PIN);
    switch1State = digitalRead(MOTOR1_SWITCH_PIN);
    button2State = digitalRead(MOTOR2_BUTTON_PIN);
    switch2State = digitalRead(MOTOR2_SWITCH_PIN);
    button3State = digitalRead(MOTOR3_BUTTON_PIN);
    switch3State = digitalRead(MOTOR3_SWITCH_PIN);

    /**
    * function call 
    * @params:
    *   @AccelStepper& obj, 
    *   @int dir, 
    *   @int buttonState, 
    *   @bool maxPosEnable = false, 
    *   @long maxPos = 230
    */
    moveToPos(motor, switch1State, button1State);
    moveToPos(motor2, switch2State, button2State);
    moveToPos(motor3, switch3State, button3State);
   
}