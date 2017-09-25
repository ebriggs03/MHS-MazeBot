
#include <SoftwareSerial.h>

SoftwareSerial mazebot(3, 4); // RX, TX

void setup() {
  pinMode(8,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  mazebot.begin(9600);
}

void loop() { // run over and over

    delay(1000);
    forward(); 
    delay(1000);
    leftTurn();
    backward();
    
}

void setMotor(int motor){
  setMotor(motor, motor);
}
void backward(){
    setMotor(-55,-51);
}

void leftTurn(){
    setMotor(-63,0);
    delay(625);
}

void Stop(){
    setMotor(0,0);
}

void rightTurn(){
    setMotor(0,-64);
}

void forward(){
  setMotor(55,51);
}
void setMotor(int mLeft, int mRight){ //-63, 63

  mazebot.write(mLeft + 64); //1 - 127, 64
  mazebot.write(mRight + 192); // 128-255, 192

  // Stop is (0,0)
  // mRight greater then 192 is backwards
  // mLeft Greater then 64 is backwards
  // Straight is (-55,-51)
  // Rotate 90 CCW is setMotor(-63,0); delay(625)
  // Rotate 90 CW is setMotor(0,-64)
  }

