void encoder_setup() {

  pinMode(encoderPin1X, INPUT);
  pinMode(encoderPin2X, INPUT);
  pinMode(encoderPin1Y, INPUT);
  pinMode(encoderPin2Y, INPUT);


  digitalWrite(encoderPin1X, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin2X, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin1Y, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin2Y, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) ,interrupt 3(pin 20),interrupt 4(pin 19)
  attachInterrupt(0, updateEncoderX, CHANGE);
  attachInterrupt(1, updateEncoderX, CHANGE);
  attachInterrupt(4, updateEncoderY, CHANGE);
  attachInterrupt(3, updateEncoderY, CHANGE);
  

}


void updateEncoderX(){
  int MSB = digitalRead(encoderPin1X); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2X); //LSB = least significant bit
 
  int encodedX = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sumX  = (lastEncodedX << 2) | encodedX; //adding it to the previous encoded value
 
  if(sumX == 0b1101 || sumX == 0b0100 || sumX == 0b0010 || sumX == 0b1011) encoderValueX ++;
  if(sumX == 0b1110 || sumX == 0b0111 || sumX == 0b0001 || sumX == 0b1000) encoderValueX --;
 
  lastEncodedX = encodedX;
  //Serial.println("jhol");
  x_enc=map(encoderValueX,0,48471,0,npix);//store this value for next time
}

void updateEncoderY(){
  int MSB = digitalRead(encoderPin1Y); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2Y); //LSB = least significant bit
 
  int encodedY = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sumY  = (lastEncodedY << 2) | encodedY; //adding it to the previous encoded value
 
  if(sumY == 0b1101 || sumY == 0b0100 || sumY == 0b0010 || sumY == 0b1011) encoderValueY ++;
  if(sumY == 0b1110 || sumY == 0b0111 || sumY == 0b0001 || sumY == 0b1000) encoderValueY --;
 
  lastEncodedY = encodedY; //store this value for next time
  y_enc=map(encoderValueY,0,48471,0,npix);
}

