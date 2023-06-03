//A-3 Code
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 21); // CE7, CSN8  9,8 48 49
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

int r1 = 53; //Define Digital PIN 28
int r2 = A14; //Define Digital PIN
int r3 = 49; //Define Digital PIN
int r4 = 47; //Define Digital PIN 31
int r5 = 45; //Define Digital PIN 34
int r6 = 43; //Define Digital PIN
int r7 = 41; //Define Digital PIN
int r8 = 39; //Define Digital PIN
int r9 = 37; //Define Digital PIN
int r10 =35; //Define Digital PIN
int r11= 33; //Define Digital PIN
int r12= 31; //Define Digital PIN
int r13= 29; //Define Digital PIN
int r14= 27; //Define Digital PIN
int r15= 25; //Define Digital PIN
int r16= 23; //Define Digital PIN
int r17= 24; //Define Digital PIN
int r18= 28; //Define Digital PIN 47
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
 myservo2.attach(13); // attaches the servo on pin 9 to the servo object
 myservo2.write(65); 

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

 
 
 Serial.print(" PWM CH1: "); Serial.print(pwm1);
 Serial.print(" PWM CH2: "); Serial.print(pwm2);
 Serial.print(" PWM CH3: "); Serial.print(pwm3);
 Serial.print(" PWM CH4: "); Serial.print(pwm4);
 Serial.print(" PWM CH5: "); Serial.print(pwm5);
 Serial.print(" PWM CH6: "); Serial.print(pwm6);
 Serial.print(" PWM CH7: "); Serial.print(pwm7);
 Serial.print(" PWM CH8: "); Serial.print(pwm8);
 Serial.print(" PWM CH9: "); Serial.println(pwm9);
 
 Serial.print("checking . . .");
 Serial.println("");


 Serial.println("r1");
 digitalWrite(r1,LOW); delay(1000); digitalWrite(r1,HIGH);  
 digitalWrite(r2,LOW); delay(1000); digitalWrite(r2,HIGH);  
 digitalWrite(r3,LOW); delay(1000); digitalWrite(r3,HIGH); 
 digitalWrite(r4,LOW);delay(1000); digitalWrite(r4,HIGH);
 digitalWrite(r5,LOW);delay(1000); digitalWrite(r5,HIGH);
 digitalWrite(r6,LOW); delay(1000);digitalWrite(r6,HIGH);
 digitalWrite(r7,LOW);delay(1000); digitalWrite(r7,HIGH);
 digitalWrite(r8,LOW); delay(1000);digitalWrite(r8,HIGH);
 digitalWrite(r9,LOW); delay(1000);digitalWrite(r9,HIGH);
 digitalWrite(r10,LOW);delay(1000); digitalWrite(r10,HIGH);
 digitalWrite(r11,LOW);delay(1000); digitalWrite(r11,HIGH);
 digitalWrite(r12,LOW);delay(1000); digitalWrite(r12,HIGH);
 digitalWrite(r13,LOW);delay(1000); digitalWrite(r13,HIGH);
 digitalWrite(r14,LOW);delay(1000); digitalWrite(r14,HIGH);
 digitalWrite(r15,LOW);delay(1000); digitalWrite(r15,HIGH);
 digitalWrite(r16,LOW);delay(1000); digitalWrite(r16,HIGH);
 digitalWrite(r17,LOW);delay(1000); digitalWrite(r17,HIGH);
 digitalWrite(r18,LOW);delay(1000); digitalWrite(r18,HIGH);
 Serial.println("r18");


int a=5; 
radio.write(&a, sizeof(int));delay(500);
radio.write(&a, sizeof(int));delay(500);
radio.write(&a, sizeof(int));delay(500);
radio.write(&a, sizeof(int));delay(500);
 
// Serial.print(" PWM CH10: "); Serial.print(pwm10);
val==val; motorval==motorval;
}
