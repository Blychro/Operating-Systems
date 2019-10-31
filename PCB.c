#include "PCB.h"
#include <stdio.h>

// process - Pointer to a PCB
// post-condition: assigns all attributes to have value 0.
void initProcess(PCB* process) {
    process->totalTime = 0;
    process->pid = 0;
    process->remainingTime = 0;
}

// initialize attributes of given PCB
// post-condition: assigned PCB totalTime to given totalRunTime and
// remainingTime to same value, assigns pid value
void initProcessValues(PCB* process, int pid, int totalRunTime) {
    process->totalTime = totalRunTime;
    process->remainingTime = totalRunTime;
    process->pid = pid;
}

// run the given process for the given amount of time
// process - Pointer to a PCB
// runTime - Number of seconds to run this process on CPU
// post-condition: Decrease process remainingTime by
// runTime only if runTime is >= remainingTime; else,
// decrease process remainingTime by remainingTime (zero it out),
// if remainingTime < runTime
// Return number of units of time actually run by the given process.
int runProcess(PCB* process, int runTime) {
    if (process->remainingTime >= runTime) {
        process->remainingTime -= runTime;
        return runTime;
    }
    else {
        int timeLeft = process->remainingTime;
        process->remainingTime -= process->remainingTime;
        return timeLeft;
    }
}

