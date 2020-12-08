/*
 * ECE 480 Team #2 - Silverware sorting robot
 * 11/19/2020
 * Nick Coury
 * 
 * This arduino code controls the conveyor belt on the robot.
 * Steper Motor Parameters:
 *    Model = NEMA 17 
 *    Step Angle = 1.8 degrees
 *    Steps per rotation = 200 steps
 *    
 * The code takes a desired velocity as an input and passes the equivilant RPM to the stepper motor. 
 * There is also an included variable "start" in the loop that allows for the motor to be turned off 
 * from the code.
 * 
 */

#include <AFMotor.h>    //Adafruit Motor Controller Shield V1 header file

const int STEPS = 200;  //This defines the steps per rotation of the stepper motor
const int CONNECTION = 2; //This defines the control scheme of the stepper motor (M3 and M4)
const int button = 19;  //This defines the pin that the button is connected to (pin 19 is A5)

AF_Stepper motor(STEPS, CONNECTION);

void setup() {
  const float DIAMETER = 0.03353;   //Diameter of conveyor roller with belt (mm)
  const float VELOCITY = 0.1;   //Linear velocity in mm/s

  float radius = DIAMETER / 2;
  float rpm = 0.0;
  float omega = 0.0;

  // Translate the conveyor velocity to an rpm for the stepper motor
  omega = VELOCITY / radius;  //Angular velocity
  rpm = (omega * 60) / (2 * PI);
  
  motor.setSpeed(rpm);

  //Pin assignment for on/off of conveyor
  pinMode(A5, INPUT_PULLUP);    //Set Analog pin 5 to input w/ a pullup resistor 
}

void loop() {
  bool start = true;  //Changing this bit to "false" will stop the motor from driving
  int buttonState = digitalRead(button);    //Read the value of the button and store it as current state
  
  if(buttonState == LOW || start == true){
    motor.step(200, BACKWARD, DOUBLE);  //run the motor indefinitely
  }else{
    motor.release();
  }  
}
