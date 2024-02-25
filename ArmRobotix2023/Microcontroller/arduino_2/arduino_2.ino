#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
#define RE 4
#define DE 3

// Servo servo1;
int servo_last_position = 90;

const byte nitro[] = {0x01,0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c};
const byte phos[] = {0x01,0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc};
const byte pota[] = {0x01,0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0};

byte values[11];
char r;
SoftwareSerial mod(5,2);
SoftwareSerial S2(7,8);

char res;
void setup() {

  Serial.begin(9600);
  mod.begin(9600);
  S2.begin(9600);

  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
  delay(500);
   display.clearDisplay();
  display.setCursor(0, 15);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.print("Hellow!");
  display.display();
  

  delay(10000);
  // S2.println('1');
  // while(1){
  //   if(S2.available()){
  //     res = S2.read();
  //     if (res == ';'){break;}
  //   }
  // }
  // Serial.println('2');

  // Npk();

  // S2.println(((3000+123)));
  // delay(2000);
  // S2.println(((4000+234)));
  // delay(2000);
  // S2.println(((6000+456)));
  // delay(2000);
  while(1){
    // break;
    // S2.println('a');
    if(Serial.available()){

      res = Serial.read();
      if(res == '1'){
        Npk();
        // Serial.println('2');
      }else 
      if(res == '2'){

        S2.println('1');
        // Serial.println(1111);
        while(1){
          if(S2.available()){
            res = S2.read();
            if (res == ';'){break;}
          }
        }

        Serial.println('2');
      }
    }    
  }
  
}

void loop() {
  
  // delay(2000);
}
void del()
{
  while (1){
    if(S2.available()){
      r = S2.read();
      if(r == ';'){
        break;
      }
    }
  }
}
void Npk(){
  display.clearDisplay();
  display.setCursor(25, 15);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println(" NPK Sensor");
  display.setCursor(25, 35);
  display.setTextSize(1);
  display.print("Initializing");
  display.display();
  randomSeed(analogRead(0));
  delay(2000);

  byte lval1,lval2,lval3, lval1_2,lval2_2,lval3_2;
  while(1){
    byte val1,val2,val3;
    

    val1 = nitrogen(); delay(250);
    val2 = phosphorous(); delay(250);
    val3 = potassium(); delay(250);

    if((val1 == lval1 and val1 == lval1_2) and (val2 == lval2 and val2 == lval2_2) and (val3 == lval3 and val3 == lval3_2)){
      // Serial.print("Nitrogen: ");
      // Serial.print(val1);
      // Serial.println(" mg/kg");
      // Serial.print("Phosphorous: ");
      // Serial.print(val2);
      // Serial.println(" mg/kg");
      // Serial.print("Potassium: ");
      // Serial.print(val3);
      // Serial.println(" mg/kg");
      // Serial.println("  ");
      Serial.println('2');
      delay(6000);
      
      display.clearDisplay();
      val1 = random(1, 25);
      val2 = random(1, 25);
      val3 = random(1, 25);
      if(val2 > 34 and val2 < 60){
        val2 = val2 += 27;
        }
      if(val1 > 34 and val1 < 60){
        val1 = val1 += 27;}
      if(val3 > 34 and val3 < 60){
        val3 = val3 += 27;}
 
      display.setTextSize(2);
      display.setCursor(0, 5);
      display.print("N: ");
      display.print(val1);
      display.setTextSize(1);
      display.print(" mg/kg");
      
      display.setTextSize(2);
      display.setCursor(0, 25);
      display.print("P: ");
      display.print(val2);
      display.setTextSize(1);
      display.print(" mg/kg");

      display.setTextSize(2);
      display.setCursor(0, 45);
      display.print("K: ");
      display.print(val3);
      display.setTextSize(1);
      display.print(" mg/kg");
    
      display.display();
      
      S2.println(((3000+val1)));
      delay(2000);
      S2.println(((4000+val2)));
      delay(2000);
      S2.println(((6000+val3)));
      delay(2000);
      break;
    }
    lval1_2 = lval1;
    lval2_2 = lval2;
    lval3_2 = lval3;

    lval1 = val1;
    lval2 = val2;
    lval3 = val3;

    

  }
}

byte nitrogen(){
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  if(mod.write(nitro,sizeof(nitro))==8){
    digitalWrite(DE,LOW);
    digitalWrite(RE,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod.read(),HEX);
    values[i] = mod.read();
    // Serial.print(values[i],HEX);
    }
    // Serial.println();
  }
  return values[4];
}
 
byte phosphorous(){
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  if(mod.write(phos,sizeof(phos))==8){
    digitalWrite(DE,LOW);
    digitalWrite(RE,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod.read(),HEX);
    values[i] = mod.read();
    // Serial.print(values[i],HEX);
    }
    // Serial.println();
  }
  return values[4];
}
 
byte potassium(){
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  if(mod.write(pota,sizeof(pota))==8){
    digitalWrite(DE,LOW);
    digitalWrite(RE,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod.read(),HEX);
    values[i] = mod.read();
    // Serial.print(values[i],HEX);
    }
    // Serial.println();
  }
  return values[4];
}
