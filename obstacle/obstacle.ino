/* this is a remade version of the obstacle avoidance by elegoo. */

# include <Servo.h>

#define Ltrack A2
#define Mtrack A1
#define Rtrack A0
#define trig 13
#define echo 12
#define servo 10

float cm;
Servo myservo;

void forward(int x){  /* creates function to have left motors and right motors moving in the
same direction (forward) at the same speed*/

    digitalWrite(7, 1);
    analogWrite(5, x);
    digitalWrite(8, 1);
    analogWrite(6, x);
}
void back(int x){   /* creates function to have left motors and right motors moving in the
same direction (backwards) at the same speed*/
 
    digitalWrite(7, 0);
    analogWrite(5, x);
    digitalWrite(8, 0);
    analogWrite(6, x);
}
void left(int x){     /* creates function to have left motors going backwards and right motors
going forward at the same speed*/
 
    digitalWrite(7, 1);
    analogWrite(5, x);
    digitalWrite(8, 0);
    analogWrite(6, x);
}
void right(int x){   /* creates function to have left motors going forward and right motors
going backwards at the same speed*/
 
    digitalWrite(7, 0);
    analogWrite(5, x);
    digitalWrite(8, 1);
    analogWrite(6, x);
}
void leftforward(int x){   /* creates function to have left and right motors going forward but
having the left motor going half the speed*/
 
    digitalWrite(7, 1);
    analogWrite(5, x);
    digitalWrite(8, 1);
    analogWrite(6, x/2);
}
void rightforward(int x){  /* creates function to have left and right motors going forward but
having the right motor going half the speed*/
 
    digitalWrite(7, 1);
    analogWrite(5, x/2);
    digitalWrite(8, 1);
    analogWrite(6, x);
}

void leftback(int x){    /* creates function to have left and right motors going backwards but
having the left motor going half the speed*/
 
    digitalWrite(7, 0);
    analogWrite(5, x);
    digitalWrite(8, 0);
    analogWrite(6, x/2);
}
void rightback(int x){    /* creates function to have left and right motors going backwards but
having the right motor going half the speed*/
 
    digitalWrite(7, 0);
    analogWrite(5, x/2);
    digitalWrite(8, 0);
    analogWrite(6, x);
}
void stopping(){     /* creates function to stop the car by having both motors at 0 speed */
 
    digitalWrite(7, 0);
    analogWrite(5, 0);
    digitalWrite(8, 0);
    analogWrite(6, 0);
}
void checkdist(){              //creates function to check distance with the ultrasonic

  digitalWrite(trig, LOW);        //writes pin 9 to LOW
  delayMicroseconds(2);        //delays it by 2 microseconds      
  digitalWrite(trig, HIGH);        //writes pin 9 to HIGH
  delayMicroseconds(20);        //delays it by 20 microseconds
  digitalWrite(trig, LOW);        //writes pin 9 to LOW
  float duration = pulseIn(echo, HIGH);         // floats "duration" and sets pin 13 to HIGH
  cm = (duration/58);                     //writes equation for the distance by dividing the duration by 58
  return(int)cm;                         //returns the value of DIST
}

int middle = 90;           //sets the angle of the servo (90°) to startpos
int lefts = 160;          //sets the angle of the servo (170°) to leftpos
int rights = 20;           //sets the angle of the servo (5°) to rightpos


void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);            
    pinMode(5, OUTPUT);     //sets pin 5 as an output
    pinMode(8, OUTPUT);     //sets pin 8 as an output
    pinMode(6, OUTPUT);     //sets pin 6 as an output
    pinMode(7, OUTPUT);     //sets pin 7 as an output
    pinMode(3, OUTPUT);     //sets pin 3 as an output
    digitalWrite(3, 1);      //turns on the motor
   pinMode(Ltrack, INPUT);  //sets A2 as an input
  pinMode(Mtrack, INPUT);   //sets A1 as an input
  pinMode(Rtrack, INPUT);   //sets A0 as an input
  pinMode(trig, OUTPUT);    // sets pin 13 as an output
  pinMode(echo, INPUT);     //sets pin 12 as an input
  myservo.attach(servo);    //attach servo pin to pin 10

}

void loop() {
  // put your main code here, to run repeatedly:

  int Lsensor = analogRead(Ltrack);  // read the left sensor
  int Msensor = analogRead(Mtrack);  // read the middle sensor
  int Rsensor = analogRead(Rtrack);  // read the right sensor

if (Lsensor, Msensor, Rsensor >= 1000) {  //if suspended in the air stops the robot
    stopping();
    delay(100);
   Serial.println("STOP");    
  
  
  
                                                              } else {  //if not suspended check the distance and check if statements
                                                              checkdist();
if (cm <=20) { //if detects in front stop turn servo left and scan
  stopping();
  delay(1000);
  myservo.write(lefts);
  delay(1000);
  checkdist();
                                if (cm  <=20) { //if detect left turn servo right and scan 
                                myservo.write(rights);
                                delay(1000);
                                checkdist();
                                                              if (cm  <=20) { //if detect right move back, left and turn servo to the middle and move forward
                                                              back(100);
                                                              delay(1000);
                                                              left(100);
                                                              delay(550);
                                                              myservo.write(middle);
                                                              delay(1000);
                                                              forward(150);
                                                               
                                                               
                                                                } else { // if no detect when servo is in right position turn right for 5 sec
                                                              myservo.write(middle);
                                                              delay(1000);
                                                              right(100);
                                                              delay(500);
                                                              }
                                  } else { // if no detect when servo is in left position turn left for 5 sec
                                  myservo.write(middle);
                                  delay(1000);
                                  left(100);
                                  delay(500);
                                  }
} else { //if no detect in front move forward
  forward(100);
}
  }
}   
