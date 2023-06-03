void xplsv()
{

if( pwm6<= 1200) //E 
{


 radio.begin();
 radio.openWritingPipe(address2);

 b=9; b==9; b=b;
 radio.write(&b, sizeof(int));  Serial.print("b=9 radio=2 ");delay(1000);
 radio.write(&b, sizeof(int));  Serial.print("b=9 radio=2 ");delay(1000);
 radio.write(&b, sizeof(int));  Serial.print("b=9 radio=2 ");delay(1000);
 radio.write(&b, sizeof(int));  Serial.print("b=9 radio=2 ");delay(1000);
 radio.write(&b, sizeof(int));  Serial.print("b=9 radio=2 ");delay(1000);

 radio.stopListening();
delay(1000);
}

else if(pwm6<= 1700)
{
 myservo2.write(180);  delay(15);

}
else 
{
   myservo2.write(65);  delay(15);
 }
 
}
