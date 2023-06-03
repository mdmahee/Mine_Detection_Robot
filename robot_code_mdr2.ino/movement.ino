void movement() 
{
 
if( pwm4<= 1200)  // motor L R
{
 digitalWrite(mtrl,LOW);
 digitalWrite(mtrr,HIGH); 
 Serial.print(" mtrl=l mtr=h L ");
}
else if( pwm4>= 1700)
{
 digitalWrite(mtrl,HIGH);
 digitalWrite(mtrr,LOW); 
 Serial.print(" mtrl=h mtrr=l r ");
}
else 
{
 digitalWrite(mtrl,HIGH);
 digitalWrite(mtrr,HIGH); 
 Serial.print(" mtrl=h mtrr=h s "); 
 }




if( pwm3<= 1200)  // motor F B
{
 
  if(motorval==1)
  {
     digitalWrite(mtr1,LOW);
 digitalWrite(mtr2,HIGH);  
  }

  else
  {
 digitalWrite(mtr1,HIGH);
 digitalWrite(mtr2,HIGH);   
  }

 Serial.print(" mtr1=l mtr2=h f ");
}




else if( pwm3>= 1700)  //back code
{
if(backval==1)
{
 digitalWrite(mtr2,LOW);
delay(1000); 
backval=0; backval=backval;
}
else
{
digitalWrite(mtr1,LOW);
}

 Serial.print(" mtr1=l mtr2=l B ");
}
else 
{
 digitalWrite(mtr1,HIGH);
 digitalWrite(mtr2,HIGH); 
 Serial.print(" mtr1=h mtr2=h s "); 
 backval=1; backval=backval;
 }

}
