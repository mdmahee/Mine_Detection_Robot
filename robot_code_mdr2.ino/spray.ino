//A-4 Color Spray Code
void sprayy()
{


  if ( pwm5 < 1700 && pwm5 > 1400) //c0=pwm5
  {




    if ( pwm2 <= 1099) //E
    {


             radio.begin();    ///extra code
 radio.openWritingPipe(address);

 
      a = 0; a==0; a=a; 
      radio.write(&a, sizeof(int));  Serial.print("radio=1 "); delay(1000);
      radio.write(&a, sizeof(int));  Serial.print("radio=1 "); delay(1000);
      radio.write(&a, sizeof(int));  Serial.print("radio=1 "); delay(1000);
      radio.write(&a, sizeof(int));  Serial.print("radio=1 "); delay(1000);
  radio.stopListening();  //extra code
 delay(1000);

 
      digitalWrite(spray, LOW); //
      digitalWrite(er1, LOW);   //24v solenoid
      Serial.print("spray er1=h ");


      Serial.print("spray l/f ");
      delay(1000);

      //digitalWrite(brkon,HIGH); digitalWrite(brkoff,LOW); delay(3000);digitalWrite(brkon,HIGH);  digitalWrite(brkoff,HIGH);

      digitalWrite(spray, HIGH); //
      digitalWrite(er1, HIGH);   //24v solenoid
      motorval = 1; motorval == motorval;
     
      
   //   radval = 0; radval = radval; radval == radval;

      digitalWrite(er2, HIGH);  Serial.print("er2=h"); //back light
delay(1000);


 }






    else if (pwm2 >= 1100 && pwm2 <= 1300)
    {
      if (brkval == 2)
      {
        digitalWrite(brkon, HIGH);
        digitalWrite(brkoff, HIGH);
        //delay(5000);
        brkval = brkval; brkval == brkval;
      }
      else if (brkval == 1)
      {
        digitalWrite(brkon, HIGH);
        digitalWrite(brkoff, LOW);
        delay(1500);
        brkval = 2; brkval == brkval;brkval = brkval; 
      }

       else if (brkval == 0)
      {
        brkval = brkval+1; brkval == brkval;brkval = brkval; 
      }
     brkval == brkval; brkval = brkval; 
    }




    else if (pwm2 >= 1750)
    {
      if (brkval == 1)
      {
        digitalWrite(brkon, HIGH);
        digitalWrite(brkoff, HIGH);
        //delay(5000);
       brkval == brkval; brkval = brkval; 
      }
      else if (brkval == 2)
      {
        digitalWrite(brkon, LOW);
        digitalWrite(brkoff, HIGH);
        delay(1500);
        brkval = 1; brkval == brkval;brkval = brkval; 
      }

 else if (brkval == 0)
      {
        brkval = brkval+2; brkval == brkval;brkval = brkval; 
      }

    }




    
    else
    {
       brkval == brkval; brkval = brkval;
      //brk();
      digitalWrite(brkon, HIGH);
      digitalWrite(brkoff, HIGH);

      digitalWrite(spray, HIGH);
      digitalWrite(er1, HIGH);
      Serial.print("spray er1=L spray off ");
    }
    }
  }
