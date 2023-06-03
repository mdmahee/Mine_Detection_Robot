
//A-3 Code
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 21); // CE7, CSN8  9,8 48 49
const byte address[6] = "00001";
const byte address2[6] = "00002";


#include <Servo.h>
Servo myservo; // create servo object to control a servo
Servo myservo2; // create servo object to control a servo

int val=65;
int val2=65;



int brkval=1;
int backval=1;

int setval=350; //sensor treshold

int motorval=1; //motor alarm val
 
int alarmval=0;

int a=0;
int b=0;

const int numReadings = 5;
int readings[numReadings]; 
int readIndex = 0; 
int total = 0; 
int average = 0; 

const int numReadings2 = 5;
int readings2[numReadings2]; 
int readIndex2 = 0; 
int total2 = 0; 
int average2 = 0;
const int numReadings3 = 5;

int readings3[numReadings3]; 
int readIndex3 = 0; 
int total3 = 0; 
int average3 = 0;



int PWM_PIN1 = 2; //Define Digital PIN 3
int PWM_PIN2 = 3; //Define Digital PIN
int PWM_PIN3 = 4; //Define Digital PIN
int PWM_PIN4 = 5; //Define Digital PIN
int PWM_PIN5 = 6; //Define Digital PIN
int PWM_PIN6 = 14; //Define Digital PIN
int PWM_PIN7 = 15; //Define Digital PIN
int PWM_PIN8 = 16; //Define Digital PIN
int PWM_PIN9 = 17; //Define Digital PIN 11
//int PWM_PIN10 = 12; //Define Digital PIN

int pwm1,pwm2,pwm3,pwm4,pwm5,pwm6,pwm7,pwm8,pwm9;
//int=pwm10;


int a1l = 53; //Define Digital PIN 28 r1
int a1r = A14; //Define Digital PIN   r2
int a2u = 49; //Define Digital PIN    r3
int a2d = 47; //Define Digital PIN 31 r4
int a3u = 45; //Define Digital PIN 34 r5
int a3d = 43; //Define Digital PIN    r6
int a4u = 41; //Define Digital PIN    r7
int a4d = 39; //Define Digital PIN    r8
int er2 = 37; //Define Digital PIN    r9
int er1 =35; //Define Digital PIN    r10
int spray= 33; //Define Digital PIN    r11
int flash= 31; //Define Digital PIN    r12
int brkon= 29; //Define Digital PIN    r13
int brkoff= 27; //Define Digital PIN    r14
int sup= 25; //Define Digital PIN    r15
int sdwn= 23; //Define Digital PIN    r16
int mtr1= 28; //Define Digital PIN    r17
int mtr2= 24; //Define Digital PIN 47 r18

int mtrl= A6;
int mtrr=A7;


int s1,s2,s3;


void setup() 
{

 pinMode(PWM_PIN1, INPUT);
 pinMode(PWM_PIN2, INPUT);
 pinMode(PWM_PIN3, INPUT);
 pinMode(PWM_PIN4, INPUT);
 pinMode(PWM_PIN5, INPUT);
 pinMode(PWM_PIN6, INPUT);
 pinMode(PWM_PIN7, INPUT);
 pinMode(PWM_PIN8, INPUT);
 pinMode(PWM_PIN9, INPUT);
 
// pinMode(PWM_PIN10, INPUT);
 pinMode(a1l, OUTPUT);
 pinMode(a1r, OUTPUT);
 pinMode(a2u, OUTPUT);
 pinMode(a2d, OUTPUT);
 pinMode(a3u, OUTPUT);
 pinMode(a3d, OUTPUT);
 pinMode(a4u, OUTPUT);
 pinMode(a4d, OUTPUT);
 pinMode(er2, OUTPUT);
 pinMode(er1, OUTPUT);
 pinMode(spray, OUTPUT);
 pinMode(flash, OUTPUT);
 pinMode(brkon, OUTPUT);
 pinMode(brkoff, OUTPUT);
 pinMode(sup, OUTPUT);
 pinMode(sdwn, OUTPUT);
 pinMode(mtr1, OUTPUT);
 pinMode(mtr2, OUTPUT);
 pinMode(mtrl, OUTPUT);
 pinMode(mtrr, OUTPUT);
 
 digitalWrite(a1l,HIGH); 
 digitalWrite(a1r,HIGH); 
 digitalWrite(a2u,HIGH); 
 digitalWrite(a2d,HIGH); 
 digitalWrite(a3u,HIGH); 
 digitalWrite(a3d,HIGH); 
 digitalWrite(a4u,HIGH); 
 digitalWrite(a4d,HIGH); 
 digitalWrite(er2,HIGH); 
 digitalWrite(er1,HIGH); 
 digitalWrite(spray,HIGH); 
 digitalWrite(flash,HIGH); 
 digitalWrite(brkon,HIGH); 
 digitalWrite(brkoff,HIGH); 
 digitalWrite(sup,HIGH); 
 digitalWrite(sdwn,HIGH); 
 digitalWrite(mtr1,HIGH); 
 digitalWrite(mtr2,HIGH); 

 digitalWrite(mtrl,HIGH); 
 digitalWrite(mtrr,HIGH); 
 
 myservo.attach(A4);  myservo.write(65); 
 myservo2.attach(A5);  myservo2.write(180); 




 radio.begin();
// radio.openWritingPipe(address); radio.stopListening();
 
 
 
 
 for (int thisReading = 0; thisReading < numReadings; thisReading++) 
 {
 readings[thisReading] = 0;
 }
 for (int thisReading2 = 0; thisReading2 < numReadings2; thisReading2++) 
{
 readings2[thisReading2] = 0;
 }
 for (int thisReading3 = 0; thisReading3 < numReadings3; thisReading3++) 
 {
 readings3[thisReading3] = 0;
 }


 
 Serial.begin(115200);
 delay(200);
}



void loop() 
{
 pwm1 = pulseIn(PWM_PIN1, HIGH); //Read PWM Pulse
 pwm2 = pulseIn(PWM_PIN2, HIGH); //Read PWM Pulse
 pwm3 = pulseIn(PWM_PIN3, HIGH); //Read PWM Pulse
 pwm4 = pulseIn(PWM_PIN4, HIGH); //Read PWM Pulse
 pwm5 = pulseIn(PWM_PIN5, HIGH); //Read PWM Pulse
 pwm6 = pulseIn(PWM_PIN6, HIGH); //Read PWM Pulse
 pwm7 = pulseIn(PWM_PIN7, HIGH); //Read PWM Pulse
 pwm8 = pulseIn(PWM_PIN8, HIGH); //Read PWM Pulse
 pwm9 = pulseIn(PWM_PIN9, HIGH); //Read PWM Pulse
 
// pwm10 = pulseIn(PWM_PIN10, HIGH); //Read PWM Pulse
 
 
 movement();
 readsensor();
 arm();
 sensor();
 sprayy();
 flashh();
 // firing();
 upperbody();
// brk();
 xplsv();
 
 Serial.print(" PWM CH1: "); Serial.print(pwm1);
 Serial.print(" PWM CH2: "); Serial.print(pwm2);
 Serial.print(" PWM CH3: "); Serial.print(pwm3);
 Serial.print(" PWM CH4: "); Serial.print(pwm4);
 Serial.print(" PWM CH5: "); Serial.print(pwm5);
 Serial.print(" PWM CH6: "); Serial.print(pwm6);
 Serial.print(" PWM CH7: "); Serial.print(pwm7);
 Serial.print(" PWM CH8: "); Serial.print(pwm8);
 Serial.print(" PWM CH9: "); Serial.println(pwm9);
 
 Serial.print(" end here for checking");
 Serial.println("");
 
// Serial.print(" PWM CH10: "); Serial.print(pwm10);
val==val; motorval==motorval;
backval=backval;backval==backval;
brkval=brkval; brkval==brkval;
}
