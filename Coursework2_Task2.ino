//==========================================
//  COURSE WORK TASK 2
//==========================================
//Authors: Mohamed Faizan Cassim, Sami  
//
#include "ElectroMagnet.h"
#include "Wheels.h"

ElectroMagnet em1(1);
Wheels whls(8,9);


void setup()
{
 
}

void loop()
{
  em1.TurnOn();
  em1.TurnOff();
}
