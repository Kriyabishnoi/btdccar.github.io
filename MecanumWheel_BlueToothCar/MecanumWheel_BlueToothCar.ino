#include <AFMotor.h>


//Arduino Bluetooth App Control Mecanum Wheel Robot
//Download and Install AFMotor.h Library

AF_DCMotor motor1(1); //Front Left Wheel
AF_DCMotor motor2(2); //Back Left Wheel
AF_DCMotor motor3(3); //Front Right Wheel
AF_DCMotor motor4(4); //Back Right Wheel

String readString;

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(250);   //Set Motor Speed
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);
    
}

void loop() {
//  while(Serial.available()){
//    delay(50);
//    char c=Serial.read();
//    readString+=c;
//  }
  if(Serial.available()>0){
     char c=Serial.read();
      if(c!='S'){
   Serial.println(c);
   readString.trim();
    if (c =='F'){      // MOVE FORWARD
      Serial.println("IN");
      motor1.run (FORWARD);
      motor2.run (FORWARD);
      motor3.run (FORWARD);
      motor4.run (FORWARD);
    }
    if (c =='B'){     // MOVE BACKWARD
      motor1.run (BACKWARD);
      motor2.run (BACKWARD);
      motor3.run (BACKWARD);
      motor4.run (BACKWARD);
    }
    if (c =='L'){     // MOVE LEFT SIDE
      motor1.run (BACKWARD);
      motor2.run (BACKWARD);
      motor3.run (FORWARD);
      motor4.run (FORWARD);
    }
    if (c=='R'){     // MOVE RIGHT SIDE
      motor1.run (FORWARD);
      motor2.run (FORWARD);
      motor3.run (BACKWARD);
      motor4.run (BACKWARD);
    }
//    if (readString =="FORWARDLEFT"){     // MOVE FORWARD LEFT
//      motor1.run (RELEASE);
//      motor2.run (FORWARD);
//      motor3.run (FORWARD);
//      motor4.run (RELEASE);
//    }
//    if (readString =="FORWARDRIGHT"){     // MOVE FORWARD RIGHT
//      motor1.run (FORWARD);
//      motor2.run (RELEASE);
//      motor3.run (RELEASE);
//      motor4.run (FORWARD);
//    }
    if (readString =="BACKWARDLEFT"){     // MOVE BACKWARD LEFT
      motor1.run (BACKWARD);
      motor2.run (RELEASE);
      motor3.run (RELEASE);
      motor4.run (BACKWARD);
    }
    if (readString =="BACKWARDRIGHT"){     // MOVE BACKWARD RIGHT
      motor1.run (RELEASE);
      motor2.run (BACKWARD);
      motor3.run (BACKWARD);
      motor4.run (RELEASE);
    }
    if (readString =="ROTATELEFT"){     // ROTATE LEFT SIDE
      motor1.run (BACKWARD);
      motor2.run (BACKWARD);
      motor3.run (FORWARD);
      motor4.run (FORWARD);
    }
    if (readString =="ROTATERIGHT"){     // ROTATE RIGHT SIDE
      motor1.run (FORWARD);
      motor2.run (FORWARD);
      motor3.run (BACKWARD);
      motor4.run (BACKWARD);
    }
    if (readString =="STOP"){     // STOP
      motor1.run (RELEASE);
      motor2.run (RELEASE);
      motor3.run (RELEASE);
      motor4.run (RELEASE);
    }

    readString="";
      }
  }
}
