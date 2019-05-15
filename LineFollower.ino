void rightLineFollow() {
  lineSense();
  float spedMult;
  float dist0 = rbt.findDist(0);

  if(dist0 > 25){
    spedMult = .7;
  }else if(dist0 <= 25 && dist0 > 16){
    spedMult = float(dist0);
    map(spedMult, 16, 25, 0, .7);
  }else{
    spedMult = 0;
  }
  
  if (sB[0] && sB[7]) {
    rbt.drive(0, 0);
  } else if (!sB[3] && !sB[4] && !sB[5] && !sB[6] && !sB[7]) {
    rbt.drive(250*spedMult, -100*spedMult);
  } else if (sB[3]) {
    rbt.drive(-250*spedMult, 250*spedMult);
  } else if (sB[4]) {
    rbt.drive(-150*spedMult, 250*spedMult);
  } else if (sB[5]) {
    rbt.drive(50*spedMult, 250*spedMult);
  } else if (sB[6]) {
    rbt.drive(200*spedMult, 250*spedMult);
  } else if (sB[7]) {
    rbt.drive(250*spedMult, 250*spedMult);
  }
}
