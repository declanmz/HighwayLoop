#include "Arduino.h"
#include "DMZDrive.h"
#include <Wire.h>

DMZDrive::DMZDrive(int lsp, int l1, int l2, int rsp, int r1, int r2, int trig[], int echo[], int threshold, int leftShift) {
  lsp = lsp;
  l1 = l1;
  l2 = l2;
  rsp = rsp;
  r1 = r1;
  r2 = r2;
  echo = echo;
  trig = trig;
  threshold = threshold;
  leftShift = leftShift;
}

void DMZDrive::drive(int b, int a) { //input left and right speeds from -255 to 255, will move motors at those speeds
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
  b = map(b, 0, 255, 0, leftShift); //maps the left motor to straighten the robot path

  analogWrite(lsp, b);
  analogWrite(rsp, a);
}

int DMZDrive::findDist(int a) { //ultrasonic sensor find distance, input the number of the sensor, indexing starts at 0
  digitalWrite(trig[a], LOW);
  delayMicroseconds(2);
  digitalWrite(trig[a], HIGH);
  delayMicroseconds(10);
  digitalWrite(trig[a], LOW);
  return float(pulseIn(echo[a], HIGH) * 0.034 / 2);
}

void DMZDrive::lineSense() { //outputs true/false for sB array based on if sensor value is below threshold (true if on black)
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

void DMZDrive::rightLineFollow(float spedMult) { //line follower program for following a line on the right side of the robot
  lineSense();
  if (sB[0] && sB[7]) {
    drive(0, 0);
  } else if (!sB[3] && !sB[4] && !sB[5] && !sB[6] && !sB[7]) {
    drive(250 * spedMult, -100 * spedMult);
  } else if (sB[3]) {
    drive(-250 * spedMult, 250 * spedMult);
  } else if (sB[4]) {
    drive(-150 * spedMult, 250 * spedMult);
  } else if (sB[5]) {
    drive(50 * spedMult, 250 * spedMult);
  } else if (sB[6]) {
    drive(200 * spedMult, 250 * spedMult);
  } else if (sB[7]) {
    drive(250 * spedMult, 250 * spedMult);
  }
}

float DMZDrive::spedMultDist(float bottom, float top) { //outputs a float from 0 to 1 based on distance with the front ultrasonic, bottom and top are the minimum and maximum values, where 0 and 1 will be output
  float dist0 = findDist(0);

  if (dist0 > top) {
    return 0.7;
  } else if (dist0 <= top && dist0 > bottom) {
    return map(float(dist0), bottom, top, 0, .7);
  } else {
    return 0;
  }
}
