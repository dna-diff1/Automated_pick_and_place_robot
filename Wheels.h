#include <Servo.h>

class Wheels
{
  private:
    int rightWheelPin=0;
    int leftWheelPin=0;
    Servo servRightWheel;
    Servo servLeftWheel;
  public:
    Wheels(int rightWheelPin,int leftWheelPin)
    {
      servRightWheel.attach(rightWheelPin);
      servLeftWheel.attach(leftWheelPin);
    }

    ~Wheels()
    {
      
    }
    //The input speed can be a value between 0-100
    void MoveForward(int speed)
    {
      //Calculate the servo speed to match with the servo motor
      //Forward Range: 90-stop, 180-full speed forward
      int servoSpeed=map(speed,0,100,90,180);
      //Since we are moving forward, both servos will move at the same speed.
      servRightWheel.write(servoSpeed);
      servLeftWheel.write(servoSpeed);
    }

    void MoveBackward(int speed)
    {
      //Calculate the servo speed to match with the servo motor
      //Forward Range: 90-stop, 0-full speed forward
      int servoSpeed=map(speed,0,100,90,0);
      //Since we are moving forward, both servos will move at the same speed.
      servRightWheel.write(servoSpeed);
      servLeftWheel.write(servoSpeed);
    }

    void RotateRight(int speed,int time)
    {
      //Both Servos should move in opposite directions
      int rightServoSpeed=map(speed,0,100,90,180);
      int leftServoSpeed=map(speed,0,100,90,0);
      servRightWheel.write(rightServoSpeed);
      servLeftWheel.write(leftServoSpeed);
    }
    void RotateLeft(int speed,int time)
    {
      //Both Servos should move in opposite directions
      int rightServoSpeed=map(speed,0,100,90,0);
      int leftServoSpeed=map(speed,0,100,90,180);
      servRightWheel.write(rightServoSpeed);
      servLeftWheel.write(leftServoSpeed);
    }
    void Stop()
    {
      //Both Servos should be at 90
      servRightWheel.write(90);
      servLeftWheel.write(90);
    }
};
