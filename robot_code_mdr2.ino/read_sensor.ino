//A-6 Read Sensor
void readsensor()
{
 total = total - readings[readIndex];
 readings[readIndex] = analogRead(A2);
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
  if (readIndex2 >= numReadings2) {
 readIndex2 = 0;
 }
 s2 = total2 / numReadings2;
 delay(1);
 
 
 total3 = total3 - readings3[readIndex3];
 readings3[readIndex3] = analogRead(A0);
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


if( pwm9>= 1200)    // button D goes dwn
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
 radval=1; radval==radval; radval=radval;
}
 else
{
 Serial.print (" no alarm ");
}

}
else
{
 Serial.print (" no s reading ");
}
 
}
