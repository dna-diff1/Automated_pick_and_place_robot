
class ElectroMagnet
{
  private:
    int elecMagnetPin=0;
    bool elecMagnetStatus=false;

  public:
    ElectroMagnet(int pin)
    {
        this->elecMagnetPin=pin;
        //Set Electromagnet Pin as output
        pinMode(elecMagnetPin,OUTPUT);
        //Turn Electromagnet Pin off
        digitalWrite(elecMagnetPin,LOW); 
    }

    ~ElectroMagnet()
    {
      
    }

    void TurnOn()
    {
      digitalWrite(elecMagnetPin,HIGH); 
    }

    void TurnOff()
    {
      digitalWrite(elecMagnetPin,LOW);
    }

    void TurnOnPwm(int value)
    {
      analogWrite(elecMagnetPin,value);
    }
};
