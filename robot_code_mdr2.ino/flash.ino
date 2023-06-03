//A-5 Led Flush Code
void flashh()
{
if( pwm7<= 1200)   //f 
{
 digitalWrite(flash,LOW); 
 Serial.print("flash=l flash on ");
}
else 
{
 digitalWrite(flash,HIGH); 
 Serial.print("flash=h flash off ");
 }
 
}
