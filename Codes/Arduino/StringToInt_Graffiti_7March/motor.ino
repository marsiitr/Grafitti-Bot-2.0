//**************SET PWM AS REQUIRED***************************
void motor_setup ()
{
  pinMode(mX_dir1, OUTPUT);
  pinMode(mX_dir2, OUTPUT);
  pinMode(mX_pwm, OUTPUT);
  pinMode(mY_dir1, OUTPUT);
  pinMode(mY_dir2, OUTPUT);
  pinMode(mY_pwm, OUTPUT);

}
void mov(int x, int y)
{
  while (x > x_enc)
  {
    digitalWrite (mX_dir1, LOW);
    digitalWrite (mX_dir2, HIGH);
    analogWrite (mX_pwm, 250);
    Serial.print("x: ");Serial.println(x_enc);
    //delay(50);
  }
 
  while (x < x_enc)
  { 
    digitalWrite (mX_dir1, HIGH);
    digitalWrite (mX_dir2, LOW);
    analogWrite (mX_pwm, 250);
   Serial.print("x :");Serial.println(x_enc);
//   delay(1000);
  }
  digitalWrite (mX_dir1, HIGH);
  digitalWrite (mX_dir2, HIGH);
  //Serial.print("x :");Serial.println(x_enc);
  delay(1000);

//  Serial.print("up :");
//  Serial.print(y_enc);
  while (y>y_enc)
  { digitalWrite (mY_dir1, HIGH);
    digitalWrite (mY_dir2, LOW);
    analogWrite (mY_pwm, 200);
    //Serial.print("y :");Serial.println(y_enc);
//   delay(1000);
  }

  Serial.print("down :");
//  Serial.print(y_enc);
  while(y<y_enc)
  { digitalWrite (mY_dir1, LOW);
    digitalWrite (mY_dir2, HIGH);
    analogWrite (mY_pwm, 200);
    //Serial.print("y :");Serial.println(y_enc);
    //delay(50);
  }
  digitalWrite (mY_dir1, HIGH);
  digitalWrite (mY_dir2, HIGH);
  Serial.print("y :");Serial.println(y_enc);
  //delay(50);
}



