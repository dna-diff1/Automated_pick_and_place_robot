#include<Servo.h>

class RobotArm
{
  private:
  int armPin = 0; // this value check in the test
  Servo arm;
  public:
  RobotArm(int armPin)
  {
   arm.attach(armPin)
    }
  void GoDown(int angle){
    int pos =0; // verify this value in the tests
    for (pos = 0; pos <= angle; pos += 1) { 
    myservo.write(pos); 
    delay(10);
     }
    }
  void GoUp(int angle){
    int pos = 180; // // verify this value in the tests
    for (pos = 180; pos >= angle; pos -= 1) {
    myservo.write(pos);              
    delay(10);                       
    }
  }
}
