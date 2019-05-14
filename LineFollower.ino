void rightLineFollow() {
  lineSense();
  float spedMult;

  if(distance[0] > 25){
    spedMult = .7;
  }else if(distance[0] <= 25 && distance[0] > 16){
    spedMult = float(distance[0]);
    map(spedMult, 16, 25, 0, .7);
  }else{
    spedMult = 0;
  }
  
  if (sB[0] && sB[7]) {
    drive(0, 0);
  } else if (!sB[3] && !sB[4] && !sB[5] && !sB[6] && !sB[7]) {
    drive(250*spedMult, -100*spedMult);
  } else if (sB[3]) {
    drive(-250*spedMult, 250*spedMult);
  } else if (sB[4]) {
    drive(-150*spedMult, 250*spedMult);
  } else if (sB[5]) {
    drive(50*spedMult, 250*spedMult);
  } else if (sB[6]) {
    drive(200*spedMult, 250*spedMult);
  } else if (sB[7]) {
    drive(250*spedMult, 250*spedMult);
  }
}
