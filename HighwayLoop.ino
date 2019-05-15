#include <Wire.h>
#include "DMZDrive.h"

#define lsp 3 //motor pins
#define l1 4
#define l2 5
#define rsp 9
#define r1 6
#define r2 7

int trig[] = {12, 10, 8}; //trig and echo pins for each ultrasonic
int echo[] = {13, 11, 2};

#define threshold 70 //the threshold from black to white on the line follower module

#define leftShift 245 //maps the left speed to from 0-245, instead of 0-255, used to straigten out driving

DMZDrive rbt(lsp, l1, l2, rsp, r1, r2, trig, echo, threshold, leftShift); //create DMZDrive obj from library

void setup() {
  Wire.begin(); //i2c bus communication for line follower module
}

void loop() {
  rbt.rightLineFollow(rbt.spedMultDist(16, 25)); //follow right line, set the speed multiplier to change based on the front ultrasonic distance min = 16cm, max = 25cm
}
