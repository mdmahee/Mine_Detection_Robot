//A-1. Alarm Code
void alarm() 
{
 motorval=0; motorval==motorval;
 digitalWrite(mtr1,HIGH);
 digitalWrite(mtr2,HIGH);  

 digitalWrite(er2,LOW);  //back light
 
//brk();




  radio.begin();    ///extra code
 radio.openWritingPipe(address);

 
  delay(1000); 
  a=5; a==5; a=a; 

 radio.write(&a, sizeof(int));  delay(1000);
 radio.write(&a, sizeof(int));  delay(1000);
 radio.write(&a, sizeof(int));  delay(1000);
 radio.write(&a, sizeof(int));  delay(1000);

// radio.stopListening();  //extra code

//if(radval=1){   a=5; radio.write(&a, sizeof(int));  delay(1000);a==a;}




// digitalWrite(r3,HIGH); digitalWrite(r4,HIGH);
 //Serial.print(" r3=H r4=H SSS Alarm");
 Serial.print(" SSS Alarm");
 digitalWrite(brkon,HIGH); 
  digitalWrite(brkoff,HIGH); 
}
