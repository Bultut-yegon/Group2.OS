#include <stdio.h>
#define MAXPROCESSES 22

struct Scheduling {
    int e;
    int burstTime;
    int waitingTime;
    
};

void calculate_WaitingTime(struct Scheduling processes[], int k) {
    int i;
    int total_WaitingTime = 0;
    
    processes[0].waitingTime = 0; // The first process has no waiting time
    
    // Calculate waiting time for each process
    for (i = 1; i < k; i++) {
        processes[i].waitingTime = processes[i-1].waitingTime + processes[i-1].burstTime;
        total_WaitingTime += processes[i].waitingTime;
    }
    
    // Print the process details
    printf("Process \t Burst Time \t Waiting Time: \n");
    for (i = 0; i < k; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].e, processes[i].burstTime, processes[i].waitingTime);
    }
    
    // Calculate and print average waiting time
    float average_WaitingTime = (float) total_WaitingTime / k;
    printf("Average Waiting Time: %.4f\n", average_WaitingTime);
}



int main() {
    int i, k;
    struct Scheduling processes[MAXPROCESSES];
    
    printf("Enter the number of processes  %d: ", MAXPROCESSES);
    scanf("%d", &k);
    
    // Input process details
    for (i = 0; i < k; i++) {
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &processes[i].burstTime);
        processes[i].e = i + 1;
    }
    
    calculate_WaitingTime(processes, k);
    
    return 0;
}