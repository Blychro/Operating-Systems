#include <stdio.h>
#include <stdlib.h>
#include "PCB.h"
#include "ReadyQueue.h"

void main() {
    printf("No apparent errors.\n");
    PCB test;
    initProcess(&test);
    printf("PID %d Remaining time %d\n", test.pid, test.remainingTime);
    initProcessValues(&test, 66, 100);
    printf("PID %d Remaining time %d\n", test.pid, test.remainingTime);
    printf("Run time %d\n", runProcess(&test, 200));

    // Declare and initialize a PCB
    // Example: PID 1, total run time 10

    PCB a;

    initProcess(&a);

    //a.pid = 1; // lazy way
    // pass address of PCB named a
    // Use & address-of to turn a into the pointer to a
    initProcessValues(&a, 1, 10);

    // Confirm initialization - print PID 1 TimeRemaining 10
    // Use the DOT since a is a PCB struct, not a pointer to a PCB
    printf("PID %d TimeLeft %d\n", a.pid, a.remainingTime);

    // Initialize readyQueue insert PCB
    ReadyQueue Q;

    // Initialize to empty.
    // Pass Q by address using the & address-of operator
    emptyQueue(&Q);

    // Test isEmpty(), isFull, size
    printf("Is Q empty %d\n", isEmptyQueue(&Q));
    printf("Is Q full %d\n", isFull(&Q));
    printf("Size of Q %d\n", Q.numProcesses);

    // Insert process a into Q
    int successInsert = insertQueue(&Q, &a);
    printf("Insert worked? %d\n", successInsert);

    printf("Is Q empty %d\n", isEmptyQueue(&Q));
    printf("Is Q full %d\n", isFull(&Q));
    printf("Size of Q %d\n", Q.numProcesses);
// OR

//    if (insert(&Q, &a) {
//        printf("Insert successful!")
//    }
//    else {
//        printf("Insert failed!")
//    }

    // More unit testing...
    printQueue(&Q);

    // One run of FCFS
    runFCFS(&Q);

    printf("Is Q empty %d\n", isEmptyQueue(&Q));
    printf("Is Q full %d\n", isFull(&Q));
    printf("Size of Q %d\n", Q.numProcesses);

    PCB b;

    initProcessValues(&b, 2, 30);
    insertQueue(&Q, &b);

    printf("Is Q empty %d\n", isEmptyQueue(&Q));
    printf("Is Q full %d\n", isFull(&Q));
    printf("Size of Q %d\n", Q.numProcesses);

    runFCFS(&Q);

    emptyQueue(&Q);

    printf("Queue cleared. Starting PCB insertion loop.\n\n");

    int i = 1;

    while (!isFull(&Q)) {
        PCB t;
        initProcessValues(&t, i, 5 * i);
        insertQueue(&Q, &t);
        i++;
    }

    printf("Is Q empty %d\n", isEmptyQueue(&Q));
    printf("Is Q full %d\n", isFull(&Q));
    printf("Size of Q %d\n", Q.numProcesses);

    while (!isEmptyQueue(&Q)) {
        runFCFS(&Q);
    }

//    while (!isFull(&Q)) {
//
//    }
}
