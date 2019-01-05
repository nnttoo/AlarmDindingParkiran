#ifndef TIME_WAIT_H
#define TIME_WAIT_H

#define TIME_TIPE_MILIS 0
#define TIME_TIPE_MICRO 1;


struct TimeWait
{
    
    byte time_tipe = TIME_TIPE_MILIS;
    unsigned long mytime=0;
    boolean waitUntil(unsigned long waittime,boolean autoreset)
    {
        unsigned long currenttime = mytimeNow();
        if((currenttime - mytime) > waittime)
        {
            if(autoreset)
            mytime = currenttime;
            return true;
        }
        return false; 
    }

    unsigned long mytimeNow(){
      if(time_tipe == TIME_TIPE_MILIS) return millis();
      return micros();
    }
    
    boolean waitUntil(unsigned long waittime)
    {
        return waitUntil(waittime,true);
    }
    void resetoTimeNow()
    {
        mytime = mytimeNow();
    }
};

#endif
