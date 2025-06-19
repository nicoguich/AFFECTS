// Programmable-Air
// Author: tinkrmind
// https://github.com/orgs/Programmable-Air
//
// PCB v0.3/v0.4/v0.5

#include "programmable_air.h"


const int BUFFER_SIZE = 4;
char data[BUFFER_SIZE];
int pump_1,pump_2;
boolean valve_1,valve_2;

void setup() {
 initializePins();



pinMode(13,OUTPUT);
pinMode(2,INPUT_PULLUP);
pinMode(3,INPUT_PULLUP);
 /* // Pumps
  switchOnPump(1, 100);
  delay(2500);
  switchOffPump(1);
  delay(2500);
  switchOnPump(2, 100);
  delay(2500);
  switchOffPumps();
  delay(2500);


  setValve(1, OPEN);
  delay(2500);
  setValve(1, CLOSE);
  delay(2500);

  setAllValves(OPEN);
  delay(2500);
  closeAllValves();
  delay(2500);*/
}

void loop() {

  /*
  if (Serial.available() > 0) {
    Serial.readBytes(data,BUFFER_SIZE);

    pump_1=data[0];
    pump_2=data[1];
    valve_1=data[2];
    valve_2=data[3];
digitalWrite(13,HIGH);


  }
*/


if (digitalRead(2)==LOW){
  switchOnPump(1, 100);
  setValve(1, 1);

}
else{
  switchOnPump(1, 0);
  setValve(1, 0);

}


if (digitalRead(3)==LOW){
  switchOnPump(2, 100);
  setValve(2, 1);

}
else{
  switchOnPump(2, 0);
  setValve(2, 0);

}

}
