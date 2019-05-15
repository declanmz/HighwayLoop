
void coneAvoidanceMeasures(){
  int sped = 120;
  
  while(findDist(0) < 15){
    drv.drive(-sped,-sped);
    Serial.println("Backwards");
  }
  while(findDist(1) > 30){
    drv.drive(-sped,sped);
    Serial.println("Left Turn");
  }
  delay(100);
  while(findDist(1) <= 30){
    drv.drive(-sped,sped);
    Serial.println("Left Turn");
  }
  while(findDist(2) > 30){
    drv.drive(sped,sped);
    Serial.println("Forward");
  }
  delay(100);
  while(findDist(2) <= 30){
    drv.drive(sped,sped);
    Serial.println("Forward");
  }
  while(findDist(1) > 30){
    drv.drive(sped,-sped);
    Serial.println("Right Turn");
  }
  while(findDist(2) > 30){
    drv.drive(sped,sped);
    Serial.println("Forward");
  }
  delay(100);
  while(findDist(2) <= 30){
    drv.drive(sped,sped);
    Serial.println("Forward");
  }
  delay(100);
  while(findDist(2) > 30){
    drv.drive(sped,-sped);
    Serial.println("Right Turn");
  }
  delay(100);
  while(findDist(2) <= 30){
    drv.drive(sped,-sped);
    Serial.println("Right Turn");
  }
  while(findDist(2) > 30){
    drv.drive(sped, sped*.75);
    Serial.println("Right Veer");
  }
  lineSense();
  while(!sB[7] && !sB[6]){
    lineSense();
    drv.drive(sped,sped);
    Serial.println("Forward");
  }
  
}
