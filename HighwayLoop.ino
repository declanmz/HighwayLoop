#include <Wire.h>
#include "DMZDrive.h"

#define lsp 3
#define l1 4
#define l2 5
#define rsp 9
#define r1 6
#define r2 7

int trig[] = {12,10,8};
int echo[] = {13,11,2};

#define threshold 70

DMZDrive rbt(lsp,l1,l2,rsp,r1,r2,trig,echo, threshold);

void setup(){
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output  
}

void loop() {
  rbt.rightLineFollow(rbt.spedMultDist(16,25));
}
