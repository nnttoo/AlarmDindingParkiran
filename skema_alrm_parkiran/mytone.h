#ifndef MYTONE_H
#define MYTONE_H

#define PIN_BUZZER 9

#include "time_wait.h"

TimeWait mytime, mytimemilis;

struct MYTone
{
    MYTone()
    {
      mytime.time_tipe = TIME_TIPE_MICRO;
    }
    void mysetup()
    {      
      pinMode(PIN_BUZZER, OUTPUT);  
    }

    bool b = false;
    int waittime = 0; 
    bool toneon = false;

    bool tonstart = false;
    void startTone()
    {
      tonstart = true;
    }

    void stopTone()
    {
      waittime = 0;
      tonstart = false;
    }
    
    void myloop()
    { 
        if(!tonstart) return;
      
        if(waittime > 0 && mytime.waitUntil(waittime + 300))
        {
           if(toneon)
           {
              b ^= true;
              digitalWrite(PIN_BUZZER,b);
           } else 
           {
             digitalWrite(PIN_BUZZER,LOW);
           }
           
        }

        if(waittime == 0)
        {
           if(mytimemilis.waitUntil(500))
           { 
              toneon = true;
              waittime++;
           }
           
        } else  if(mytimemilis.waitUntil(10))
        {
           toneon = true;
           waittime +=10;
           if(waittime >= 1000) waittime = 0;
        }
      
    }

};

#endif
