
void coneAvoidanceMeasures(){
  int sped = 120;
  
  while(rbt.findDist(0) < 15){
    rbt.drive(-sped,-sped);
    Serial.println("Backwards");
  }
  while(rbt.findDist(1) > 30){
    rbt.drive(-sped,sped);
    Serial.println("Left Turn");
  }
  delay(100);
  while(rbt.findDist(1) <= 30){
    rbt.drive(-sped,sped);
    Serial.println("Left Turn");
  }
  while(rbt.findDist(2) > 30){
    rbt.drive(sped,sped);
    Serial.println("Forward");
  }
  delay(100);
  while(rbt.findDist(2) <= 30){
    rbt.drive(sped,sped);
    Serial.println("Forward");
  }
  while(rbt.findDist(1) > 30){
    rbt.drive(sped,-sped);
    Serial.println("Right Turn");
  }
  while(rbt.findDist(2) > 30){
    rbt.drive(sped,sped);
    Serial.println("Forward");
  }
  delay(100);
  while(rbt.findDist(2) <= 30){
    rbt.drive(sped,sped);
    Serial.println("Forward");
  }
  delay(100);
  while(rbt.findDist(2) > 30){
    rbt.drive(sped,-sped);
    Serial.println("Right Turn");
  }
  delay(100);
  while(rbt.findDist(2) <= 30){
    rbt.drive(sped,-sped);
    Serial.println("Right Turn");
  }
  while(rbt.findDist(2) > 30){
    rbt.drive(sped, sped*.75);
    Serial.println("Right Veer");
  }
  lineSense();
  while(!sB[7] && !sB[6]){
    lineSense();
    rbt.drive(sped,sped);
    Serial.println("Forward");
  }
  
}
