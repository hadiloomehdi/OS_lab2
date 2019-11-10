#include "types.h"
#include "stat.h"
#include "user.h"
#include "date.h"
#include "defs.h"

// void cmostime(struct rtcdate *r);

int sleepTime (int time) {
    int differenceTime = 12;
    struct rtcdate firstDate, secondDate;
    cmostime (&firstDate);
    // manualSleep (time);
    // sleep(500);
    cmostime (&secondDate);
    differenceTime =    (firstDate.minute - secondDate.minute) * 60 +
                        (firstDate.second - secondDate.second);
    printf (1, "sleepTime is called with : %d\ndifference between two time with cmostime is : %d\n", time, differenceTime);
    return differenceTime;
}

int main (int argc, char **argv) {
    sleepTime (50);
    exit ();
}
