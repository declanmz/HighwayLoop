#include <Wire.h>
#include "DMZDrive.h"
//#define uchar unsigned char

#define lsp 3
#define l1 4
#define l2 5
#define rsp 9
#define r1 6
#define r2 7

int trig[] = {12,10,8};
int echo[] = {13,11,2};

//long duration[3];
//float distance[3];

//uchar t;
//uchar data[16];

#define threshold 70
//bool sB[8]; //an array of booleans based on if the line follower is touching a line (ordered 0 - 7)

DMZDrive rbt(lsp,l1,l2,rsp,r1,r2,trig,echo, threshold);

void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
//  t = 0;
  
}

void loop() {
  rightLineFollow();
  }
