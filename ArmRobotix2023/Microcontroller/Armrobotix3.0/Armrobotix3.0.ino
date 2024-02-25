#include <Servo.h>

#define lin1 6
#define lin2 5
#define rin1 3
#define rin2 11

#define PIN_TRIG A5
#define PIN_ECHO A4
#define PIN_TRIGr 7
#define PIN_ECHOr 8
#define PIN_TRIGl 9
#define PIN_ECHOl 10

#define S3 A3
#define S2 A2
#define S1 A1
#define S0 A0
#define sensorOut 13

#define kuler 2
Servo servo1;
Servo servo2;

int servo_last_position = 90;

int frequency = 0;
int lastcolor;

char res;

int dist = 16;
void setup() {
  Serial.begin(9600);

  servo2.attach(12);
  servo1.attach(4);
  servo1.write(0);
  servo2.write(90);
  
  // delay(1000);
  // servo_rotate(180,30);

  pinMode(rin1, OUTPUT);
  pinMode(rin2, OUTPUT);
  pinMode(lin1, OUTPUT);
  pinMode(lin2, OUTPUT);
  
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_TRIGr, OUTPUT);
  pinMode(PIN_ECHOr, INPUT);
  pinMode(PIN_TRIGl, OUTPUT);
  pinMode(PIN_ECHOl, INPUT);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  pinMode(kuler, OUTPUT);

  
  digitalWrite(S0,1);
  digitalWrite(S1,LOW);
  delay(10000);
  lastcolor = color();

  int distf;
  int distr;
  int distl;

  bool fl = 0;
  // delay(10000);
  // Serial.println('2');
  while (1){
    break;
  // Serial.println('2');
    Serial.println(disstance_L());
    // int a = color();
    // Serial.print(a);Serial.print(" ");Serial.print(abs(a - lastcolor));Serial.print(" ");Serial.println(lastcolor);
  }
dist = 13;
  while(1){
    // break;    
    
    go_f(60,60);
    int distl = disstance_L();
    while(distl < dist-1 and distl != 0){
      if(abs(color() - lastcolor) > 150){
        fl = 1; break;
      }
      distl = disstance_L();
      go_b(0,65);
    } 
    while(distl > dist+2 or distl == 0){
      if(abs(color() - lastcolor) > 150){
        fl = 1; break;
      }
      distl = disstance_L();
      go_b(65,0);
    }

    if(abs(color() - lastcolor) > 150){ fl = 1; }

    if(fl ==1 ){
      fl = 0;
      stop();
      delay(500);
      corect();
      delay(500);
      go_f(72,70);
      delay(500);
      stop();
      delay(500);

      stop();
    
      servo1.write(30);
      servo_rotate(180,30);
      servo1.write(180);
      delay(2000);
      Serial.println('1');
      while(1){
        if(Serial.available()){
          res = Serial.read();
          if (res == '2'){
            break;
          }
        }
      }
      servo1.write(30);
      delay(20000);
      servo_rotate(0,30);
      servo1.write(180);
      delay(2500);
      Serial.println('1');
      while(1){
        if(Serial.available()){
          res = Serial.read();
          if (res == '2'){
            break;
          }
        }
      }
      servo1.write(30);
      delay(20000);
      servo_rotate(90,30);
      servo1.write(0);
      delay(1000);

      go_f(70,65);
      delay(600);
      stop();
      // // break;

      // while (1) {
      //   distf = disstance_F();
      //   if((distf < 18 and distf != 0) or disstance_L() < dist-2){
      //     break;
      //   }
      //   go();
      // }
      stop();
      break;
    }

  }

  

  dist = 16;
  while(1){
    // break;
    go();
    distf = disstance_F();
    if(distf < 18 and distf != 0){
      stop();
      delay(500);
      while(disstance_F() < 13){
        go_b(70,70);
      }
      stop();
      delay(500);
      
      distf = disstance_F();
      while(distf < 80){
        distf = disstance_F();
        go_f(130,0);
      }
      stop();
      dist += 4;
      break;
    }
  }
  delay(1000);
  
  // dist += 5;
  while(1){
    // break;
    go();
    distf = disstance_F();
    if(distf < 55){
      stop();
      delay(500);
      dist = 16;
      while(1){
        
        go2();
        if (disstance_F() < 18){
          distf = disstance_F();
          
          stop();
          delay(500);

          while(disstance_F() < 10){
            go_b(65,65);
          }
          stop();
          delay(500);

          distf = disstance_F();
          while(distf < 80){
            distf = disstance_F();
            go_f(0,130);
          }
          // // dist+=5;
          stop();
          
          break;
          
        }
      }
      stop();
      // delay(500);

      // while(disstance_F() < 10){
      //   go_b(65,65);
      // }
      // stop();
      // delay(500);

      // distf = disstance_F();
      // while(distf < 80){
      //   distf = disstance_F();
      //   go_f(0,100);
      // }
      // stop();
      // delay(500);
      break;
    }
  }
  
  delay(1000);
  lastcolor = color();
fl = 0;
dist = 19;
  while(1){
    // break;
    
    go_f(60,60);
    int distr = disstance_R();
    // int distl = disstance_L();
    while(distr < dist-1 and distr != 0){
      if(abs(color() - lastcolor) > 200){
        fl = 1; break;
      }
      distr = disstance_R();
      go_b(65,0);
    }
    while(distr > dist+2 or distr == 0){
      if(abs(color() - lastcolor) > 200){
        fl = 1; break;
      }
      distr = disstance_R();
      go_b(0,65);
      
    }
    
    dist = 18;
    
    if(abs(color() - lastcolor) > 200){ fl = 1; }

    if(fl ==1 ){
      fl = 1;
      stop();
      delay(500);
      // corect();
      // delay(500);
      go_f(70,60);
      delay(370);
      go_f(65,0);
      delay(250);
      stop();

      digitalWrite(kuler,1);
      servo_rotate(0,80);
      delay(500);
      servo_rotate(90,80);
      digitalWrite(kuler,0);

      go_b(65,0);
      delay(320);
      stop();

      break;
    }
  }
dist = 16;
  
  while (1)
  {
    // break;
    go2();
    distf = disstance_F();
    if(distf < 17){
      stop();
      delay(500);
      
      while(disstance_F() < 10){
        go_b(65,65);
      }
      stop();
      delay(500);

      distf = disstance_F();
      while(distf < 80){
        distf = disstance_F();
        go_f(0,100);
      }
      stop();
      delay(500);

      while (1) {
        go2();
        distf = disstance_F();
        if(distf < 55){
          stop();
          break;
        }
      }
      break;
    }
  }
  
  while (1) {
    // break;
    go();

    distf = disstance_F();
    if(distf < 17){
      stop();
      delay(500);
      
      while(disstance_F() < 13){
        go_b(65,65);
      }

      stop();
      delay(500);

      distf = disstance_F();
      while(distf < 80){
        distf = disstance_F();
        go_f(140,0);
      }
      stop();
      delay(500);
      break;
    }
  }
  dist+=1;
  delay(1000);
  lastcolor = color();
fl = 0;

  while (1){
    
    go_f(60,60);
    // int distr = disstance_R();
    int distl = disstance_L();
    // Serial.println(distl);
    while(distl < dist-1 and distl != 0){
      if(abs(color() - lastcolor) > 150){
        fl = 1; break;
      }
      distl = disstance_L();
      // Serial.println(distl);
      go_b(0,65);
    } 
    while(distl > dist+2 or distl == 0){
      if(abs(color() - lastcolor) > 150){
        fl = 1; break;
      }
      distl = disstance_L();
      // Serial.println(distl);
      go_b(65,0);
    }
    if (disstance_R() < 17 ){
      dist = 14;
    }
  if(abs(color() - lastcolor) > 150){ fl = 1; }

  if(fl ==1 ){
      fl = 0;
      stop();
      go_f(70,70);
      delay(600);
      stop();
      delay(500);
      dist = 16;
      // corect();
      delay(1000);

      Serial.println('2');
      // while(1){
      //   if(Serial.available()){
      //     res = Serial.read();
      //     if (res == '2'){
      //       break;
      //     }
      //   }
      // }

      delay(25000);

      fl = 0;

      while (1){
        go_f(60,60);
        // int distr = disstance_R();
        int distl = disstance_L();
        if(disstance_L() < 50 or fl == 1){
            break;
        }
        // Serial.println(distl);
        while(distl < dist-1 and distl != 0){
          if(disstance_L() < 50){
            fl = 1;
          }
          distl = disstance_L();
          // Serial.println(distl);
          go_b(0,65);
        } 
        while(distl > dist+2 or distl == 0){
          if(disstance_L() < 50){
            fl = 1;
          }
          distl = disstance_L();
          // Serial.println(distl);
          go_b(65,0);
        }
      }
      stop();
      delay(1000);
      while (disstance_F() > 17){
        go_f(70,70);
      }

      stop();
      delay(500);
      while(disstance_F() < 10){
        go_b(65,65);
      }
      stop();
      delay(500);

      distf = disstance_F();
      while(distf < 70){
        distf = disstance_F();
        go_f(0,130);
      }

      stop();
      delay(500);
      break;
  }
    
  }

  dist = 16;
  while (1){
    go2();
    distf = disstance_F();
    if(distf < 17){
      stop();
      delay(500);
      
      while(disstance_F() < 10){
        go_b(65,65);
      }
      stop();
      delay(500);

      distf = disstance_F();
      while(distf < 80){
        distf = disstance_F();
        go_f(0,130);
      }
      stop();
      delay(500);
      break;
    }
  }
  
  while (disstance_L() > 20) {
    go2();
  }
  stop();
 

}

void loop() {
  // go();
  // disstance_R();
  // Serial.println(disstance_R());
  // Serial.print(" ");Serial.print(disstance_R());Serial.print(" ");Serial.println(disstance_F());
  // int a = color();
  // Serial.print(a);Serial.print(" ");Serial.print(abs(a - lastcolor));Serial.print(" ");Serial.println(lastcolor);
  // go_f(60,60);

  // go2();
}


void go(){
  go_f(60,60);
  // int distr = disstance_R();
  int distl = disstance_L();
  // Serial.println(distl);
  while(distl < dist-1 and distl != 0){
    distl = disstance_L();
    // Serial.println(distl);
    go_b(0,65);
  } 
  while(distl > dist+2 or distl == 0){
    distl = disstance_L();
    // Serial.println(distl);
    go_b(65,0);
  }
}

void go2(){
  go_f(60,60);
  int distr = disstance_R();
  // Serial.println(distr);
  // int distl = disstance_L();
  while(distr < dist-1 and distr != 0){
    distr = disstance_R();
    go_b(65,0);
    // Serial.println(distr);
  }
  while(distr > dist+2 or distr == 0){
    distr = disstance_R();
    go_b(0,65);
    // Serial.println(distr);
  }
}
void corect(){
  int distl = disstance_L();
  // int distl = disstance_L();
  while(distl < dist and distl != 0){
    distl = disstance_L();
    go_b(0,50);
  }
  while(distl > dist or distl == 0){
    distl = disstance_L();
    go_b(50,0);
  }
  stop();
}
void corect2(){
  int distr = disstance_R();
  // int distl = disstance_L();
  while(distr < 16 and distr != 0){
    distr = disstance_R();
    go_b(50,0);
  }
  while(distr > 16 or distr == 0){
    distr = disstance_R();
    go_b(0,50);
  }
  stop();
}


int color(){
  int res = 0;
    // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  res+=frequency;
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  res+=frequency;
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  res+=frequency;
  // Serial.print(res);Serial.println(" ");
  return res;
}

int disstance_F(){
  
  digitalWrite(PIN_TRIG, 0);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, 1);

  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, 0);
  
  int di = (pulseIn(PIN_ECHO, HIGH) / 2) / 29.1;
  delay(10);
  
  return di;
}
int disstance_R(){
  
  digitalWrite(PIN_TRIGr, 0);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIGr, 1);

  delayMicroseconds(10);
  digitalWrite(PIN_TRIGr, 0);
  
  int di = (pulseIn(PIN_ECHOr, HIGH) / 2) / 29.1;
  delay(10);
  
  return di;
}
int disstance_L(){
  
  digitalWrite(PIN_TRIGl, 0);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIGl, 1);

  delayMicroseconds(10);
  digitalWrite(PIN_TRIGl, 0);
  int di = (pulseIn(PIN_ECHOl, HIGH) / 2) / 29.1;
  delay(10);
    
  
  return di;
}

void stop(){
  analogWrite(lin1, 1);
  analogWrite(lin2, 1);
  analogWrite(rin1, 1);
  analogWrite(rin2, 1);
}
void go_f(int Speedl, int Speedr){
  analogWrite(lin1, 0);
  analogWrite(lin2, Speedl+15);
  analogWrite(rin1, 0);
  analogWrite(rin2, Speedr);
}
void go_b(int Speedl, int Speedr){
  analogWrite(lin1, Speedl+15);
  analogWrite(lin2, 0);
  analogWrite(rin1, Speedr);
  analogWrite(rin2, 0);
}
void go_l(int Speedl, int Speedr){
  analogWrite(lin1, 0);
  analogWrite(lin2, Speedl+15);
  analogWrite(rin1, Speedr);
  analogWrite(rin2, 0);
}
void go_r(int Speedl, int Speedr){
  analogWrite(lin1, Speedl+15);
  analogWrite(lin2, 0);
  analogWrite(rin1, 0);
  analogWrite(rin2, Speedr);
}

int servo_rotate(int angle,int speed){
  if(angle < 0 and angle > 180){
    return 0;
  } 
  
  int dist = angle-servo_last_position;
  int n = dist/abs(dist);
  
  if(n > 0){
    for(servo_last_position; servo_last_position <= angle; servo_last_position+=n){
      // Serial.println(servo_last_position);
      servo2.write(servo_last_position);
      delay(speed);
    }
  }else 
  if(n < 0){
    for(servo_last_position; servo_last_position >= angle; servo_last_position+=n){
      // Serial.println(servo_last_position);
      servo2.write(servo_last_position);
      delay(speed);      
    }
  }
}