/*
  String to Integer conversion

  Reads a serial input string until it sees a newline, then converts the string
  to a number if the characters are digits.

  The circuit:
  - No external components needed.

  created 29 Nov 2010
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/StringToInt
*/

#include <Servo.h>

#define servopin 11
#define npix 150
#define encoderPin1X  3
#define encoderPin2X  2
#define encoderPin1Y 19
#define encoderPin2Y 20
Servo myservo;

String inStringX = ""; 
String inStringY = "";
String inStringC = "";// string to hold input
int x=0;int y=0;int c=0;
char d='0';
int i=0;


volatile int lastEncodedX = 0;
volatile long encoderValueX = 0;
volatile int lastEncodedY = 0;
volatile long encoderValueY = 0;


long lastencoderValueX = 0;
long lastencoderValueY = 0;


int lastMSBX = 0;
int lastLSBX = 0;
int lastMSBY = 0;
int lastLSBY = 0;



//for motors
int x_enc = 0;
int y_enc = 0;
int spray_on = 0;
int spray_off = 30;
//int pwm_x=180;
//int pwm_y=180;
int mX_dir1 = 4;
int mX_dir2 = 5;
int mX_pwm = 6;   //pins from 2 to 13 works as pwm pins in mega 2560
int mY_dir1 = 8;
int mY_dir2 = 7;
int mY_pwm = 9;

void spray(){
  myservo.write(spray_on);
  delay(1500);
  myservo.write(spray_off);
  
}
void setup() {
  myservo.attach(servopin);
  myservo.write(spray_off);
  encoder_setup();
  motor_setup ();
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  /*while (!Serial) {
      // send a capital A
       // wait for serial port to connect. Needed for native USB port only
  }*/

  // send an intro:
//  Serial.println("\n\nString toInt():");
//  Serial.println();
  Serial.println('A');
  pinMode(13, OUTPUT);
  
  
  
}

void loop() {
  // Read serial input:
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    d=(char)inChar;
    if (isDigit(inChar)&& i==0) {
      // convert the incoming byte to a char and add it to the string:
      inStringX += d;
    }
     if(d=='#'){
      if(i==0){
      i=1;
      inChar=Serial.read();
      d=(char)inChar;
      }
      else {
       i=2; 
       inChar=Serial.read();
       d=(char)inChar;
      }
    }
      if (isDigit(inChar)&& i==1){
      // convert the incoming byte to a char and add it to the string:
      inStringY += d;
    }
    if (isDigit(inChar)&& i==2) {
      // convert the incoming byte to a char and add it to the string:
      inStringC += d;
    }
    // if you get a newline, print the string, then the string's value:
    if (inChar == '\n') {
      x=inStringX.toInt();y=inStringY.toInt();c=inStringC.toInt();
     
      Serial.print("Start ");
      Serial.print(x);
      Serial.print(" ");
      Serial.println(y);
      mov(x,y);

         if(c==0)
         spray();

      inStringX = "";inStringY = "";inStringC = "";
      i=0;
      Serial.println('A');
     // Serial.println('A');
     delay(200);
    } 
  }
}

