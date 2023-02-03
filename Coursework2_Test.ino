//==========================================
//  COURSE WORK TASK 2
//==========================================
//Authors: Mohamed Faizan Cassim, Sami  
//
#include "ElectroMagnet.h"
//#include "Wheels.h"
#include "RobotArm.h"
#include <Servo.h>


//Pin Definitions
#define RobotArmPin 5
#define ElectroMagnetPin 1
#define ElectroMagnetPowerPin 7
#define pinPot A0

int readingPot=0;


Servo robotArm;
ElectroMagnet em1(1);
//Wheels whls(8,9);
RobotArm rbtArm(robotArm);

void setup()
{
 // Serial.begin(9600);
  robotArm.attach(RobotArmPin);
  rbtArm.GoUp(0);
  //Read value from potentiometer
  readingPot=analogRead(pinPot);
  pinMode(ElectroMagnetPin,OUTPUT);
  pinMode(ElectroMagnetPowerPin,OUTPUT);
}

void loop()
{
  //robotArm.write(20);

 /* //Read value from potentiometer
  readingPot=analogRead(pinPot);
  int emPwmOutput=map(readingPot*1, 0, 1023,0,255);
  Serial.println(emPwmOutput);

  //em1.TurnOnPwm(emPwmOutput);
  rbtArm.Shake(5);

  if(emPwmOutput>240)
  {
   em1.TurnOn();
  }
  else
  {
    em1.TurnOff();
  }*/

  

  //em1.TurnOff();

  rbtArm.GoDown(45);
  em1.TurnOn();
  Serial.println("Magnet On");
  delay(5000);
  rbtArm.GoUp(0);
  em1.TurnOff();
  Serial.println("Magnet Off");
  delay(5000);
  

  
}
