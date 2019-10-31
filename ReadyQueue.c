// readyQueue.c
// implementation of ReadyQ functions

#include "ReadyQueue.h"
#include <stdio.h>

// Q - pointer to a ReadyQueue
// post-conditon: sets numProcesses = 0
void emptyQueue(ReadyQueue* Q)
{
  Q->numProcesses = 0;
}

// Q - pointer to a ReadyQueue
// returns true if queue is empty - contains no processes; else, false.
int isEmptyQueue(ReadyQueue* Q)
{
  return Q->numProcesses == 0;
}

// Q - pointer to a ReadyQueue
// returns true if queue is full - contains MAX_Q_LEN processes; else, false.
int isFull(ReadyQueue* Q)
{
  return Q->numProcesses >= MAX_Q_LEN;
}

// Q - pointer to a ReadyQueue
// process - pointer to a PCB assume has been initialized
// post-condition: if Q is not full, then insert process
// into next open processList array slot, increment
// numProcesses, and return true; else, return false.
// !! Copy data values from process into array owned by Q.
int insertQueue(ReadyQueue* Q, PCB* process)
{
  // if pointers are not NULL and Q is not full then...
  if (Q != NULL && process != NULL && !isFull(Q) )
  {
    // Know Q is not full
    // Copy values from given process into array slot's PCB
    Q->processList[Q->numProcesses] = *process;
    Q->numProcesses++;
    // Assume #define TRUE  1 has been done somewhere
    return 1;
  }
  else
    return 0;
}

// pre-condition: assume first PCB has completed
//                assume size of Q is > 1.
// post-condition: shift all other PCB one slot to left
//                 decrement numProcesses by 1.
void removeFrontPCB(ReadyQueue* Q)
{
  // ? Somepoint print message saying process exited

  if(Q->numProcesses > 1)
  {
    // Loop to copy shift second element into first slot,
    // third element into second slot, ...
    for(int i = 0; i < (Q->numProcesses-1); i++)
       Q->processList[i] = Q->processList[i+1];
  }

  if(!isEmptyQueue(Q)) {
    // decrement numProcesses by 1
    Q->numProcesses--;
  }

}

// Q - pointer to a ReadyQueue
// post-condition: if Q is not empty, then call runProcess function
// on first PCB in the queue.
// Run first process in Q to completion.  Shift all remaining
// PCBs one array slot forward so second is now first.
void runFCFS(ReadyQueue* Q)
{
    if(!isEmptyQueue(Q))
    {
        // Get pointer to first process in Q
        PCB* process = &( Q->processList[0] );

        // FCFS - assume process runs to completion
        int timeRun = runProcess(process, process->remainingTime);

        // Increment Q simulator time by time ran
        Q->time += process->remainingTime;

        // Completed process' print message
        if (process->remainingTime <= 0) {
            printf("Time %d     Process %d completes\n", timeRun, process->pid);
            removeFrontPCB(Q);
        }

        // Print message indicating when a process runs
        // Example:
        // TIME 0   PID 1    RUNS FOR   2
		// Use globalTime to show current time

        // If process has <= 0 remainingTime ten remove completed front of Q process and
		// Print message if process completes
        // TIME 2   PID 1    COMPLETE

   }
}


void printQueue(ReadyQueue* Q) {
    if (isEmptyQueue(Q) != 1) {
        for (int i = 0; i < Q->numProcesses; i++) {
            PCB* process = &(Q->processList[i]);
            printf("PID %d\nRemaining Time %d\n", process->pid, process->remainingTime);
        }
    }
}

//void main() {
//    printf("No apparent errors.");
//}
