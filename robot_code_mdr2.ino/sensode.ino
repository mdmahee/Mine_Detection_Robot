//A-7 Sensor Code
void sensor()
{
if( pwm8<= 1200)  // G dwn for metal sensor
{
 digitalWrite(sup,LOW);
 digitalWrite(sdwn,HIGH); 
 Serial.print(" sup=l sdwn=h u ");
}
else if( pwm8>= 1700)
{
 digitalWrite(sup,HIGH);
 digitalWrite(sdwn,LOW); 
 Serial.print(" sup=h sdwn=l d ");
}
else 
{
 digitalWrite(sup,HIGH);
 digitalWrite(sdwn,HIGH); 
 Serial.print(" sup=h sdwn=h s "); 
 }
 
}
