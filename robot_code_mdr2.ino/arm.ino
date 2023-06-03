//A-2 Arm Code
void arm()
{
 if( pwm5>=1800) // c2=pwm5 goes up
////arm 1 l/r
{ 
if( pwm1<= 1200)
{
 digitalWrite(a1l,LOW);
 digitalWrite(a1r,HIGH); 
 Serial.print(" a1l=l a1r=h L ");
}
else if( pwm1>= 1700)
{
 digitalWrite(a1l,HIGH);
 digitalWrite(a1r,LOW); 
 Serial.print(" a1l=h a1r=l R ");
}
else 
{
 digitalWrite(a1l,HIGH);
 digitalWrite(a1r,HIGH); 
 Serial.print(" a1l=h a1r=h s "); 
 }

 
////arm 2 u/d
if( pwm2<= 1200)
{
 digitalWrite(a2u,LOW);
 digitalWrite(a2d,HIGH); 
 Serial.print(" a2u=l a2d=h u ");
}
else if( pwm2>= 1700)
{
 digitalWrite(a2u,HIGH);
 digitalWrite(a2d,LOW); 
 Serial.print(" a2u=h a2d=l d ");
}
else 
{
 digitalWrite(a2u,HIGH);
 digitalWrite(a2d,HIGH); 
 Serial.print(" a2u=h a2d=h s "); 
 }

}


else if( pwm5<=1200) //c1=pwm5 goes dwn
////arm 3 u/d
{
if( pwm2<= 1200)
{
 digitalWrite(a3u,HIGH);
 digitalWrite(a3d,LOW); 
 Serial.print(" a3u=h a3d=l u ");
}
else if( pwm2>= 1700)
{
 digitalWrite(a3u,LOW);
 digitalWrite(a3d,HIGH); 
 Serial.print(" a3u=l a3d=h d ");
}
else 
{
 digitalWrite(a3u,HIGH);
 digitalWrite(a3d,HIGH); 
 Serial.print(" a3u=h a3d=h s "); 
 }


 
////arm 4 l/r u/d
if( pwm1<= 1200)
{
 digitalWrite(a4u,LOW);
 digitalWrite(a4d,HIGH); 
 Serial.print(" a4u=l a4d=h u ");
}
else if( pwm1>= 1700)
{
 digitalWrite(a4u,HIGH);
 digitalWrite(a4d,LOW); 
 Serial.print(" a4u=h a4d=l D ");
}
else 
{
 digitalWrite(a4u,HIGH);
 digitalWrite(a4d,HIGH); 
 Serial.print(" a4u=h a4d=h s "); 
 }
}

else 
{
 Serial.print("C0 nothing "); 
 }
}
