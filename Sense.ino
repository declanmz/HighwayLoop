//void lineSense() {
//  Wire.requestFrom(9, 16);    // request 16 bytes from slave device #9
//  while (Wire.available())   // slave may send less than requested
//  {
//    data[t] = Wire.read(); // receive a byte as character
//    if (t < 15)
//      t++;
//    else
//      t = 0;
//  }
//
//  for (int i = 0; i <= 7; i++) {
//    sB[i] = data[i * 2] < threshold;
//  }
//}

//int findDist(int a){
//  digitalWrite(trig[a], LOW);
//  delayMicroseconds(2);
//  digitalWrite(trig[a], HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trig[a], LOW);
//  duration[a] = pulseIn(echo[a], HIGH);
//  distance[a]= duration[a]*0.034/2;
//  return distance[a];
//}


//int findDist1(){
//  digitalWrite(trig1, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trig1, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trig1, LOW);
//  duration1 = pulseIn(echo1, HIGH);
//  distance1= duration1*0.034/2;
//  return distance1;
//}
//
//int findDist2(){
//  digitalWrite(trig2, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trig2, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trig2, LOW);
//  duration2 = pulseIn(echo2, HIGH);
//  distance2= duration2*0.034/2;
//  return distance2;
//}
//
//int findDist3(){
//  digitalWrite(trig3, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trig3, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trig3, LOW);
//  duration3 = pulseIn(echo3, HIGH);
//  distance3= duration3*0.034/2;
//  return distance3;
//}
