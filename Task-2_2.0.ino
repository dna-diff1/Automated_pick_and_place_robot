//#include <SharpIR.h>
#include <Servo.h>

const int pinAI11 = 1;       // Pin allocation for AI1
const int pinAI12 = 2;       // Pin allocation for AI2
const int pinBI11 = 3;       // Pin allocation for AI1
const int pinBI12 = 4;       // Pin allocation for AI2
const int pinPWM1 = 5;       // Pin allocation for the PWM pin
const int pinPWM2 = 6;       // Pin allocation for the PWM pin
const int pinStandBy1 = 7;   // Pin allocation for the standby pin
const int pinIR = A0;
const int pinGripper = 9;
const int pinArm = 10;
const int pinHall_1 = 12;
const int pinHall_2 = 13;
//const int pinLED1 = 0; // R
//const int pinLED2 = 8; // B
//const int pinLED3 = 11; // G

boolean AI11 = 0;            // AI1 pin value
boolean AI12 = 0;            // AI2 pin value
boolean BI11 = 0;            // AI1 pin value
boolean BI12 = 0;            // AI2 pin value
boolean standBy1 = 0;        // standBy pin Value

int dist,i;
int pos = 0;
int flag = 0;
int hallstate1,hallstate2;
Servo gripper, arm;

void setup() 
{
  pinMode(pinAI11, OUTPUT);
  pinMode(pinAI12, OUTPUT);
  pinMode(pinBI11, OUTPUT);
  pinMode(pinBI12, OUTPUT);
  pinMode(pinPWM1, OUTPUT);
  pinMode(pinPWM2, OUTPUT);
  pinMode(pinStandBy1, OUTPUT);
  //moveStop(0);
//  digitalWrite(pinLED1, 0); //R
//  digitalWrite(pinLED2, 0); //B
//  digitalWrite(pinLED3, 0); //G
  gripper.attach(pinGripper);
  arm.attach(pinArm);
  arm.write(90);
  gripper.write(90);
  standBy1 = true;
  digitalWrite(pinStandBy1, standBy1);
//  Serial.begin(9600);
}

void loop()
{
  arm.write(90);
  gripper.write(90);
//  digitalWrite(pinLED1, 1);
//  digitalWrite(pinLED2, 0);
//  digitalWrite(pinLED3, 0);
  delay(4000);
//  digitalWrite(pinLED1, 0);
//  digitalWrite(pinLED2, 0);
//  digitalWrite(pinLED3, 1);
  if(flag==0)
  {
//  moveForward(0);
//  delay(1000);
  hallstate1 = digitalRead(pinHall_1);
  while(hallstate1 == HIGH)
  {
    moveForward(0);
    hallstate1 = digitalRead(pinHall_1);
  }
  moveStop(0);
  gripper_grab();
  moveForward(0);
  delay(1500);
  moveStop(1);
  delay(200);
  alt_path();
//  moveForward(0);
//  delay(2000); 
  hallstate2 = digitalRead(pinHall_2);  
  while(hallstate2 == LOW)
  {
    moveForward(0);
    hallstate2 = digitalRead(pinHall_2);
  }
  moveStop(0);
  gripper_drop();
  moveBackward(0);
  delay(2000);
  moveStop(2);
//  digitalWrite(pinLED1, 1);
//  digitalWrite(pinLED2, 0);
//  digitalWrite(pinLED3, 0);
  flag = 1; 
  } 
}

int distance()
{
  dist = 4800/(analogRead(pinIR)-20);
  if(dist > 80) 
  return 81;
  else if(dist < 10) 
  return 9;
  else 
  return dist;
}

void moveBackward(int f) 
{
  AI11 = true;
  AI12 = false;
  BI11 = true;
  BI12 = false;
    
  digitalWrite(pinAI11, AI11);
  digitalWrite(pinAI12, AI12);
  digitalWrite(pinBI11, BI11);
  digitalWrite(pinBI12, BI12);

  if (f == 0)
  {
  analogWrite(pinPWM1, 200);
  analogWrite(pinPWM2, 200);
  }
  else
  {
  analogWrite(pinPWM1, 120);
  analogWrite(pinPWM2, 120);    
  }
}

void moveForward(int f) 
{
  AI11 = false;
  AI12 = true;
  BI11 = false;
  BI12 = true; 
   
  digitalWrite(pinAI11, AI11);
  digitalWrite(pinAI12, AI12);
  digitalWrite(pinBI11, BI11);
  digitalWrite(pinBI12, BI12);
  
  if (f == 0)
  {
  analogWrite(pinPWM1, 200);
  analogWrite(pinPWM2, 200);
  }
  else
  {
  analogWrite(pinPWM1, 120);
  analogWrite(pinPWM2, 120);    
  }
}

void moveLeft() 
{
  AI11 = true;
  AI12 = false;
  BI11 = false;
  BI12 = true;
  
  digitalWrite(pinAI11, AI11);
  digitalWrite(pinAI12, AI12);
  digitalWrite(pinBI11, BI11);
  digitalWrite(pinBI12, BI12);
  
  analogWrite(pinPWM1, 150);
  analogWrite(pinPWM2, 150);  
}

void moveRight() 
{
  AI11 = false;
  AI12 = true;
  BI11 = true;
  BI12 = false;
  
  digitalWrite(pinAI11, AI11);
  digitalWrite(pinAI12, AI12);
  digitalWrite(pinBI11, BI11);
  digitalWrite(pinBI12, BI12);
  
  analogWrite(pinPWM1, 150);
  analogWrite(pinPWM2, 150);
}

void moveStop(int f) 
{
  int i;
  if (f==1)
  {
  AI11 = false;
  AI12 = true;
  BI11 = false;
  BI12 = true;
  }
  else
  {
  AI11 = true;
  AI12 = false;
  BI11 = true;
  BI12 = false; 
  } 
    
  digitalWrite(pinAI11, AI11);
  digitalWrite(pinAI12, AI12);
  digitalWrite(pinBI11, BI11);
  digitalWrite(pinBI12, BI12);  

  if(f!=0)
  for(i=150;i>=0;i-=25)
  {
  analogWrite(pinPWM1, i);
  analogWrite(pinPWM2, i);
  delay(30);
  }
  else
  {
  analogWrite(pinPWM1, 0);
  analogWrite(pinPWM2, 0);    
  }
}

void gripper_grab()
{
//  digitalWrite(pinLED1, 0);
//  digitalWrite(pinLED2, 1);
//  digitalWrite(pinLED3, 0);
  gripper.write(150);
  delay(1000);
  for(pos = 90; pos<=150; pos +=2)
  {
    arm.write(pos);
    delay(15);
  }  
  delay(500);
}

void gripper_drop()
{
  for(pos = 150; pos>=90; pos -=2)
  {
   arm.write(pos);
   delay(15);
  }
  delay(500);
  gripper.write(100);
//  digitalWrite(pinLED1, 0);
//  digitalWrite(pinLED2, 0);
//  digitalWrite(pinLED3, 1); 
  delay(1000);
}
void alt_path()
{
  moveRight();
  delay(1000);
  moveStop(0);
  delay(100);
  moveForward(0);
  delay(1000);
  moveStop(1);
  delay(100);
  moveLeft();
  delay(1000);
  moveStop(0);
  delay(100);
  moveForward(0);
  delay(1000);
  moveStop(1);
  delay(100);
  moveLeft();
  delay(1000);
  moveStop(0);
  delay(100);
  moveForward(0);
  delay(1000);
  moveStop(1);
  delay(100);
  moveRight();
  delay(1000);
  moveStop(0);
  delay(100);       
}

