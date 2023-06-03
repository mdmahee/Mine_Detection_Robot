A-1. Alarm Code
void alarm() 
{
int a=5; radio.write(&a, sizeof(int)); 
// delay(1000);
// digitalWrite(r3,HIGH); digitalWrite(r4,HIGH);
 Serial.print(" r3=H r4=H SSS Alarm");
 motorval=0; motorval==motorval;
 digitalWrite(r17,LOW); 
// delay(10000);
}
/*void alarmoff()
{
if( pwm9>= 1200)
{
 motorval=1;
 motorval=motorval;
 Serial.print(" Alarm off ");
}
else 
{
 Serial.print(" alarm sw nothng ");
 }
 
 
}
*/
44
A-2 Arm Code
void arm()
{
 if( pwm5>=1800) //c2=pwm5
////arm 1 l/r
{ 
if( pwm1<= 1200)
{
 digitalWrite(r5,LOW);
 digitalWrite(r6,HIGH); 
 Serial.print(" r5=l r6=h L ");
}
else if( pwm1>= 1700)
{
 digitalWrite(r5,HIGH);
 digitalWrite(r6,LOW); 
 Serial.print(" r5=h r6=l R ");
}
else 
{
 digitalWrite(r5,HIGH);
 digitalWrite(r6,HIGH); 
 Serial.print(" r5=h r6=h s "); 
 }
////arm 2 u/d
if( pwm2<= 1200)
{
 digitalWrite(r7,LOW);
 digitalWrite(r8,HIGH); 
 Serial.print(" r7=l r8=h u ");
}
else if( pwm2>= 1700)
{
 digitalWrite(r7,HIGH);
 digitalWrite(r8,LOW); 
 Serial.print(" r7=h r8=l d ");
}
else 
{
 digitalWrite(r7,HIGH);
 digitalWrite(r8,HIGH); 
 Serial.print(" r7=h r8=h s "); 
 }
45
}
else if( pwm5<=1200) //c1=pwm5
////arm 3 u/d
{
if( pwm2<= 1200)
{
 digitalWrite(r9,LOW);
 digitalWrite(r10,HIGH); 
 Serial.print(" r9=l r10=h u ");
}
else if( pwm2>= 1700)
{
 digitalWrite(r9,HIGH);
 digitalWrite(r10,LOW); 
 Serial.print(" r9=h r10=l d ");
}
else 
{
 digitalWrite(r9,HIGH);
 digitalWrite(r10,HIGH); 
 Serial.print(" r9=h r10=h s "); 
 }
////arm 4 l/r
if( pwm1<= 1200)
{
 digitalWrite(r11,LOW);
 digitalWrite(r12,HIGH); 
 Serial.print(" r11=l r12=h L ");
}
else if( pwm1>= 1700)
{
 digitalWrite(r11,HIGH);
 digitalWrite(r12,LOW); 
 Serial.print(" r11=h r12=l R ");
}
else 
{
 digitalWrite(r11,HIGH);
 digitalWrite(r12,HIGH); 
 Serial.print(" r11=h r12=h s "); 
 }
}
46
else 
{
 Serial.print(" nothing "); 
 }
}
A-3 Code
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(48, 49); // CE7, CSN8 9,8
const byte address[6] = "00001";
#include <Servo.h>
Servo myservo; // create servo object to control a servo
Servo myservo2; // create servo object to control a servo
int val=65;
int val2=65;
int setval=350; //sensor treshold
int motorval=1; //motor alarm val 
int alarmval=0;
int a=0;
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
47
int readings3[numReadings3]; 
int readIndex3 = 0; 
int total3 = 0; 
int average3 = 0;
int PWM_PIN1 = 3; //Define Digital PIN
int PWM_PIN2 = 4; //Define Digital PIN
int PWM_PIN3 = 6; //Define Digital PIN
int PWM_PIN4 = 5; //Define Digital PIN
int PWM_PIN5 = 7; //Define Digital PIN
int PWM_PIN6 = 8; //Define Digital PIN
int PWM_PIN7 = 9; //Define Digital PIN
int PWM_PIN8 = 10; //Define Digital PIN
int PWM_PIN9 = 11; //Define Digital PIN
//int PWM_PIN10 = 12; //Define Digital PIN
int pwm1,pwm2,pwm3,pwm4,pwm5,pwm6,pwm7,pwm8,pwm9;
//int=pwm10;
int r1 = 28; //Define Digital PIN
int r2 = 29; //Define Digital PIN
int r3 = 30; //Define Digital PIN
int r4 = 31; //Define Digital PIN
int r5 = 34; //Define Digital PIN
int r6 = 35; //Define Digital PIN
int r7 = 36; //Define Digital PIN
int r8 = 37; //Define Digital PIN
int r9 = 38; //Define Digital PIN
int r10 =39; //Define Digital PIN
int r11= 40; //Define Digital PIN
int r12= 41; //Define Digital PIN
int r13= 42; //Define Digital PIN
int r14= 43; //Define Digital PIN
int r15= 44; //Define Digital PIN
int r16= 45; //Define Digital PIN
int r17= 46; //Define Digital PIN
int r18= 47; //Define Digital PIN
int s1,s2,s3;
void setup() 
{
48
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
 pinMode(r1, OUTPUT);
 pinMode(r2, OUTPUT);
 pinMode(r3, OUTPUT);
 pinMode(r4, OUTPUT);
 pinMode(r5, OUTPUT);
 pinMode(r6, OUTPUT);
 pinMode(r7, OUTPUT);
 pinMode(r8, OUTPUT);
 pinMode(r9, OUTPUT);
 pinMode(r10, OUTPUT);
 pinMode(r11, OUTPUT);
 pinMode(r12, OUTPUT);
 pinMode(r13, OUTPUT);
 pinMode(r14, OUTPUT);
 pinMode(r15, OUTPUT);
 pinMode(r16, OUTPUT);
 pinMode(r17, OUTPUT);
 pinMode(r18, OUTPUT);
 digitalWrite(r1,HIGH); 
 digitalWrite(r2,HIGH); 
 digitalWrite(r3,HIGH); 
 digitalWrite(r4,HIGH); 
 digitalWrite(r5,HIGH); 
 digitalWrite(r6,HIGH); 
 digitalWrite(r7,HIGH); 
 digitalWrite(r8,HIGH); 
 digitalWrite(r9,HIGH); 
 digitalWrite(r10,HIGH); 
 digitalWrite(r11,HIGH); 
 digitalWrite(r12,HIGH); 
 digitalWrite(r13,HIGH); 
 digitalWrite(r14,HIGH); 
 digitalWrite(r15,HIGH); 
 digitalWrite(r16,HIGH); 
 digitalWrite(r17,HIGH); 
 digitalWrite(r18,HIGH); 
 myservo.attach(12); // attaches the servo on pin 9 to the servo object
 myservo.write(65); 
 myservo2.attach(13); // attaches the servo on pin 9 to the servo 
object
 myservo2.write(65); 
49
 radio.begin();
 radio.openWritingPipe(address);
 radio.stopListening();
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
 readsensor();
 movement();
 arm();
 sensor();
 spray();
 flash();
 // firing();
 upperbody();
 // alarmoff();
 
50
 
 Serial.print(" PWM CH1: "); Serial.print(pwm1);
 Serial.print(" PWM CH2: "); Serial.print(pwm2);
 Serial.print(" PWM CH3: "); Serial.print(pwm3);
 Serial.print(" PWM CH4: "); Serial.print(pwm4);
 Serial.print(" PWM CH5: "); Serial.print(pwm5);
 Serial.print(" PWM CH6: "); Serial.print(pwm6);
 Serial.print(" PWM CH7: "); Serial.print(pwm7);
 Serial.print(" PWM CH8: "); Serial.print(pwm8);
 Serial.print(" PWM CH9: "); Serial.println(pwm9);
 
// Serial.print(" PWM CH10: "); Serial.print(pwm10);
val==val; motorval==motorval;
}
A-4 Color Spray Code
void spray()
{
if( pwm6<= 1200)
{
 digitalWrite(r15,LOW); 
 digitalWrite(r16,LOW); 
 Serial.print("r14=h spray l/f ");
 motorval=1; motorval==motorval;
 
 myservo2.write(45);
 delay(25);
 Serial.print("r14=h spray l/f ");
 delay(1000);
 myservo2.write(145);
 delay(25);
 Serial.print("r14=h spray l/f ");
 delay(1000);
 myservo2.write(45);
 delay(25);
 Serial.print("r14=h spray l/f ");
 delay(1000);
 myservo2.write(145);
 delay(25);
 Serial.print("r14=h spray l/f ");
 delay(1000);
51
 myservo2.write(45);
 delay(25);
 Serial.print("r14=h spray l/f ");
 delay(1000);
 myservo2.write(145);
 delay(25);
 Serial.print("r14=h spray l/f ");
 delay(1000);
 digitalWrite(r17,HIGH); 
 a=1; radio.write(&a, sizeof(int)); 
}
else if( pwm6>= 1200 && pwm6<= 1700)
{
 digitalWrite(r15,LOW); 
 digitalWrite(r16,LOW); 
 Serial.print("r14=h spray on ");
}
else 
{
 digitalWrite(r15,HIGH); 
 digitalWrite(r16,HIGH); 
 Serial.print("r14=h spray off ");
 }
 
}
A-5 Firing Code
void firing()
{
/*
if( pwm9>= 1200)
{
 digitalWrite(r17,LOW); 
 Serial.print("r17=l firing");
}
else 
{
 digitalWrite(r17,HIGH); 
 Serial.print("r17=h firing off ");
 }
*/
 
52
}
A-5 Led Flush Code
void flash()
{
if( pwm7<= 1200)
{
 digitalWrite(r18,LOW); 
 Serial.print("r16=l flash on ");
}
else 
{
 digitalWrite(r18,HIGH); 
 Serial.print("r18=h flash off ");
 }
 
}
A-6 Read Sensor
void readsensor()
{
 total = total - readings[readIndex];
 readings[readIndex] = analogRead(A0);
 total = total + readings[readIndex];
 readIndex = readIndex + 1;
 if (readIndex >= numReadings) {
 readIndex = 0;
 }
 s1 = total / numReadings;
 delay(1);
 total2 = total2 - readings2[readIndex2];
 readings2[readIndex2] = analogRead(A1);
 total2 = total2 + readings2[readIndex2];
 readIndex2 = readIndex2 + 1;
53
 if (readIndex2 >= numReadings2) {
 readIndex2 = 0;
 }
 s2 = total2 / numReadings2;
 delay(1);
 total3 = total3 - readings3[readIndex3];
 readings3[readIndex3] = analogRead(A2);
 total3 = total3 + readings3[readIndex3];
 readIndex3 = readIndex3 + 1;
 if (readIndex3 >= numReadings3) {
 readIndex3 = 0;
 }
 s3 = total3 / numReadings3;
 delay(1);
 
//s1=analogRead(A0);s2=analogRead(A1);s3=analogRead(A2);
 Serial.print ("s1: "); Serial.print(s1);
 Serial.print (" s2: "); Serial.print(s2);
 Serial.print (" s3: "); Serial.print(s3);
if( pwm9>= 1200)
{ 
 if(s1>=150)
{
 alarm();
}
 else if(s2>=300)
{
 alarm();
}
 else if(s3>=200)
{
 alarm();
}
 else
{
 Serial.print (" no alarm ");
}
54
}
else
{
 Serial.print (" no s reading ");
}
 
}
A-7 Sensor Code
void sensor()
{
if( pwm8<= 1200)
{
 digitalWrite(r13,LOW);
 digitalWrite(r14,HIGH); 
 Serial.print(" r13=l r14=h u ");
}
else if( pwm8>= 1700)
{
 digitalWrite(r13,HIGH);
 digitalWrite(r14,LOW); 
 Serial.print(" r13=h r14=l d ");
}
else 
{
 digitalWrite(r13,HIGH);
 digitalWrite(r14,HIGH); 
 Serial.print(" r13=h r14=h s "); 
 }
 
}
55
A-8 Upper Body Code
void upperbody()
{
 if( pwm5<1700 && pwm5>1400) //c0=pwm5
////arm 1 l/r
{ 
 
 if(pwm1>1600)
 {
 val=val+5;
 
 if(val>=180)
 {
 val=180;
 val==val;
 }
 
 val==val;
 myservo.write(val); 
 delay(15);
 Serial.print(" upper body servo ");
 Serial.print(val); 
 }
 
else if(pwm1<1300)
 {
 val=val-5;
 
 if(val<=0)
 {
 val=0;
 val==val;
 }
 
 val==val;
 myservo.write(val); 
 delay(15);
 Serial.print(" upper body servo ");
 Serial.print(val); 
 } 
 
 else
 {
 val==val;
 myservo.write(val); 
 delay(15);
 Serial.print(" upper body servo ");
 Serial.print(val); 
 }
56
if(pwm2>1600)
 {
 alarmval=alarmval+1;
 alarmval=alarmval;
 //delay(5000);
 if( alarmval>= 50)
{
 motorval=1;
 motorval=motorval;
 Serial.print(" Alarm off ");
 alarmval=0;
 alarmval=alarmval;
}
 }
 else
 {
 Serial.print(" no alarmval ");
 }
 
}
}
A-9 NRF Transmitter Code
//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//create an RF24 object
RF24 radio(48, 49); // CE7, CSN8 9,8
//address through which two modules communicate.
const byte address[6] = "00001";
void setup()
{
 radio.begin();
 
 //set the address
 radio.openWritingPipe(address);
 
 //Set module as transmitter
57
 radio.stopListening();
}
void loop()
{
 //Send message to receiver
 //const char text[] = "5"; radio.write(&text, sizeof(text));
 int a=5; radio.write(&a, sizeof(int)); 
 delay(1000);
}
