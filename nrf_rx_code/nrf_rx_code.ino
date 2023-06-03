
//A-10 NRF Rx Code
//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//create an RF24 object
RF24 radio(9, 8); // CE, CSN
//address through which two modules communicate.
const byte address[6] = "00001";
char text[32];
int a;
void setup()
{
 pinMode(A0, OUTPUT);
 while (!Serial);
 Serial.begin(9600);
 
 radio.begin();
 
 //set the address
 radio.openReadingPipe(0, address);
 
 //Set module as receiver
 radio.startListening();

 digitalWrite(A0,HIGH); digitalWrite(A0,HIGH);delay(500);
 digitalWrite(A0,LOW); digitalWrite(A0,LOW);delay(500);
 digitalWrite(A0,HIGH); digitalWrite(A0,HIGH);delay(500);
 digitalWrite(A0,LOW); digitalWrite(A0,LOW);

 
}
void loop()
{
 // Serial.println("chkng . . .");
 //Read the data if available in buffer
 
 
 if (radio.available())

 {
 // char
 //text[32] = {0};

 radio.read(&a, sizeof(int));
 Serial.println(a);
 
 }



if (Serial.available())

 {
 // char
 //text[32] = {0};

 a=Serial.read();
 Serial.println(a);
 
 }


 
 if (a==5 || a==53)
 {
 digitalWrite(A0,HIGH);
 delay(1000);
 }
 else
 digitalWrite(A0,LOW);
}
