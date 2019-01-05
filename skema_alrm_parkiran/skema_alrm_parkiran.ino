#include <TimerOne.h>

 


#include "mytone.h"


#define TRIGPIN 4
#define ECHOPIN 5

MYTone mytone;
TimeWait timeukurjarak;

unsigned long ukurJarak()
{  
    digitalWrite(TRIGPIN,HIGH);
    delay(50);
    digitalWrite(TRIGPIN,LOW);

    return pulseIn(ECHOPIN,HIGH, 30000);
    
    
}

void setup() {  
   Serial.begin(9600);
   mytone.mysetup(); 
   pinMode(TRIGPIN,OUTPUT);
   pinMode(ECHOPIN,INPUT);

   Timer1.initialize(100);
   Timer1.attachInterrupt(looptone); 
   
} 

void looptone()
{
  
  mytone.myloop();
}


 
void loop() {   
  if(timeukurjarak.waitUntil(500))
  { 
     unsigned long jarak = ukurJarak();
     Serial.println(jarak);
     if(jarak < 300 && jarak > 0)
     {
       mytone.startTone();
     } else 
     {
        mytone.stopTone();
     }
  }
}
