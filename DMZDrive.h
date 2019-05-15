#ifndef DMZDrive_h
#define DMZDrive_h

#include "Arduino.h"

class DMZDrive{
  public:
      DMZDrive(int lsp,int l1,int l2,int rsp,int r1,int r2, int trig[],int echo[], int threshold);
      void drive(int b, int a);
      int findDist(int a);
      void lineSense();
      bool sB[8];
  private:
      int lsp;
      int l1; 
      int l2;
      int rsp;
      int r1;
      int r2;
      int trig[];
      int echo[];
      unsigned char t;
      unsigned char data[16];
      int threshold;
};

#endif
