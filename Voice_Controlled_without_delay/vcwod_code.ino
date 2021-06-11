int motor1a=8;      //Declaring motor pins from motor driver circuit.
int motor1b=9;
int motor2a=10;
int motor2b=11;

void setup() {
  // put your setup code here, to run once:
pinMode(motor1a,OUTPUT);                        //Setting up the status of Motor pins.
pinMode(motor1b,OUTPUT);
pinMode(motor2a,OUTPUT);
pinMode(motor1b,OUTPUT);

Serial.begin(9600);                            //To start the commuication at this baud rate.
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available())                      //If there is anything in the buffer, perform the following actions. 
{ delay(10);                                   //wait for 10 milliseconds.
  String ch = Serial.readStringUntil('#');     //Read the data in string format until you encounter the character inside ' ' .

  if(ch=="*forward"){                          //If the string is *forward then make the car go forward until a new voice command is given.
    go_forward();
  }
  else if(ch=="*backward"){                   //If the string is *backward then make the car go backward until a new voice command is given.
    go_backward();
  }
  else if(ch=="*left"){                     //If the string is *left then turn the car left.[delay(500),rest() can be added for a proper control over the car]
    turn_left();
  }
  else if(ch=="*right"){                    //If the string is *right then turn the car right.[delay(500),rest() can be added for a proper control over the car.
    turn_right();
  }
if (ch=="*stop"){                          //If the string is *stop then stop the car.
  rest();
}
else {                                      //If the string is not any of the above mentioned commands then remain in rest position.[Mostly happens because of the fault in voice to text conversion]
  rest();
}
}
}
//end void loop

void go_forward(){                        //A function for the car to move forward, both motors are ON and going in anti-clockwise direction. 
  digitalWrite(motor1a,LOW);              //The configuration of LOW,HIGH can vary depending on the circuit made with motor driver and motors. 
  digitalWrite(motor1b,HIGH);
  digitalWrite(motor2a,LOW);
  digitalWrite(motor2b,HIGH);
}
void go_backward(){                      //A function for the car to move backward, both motors are ON and going in clockwise direction.
  digitalWrite(motor1a,HIGH);             
  digitalWrite(motor1b,LOW);
  digitalWrite(motor2a,HIGH);
  digitalWrite(motor2b,LOW);
}
void turn_left(){                       //A function for the car to move left, Left motor is OFF and Right motor is ON.
  digitalWrite(motor1a,HIGH);
  digitalWrite(motor1b,HIGH);
  digitalWrite(motor2a,LOW);
  digitalWrite(motor2b,HIGH);
}
void turn_right(){                     //A function for the car to move right, Left motor is ON and Right motor is OFF. 
  digitalWrite(motor1a,LOW);
  digitalWrite(motor1b,HIGH);
  digitalWrite(motor2a,HIGH);
  digitalWrite(motor2b,HIGH);
}
void rest(){                           //A function for the car to be a rest, Both motors are OFF. Either all are LOW or all are HIGH.
  digitalWrite(motor1a,LOW);
  digitalWrite(motor1b,LOW);
  digitalWrite(motor2a,LOW);
  digitalWrite(motor2b,LOW);
}
