#include <Servo.h> 
Servo myservoTurn;

#define numOfValsRec 2
#define digitsPerValRec 4

int valsRec[numOfValsRec];
int stringLength = numOfValsRec*digitsPerValRec + 1;
int counter = 0;
bool counterStart = false;
String receivedString;

 // Pin 2, 4 direction; Pin5 PWM



//const int Forward = 1;
//const int Backward = 0;

void moveRobot(int mySpeed, int myTurn, int maxSpeed = 255, int maxTurn=90)
{
  /*
  *mySpeed and myTurn range from -100 to 100
  *+ val of mySpeed is forward and - is backward
  *+ val of myTurn is right turn and - is left turn
  */

  

}

void receiveData()
{
  while(Serial.available()) {
    char c = Serial.read();
    if (c=='$'){
      counterStart = true;
    }
    if(counterStart){
      if(counter<stringLength){
        receivedString = String(receivedString+c);
        counter++;
      }
      if(counter>=stringLength){
        for(int i=0; i<numOfValsRec; i++)
        {
          int num = (i*digitsPerValRec) +1;
          valsRec[i]=receivedString.substring(num,num+digitsPerValRec).toInt(); 
        }
        receivedString = "";
        counter = 0;
        counterStart = false;
      }
    }
  }
}

void setup(){

  
}

void loop() {

}
