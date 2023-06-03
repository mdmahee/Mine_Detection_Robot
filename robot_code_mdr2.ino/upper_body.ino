//A-8 Upper Body Code
void upperbody()
{
 if( pwm5<1700 && pwm5>1400) //c0=pwm5
////cam l/r
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
 myservo.write(val);  delay(15);
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


}
}
