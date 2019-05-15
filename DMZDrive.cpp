#include "Arduino.h"
#include "DMZDrive.h"
#include <Wire.h>



DMZDrive::DMZDrive(int lsp,int l1,int l2,int rsp,int r1,int r2, int trig[], int echo[], int threshold){
  lsp = lsp; 
  l1 = l1; 
  l2 = l2; 
  rsp = rsp; 
  r1 = r1; 
  r2 = r2;
  echo = echo;
  trig = trig;
  threshold = threshold;
}

void DMZDrive::drive(int b, int a){
  if (a > 0) {
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
  } else if (a < 0) {
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
  } else if (a == 0) {
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
  }

  if (b > 0) {
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
  } else if (b < 0) {
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
  } else if (b == 0) {
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
  }

  a = abs(a);
  b = abs(b);
  b = map(b, 0, 255, 0, 245);

  analogWrite(lsp, b);
  analogWrite(rsp, a);
}

int DMZDrive::findDist(int a){
  digitalWrite(trig[a], LOW);
  delayMicroseconds(2);
  digitalWrite(trig[a], HIGH);
  delayMicroseconds(10);
  digitalWrite(trig[a], LOW);
  return float(pulseIn(echo[a],HIGH)*0.034/2);
}

void DMZDrive::lineSense() {
  Wire.requestFrom(9, 16);    // request 16 bytes from slave device #9
  while (Wire.available())   // slave may send less than requested
  {
    data[t] = Wire.read(); // receive a byte as character
    if (t < 15)
      t++;
    else
      t = 0;
  }

  for (int i = 0; i <= 7; i++) {
    sB[i] = data[i * 2] < threshold;
  }
}
