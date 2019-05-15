#include "Arduino.h"
#include "DMZDrive.h"


DMZDrive::DMZDrive(int lsp,int l1,int l2,int rsp,int r1,int r2){
  lsp = lsp; 
  l1 = l1; 
  l2 = l2; 
  rsp = rsp; 
  r1 = r1; 
  r2 = r2;
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
