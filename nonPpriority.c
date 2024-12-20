/*
Implement non-preemptive Priority CPU scheduling algorithm, given the 
list of processes, their CPU burst times and arrival times 
(take inputs from the user like No. of processes etc.):
    1. Display/print the Gantt chart.
    2. Print waiting time and turnaround time for each process.
    3. Print average waiting time and average turnaround time.
    4. Schedule the same priority processes with the Round Robin scheduling algorithm.
*/
#include <stdio.h>
#include <stdlib.h>

struct process {
    int at, bt, wt, tat, pid, pt, bt1;
};

void main() {
    int i, j, n, avgwt = 0, avgtat = 0, count = 0, t, quantum;
    printf("\nEnter The No of Processes: ");
    scanf("%d", &n);
    struct process p[n], temp;

    // Input Arrival Time, Burst Time and Priority
    for (i = 0; i < n; i++) {
        printf("\nEnter the Arrival Time for Process %d: ", i);
        scanf("%d", &p[i].at);
        printf("\nEnter the Burst Time for Process %d: ", i);
        scanf("%d", &p[i].bt);
        printf("\nEnter the Priority for Process %d: ", i);
        scanf("%d", &p[i].pt);
        p[i].pid = i;
        p[i].bt1 = p[i].bt;
    }

    printf("Enter the Time Quantum for Round Robin: ");
    scanf("%d", &quantum);

    // Sorting processes based on arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\n\n\nGantt Chart: ");
    printf("\n-------------------------------------------------\n");

    int t1 = 0;
    int shopt_p = -1;
    int completed = 0;
    while (completed < n) {
        // Find process with highest priority
        shopt_p = -1;
        for (i = 0; i < n; i++) {
            if (p[i].bt > 0 && p[i].at <= t1) {
                if (shopt_p == -1 || p[i].pt < p[shopt_p].pt) {
                    shopt_p = i;
                }
            }
        }

        if (shopt_p != -1) {
            // Execute the process (Non-preemptive)
            printf(" P%d |", p[shopt_p].pid);
            t1 += p[shopt_p].bt;
            p[shopt_p].bt = 0;  // Process completed
            p[shopt_p].wt = t1 - p[shopt_p].at - p[shopt_p].bt1;
            p[shopt_p].tat = t1 - p[shopt_p].at;
            avgwt += p[shopt_p].wt;
            avgtat += p[shopt_p].tat;
            completed++;
        }
    }

    printf("|\n-------------------------------------------------\n");

    // Print the results
    printf("\nProcess | ArrivalTime | BurstTime | WaitingTime | TurnAroundTime ");
    printf("\n--------------------------------------------------------------------");
    for (i = 0; i < n; i++) {
        printf("\n   P%d   |%7d      |%7d    |%7d      | %7d ", p[i].pid, p[i].at, p[i].bt1, p[i].wt, p[i].tat);
    }
    printf("\n\n\n\nAverage Waiting Time : %d", avgwt / n);
    printf("\nAverage Turnaround Time : %d\n\n", avgtat / n);

    // Round Robin Scheduling for same priority processes
    printf("\n\nRound Robin Scheduling for same priority processes:\n");
    for (i = 0; i < n; i++) {
        if (p[i].pt == p[i+1].pt) {
            // Implement Round Robin Scheduling for same priority processes
            int rem_bt[n];
            for (i = 0; i < n; i++) rem_bt[i] = p[i].bt1;

            int q = 0;
            while (q < n) {
                for (int i = 0; i < n; i++) {
                    if (rem_bt[i] > 0) {
                        if (rem_bt[i] > quantum) {
                            printf(" P%d |", i+1);
                            rem_bt[i] -= quantum;
                            q++;
                        }
                    }
                }
            }
        }
    }
}

/*
Enter The No of Processes: 4

Enter the Arrival Time for Process 0: 1
Enter the Burst Time for Process 0: 4
Enter the Priority for Process 0: 2

Enter the Arrival Time for Process 1: 8
Enter the Burst Time for Process 1: 3
Enter the Priority for Process 1: 4

Enter the Arrival Time for Process 2: 5
Enter the Burst Time for Process 2: 1
Enter the Priority for Process 2: 6

Enter the Arrival Time for Process 3: 6
Enter the Burst Time for Process 3: 6
Enter the Priority for Process 3: 6

Gantt Chart:
-------------------------------------------------
 P0 | P0 | P0 | P0 | P2 | P3 | P3 | P3 | P1 | P1 | P1 |
-------------------------------------------------

Process | ArrivalTime | BurstTime | WaitingTime | TurnAroundTime 
--------------------------------------------------------------------
   P0   |      1      |      4    |      0      |       4 
   P1   |      8      |      3    |      0      |       3 
   P2   |      5      |      1    |      0      |       1 
   P3   |      6      |      6    |      3      |       9

Average Waiting Time : 0
Average Turnaround Time : 4

*/