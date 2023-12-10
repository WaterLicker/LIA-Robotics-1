/*  
This code is a remade version of the line-tracker
by elegoo. The goal is to bring the understanding of implementing
a sensor and implementing flow charts to the understanding
of coding.
*/
void forward(int x){        // goes forward

    digitalWrite(7, 1);     //right motor (same direction as left)
    analogWrite(5, x);      //speed for left motor
    digitalWrite(8, 1);     //left motor (same direction as right)
    analogWrite(6, x);      //speed for rightr motor
}
void back(int x){      // goes backwards

    digitalWrite(7, 0);     //right motor goes back
    analogWrite(5, x);      
    digitalWrite(8, 0);     //left motor goes back
    analogWrite(6, x);
}
void left(int x){           // goes left

    digitalWrite(7, 1);     //right motor is forward
    analogWrite(5, x);
    digitalWrite(8, 0);     //left motor is backwards
    analogWrite(6, x);
}
void right(int x){          // goes right

    digitalWrite(7, 0);     //right motor is backwards
    analogWrite(5, x);
    digitalWrite(8, 1);     //left motor is forwards
    analogWrite(6, x);
}
void leftforward(int x){    // goes left and forwards

    digitalWrite(7, 1);     //right motor is forwards
    analogWrite(5, x);      // speed is regular
    digitalWrite(8, 1);     //left motor is forwards
    analogWrite(6, x/2);    // speed is halfed
}
void rightforward(int x){   // goes right and forwards

    digitalWrite(7, 1);     //right motor is forwards
    analogWrite(5, (x/2));  // speed is halfed
    digitalWrite(8, 1);     //left motor is forwards
    analogWrite(6, x);      // speed is regular
}
void leftback(int x){   // left and backwards

    digitalWrite(7, 0);     //right motor is backwards
    analogWrite(5, x);      // speed is regular
    digitalWrite(8, 0);     //left motor is backwards
    analogWrite(6, x/2);    // speed is halfed
}
void rightback(int x){  // right and backwards

    digitalWrite(7, 0);     //right motor is backwards
    analogWrite(5, x/2);    // speed is halfed
    digitalWrite(8, 0);     //left motor is backwards
    analogWrite(6, x);      // speed regular
}
void stopping(){              //stop

    digitalWrite(7, 0);     //right motor is off
    analogWrite(5, 0);      // speed is off
    digitalWrite(8, 0);     //left motor is off
    analogWrite(6, 0);      // speed is off
}


void setup() { 

  // put your setup code here, to run once: 

Serial.begin(9600); //initalize the serial monitor

  

int right = analogRead(A0); //right sensor value

int middle = analogRead(A1); //middle sensor value

int left = analogRead(A2); //left sensor value

} 

void loop() { 

  // put your main code here, to run repeatedly: 

Serial.println(analogRead(A0)); //prints value of right sensor

Serial.println(analogRead(A1)); //prints value of middle sensor

Serial.println(analogRead(A2)); //prints value of left sensor 

if (analogRead(A0) >= 760 && analogRead(A1) >= 760 && analogRead(A2) >= 760) {     // when value of all sensor >=760 stop movement     

    // suspended in air 
stopping() //stops moving until condition is not met

} 

if (analogRead(A1) >= 150 && analogRead(A1) <= 750) { 

// middle detects go forward 

forward(40) //forward until condition is not met

} 

if (analogRead(A0) <= 150 && analogRead(A1) >= 150 && analogRead(A1) <= 750 && analogRead(A2) <= 750 && analogRead(A2) >= 150) {  

// right no detect and middle no detect turn left 

left(40) //left until condition is not met

} 

if (analogRead(A0) >= 150 && analogRead(A0) <= 750 && analogRead(A1) >= 150 && analogRead(A1) <= 750&& analogRead(A2) <= 150) {  

// left no detect and middle no detect turn right 

right(40)  //right until condition is not met

} 

if (analogRead(A0) <= 50 && analogRead(A1) <= 50 && analogRead(A2) <= 50) { 

 // left no detect and right no detect turn right 

right(40) //right until condition is not met

} 

} 

 
