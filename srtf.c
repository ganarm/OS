/*
Q2. Implement SRTF CPU scheduling algorithm, given the list of processes, their CPU burst times and arrival times (take inputs from the user like No. of processes etc.):
    1. Use FCFS to schedule processes having the same CPU burst.
    2. Display/print the Gantt chart.
    3. Print waiting time and turnaround time for each process.
    4. Print average waiting time and average turnaround time.
*/
#include <stdio.h>

struct process {
    int at, bt, wt, tat, pid, rem_bt;
};

void sortByArrival(struct process p[], int n) {
    struct process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void sortByBurst(struct process p[], int n, int current_time) {
    struct process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at <= current_time && p[j].at <= current_time) {
                if (p[i].rem_bt > p[j].rem_bt || (p[i].rem_bt == p[j].rem_bt && p[i].at > p[j].at)) {
                    temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }
        }
    }
}

void main() {
    int n, count = 0, t = 0, complete = 0;
    float avgwt = 0, avgtat = 0;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    // Input Arrival Time and Burst Time
    for (int i = 0; i < n; i++) {
        printf("\nEnter Arrival Time for Process %d: ", i);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &p[i].bt);
        p[i].pid = i;
        p[i].rem_bt = p[i].bt;
    }

    // Sort the processes by Arrival Time first
    sortByArrival(p, n);

    int gantt_chart[2 * n];

    printf("\nGantt Chart:\n");
    printf("-------------------------------------------\n");
    printf("Time -> ");

    while (count < n) {
        // Sort the processes by remaining burst time and apply FCFS for equal burst times
        sortByBurst(p, n, t);
        
        // Find the process with the shortest remaining burst time
        int min = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= t && p[i].rem_bt > 0) {
                if (min == -1 || p[i].rem_bt < p[min].rem_bt || 
                    (p[i].rem_bt == p[min].rem_bt && p[i].at < p[min].at)) {
                    min = i;
                }
            }
        }

        if (min != -1) {
            // Execute the process for 1 unit of time
            gantt_chart[complete++] = p[min].pid;
            p[min].rem_bt--;
            printf("P%d ", p[min].pid);
            t++;
            
            // If the process is finished, calculate its WT and TAT
            if (p[min].rem_bt == 0) {
                p[min].tat = t - p[min].at;
                p[min].wt = p[min].tat - p[min].bt;
                avgwt += p[min].wt;
                avgtat += p[min].tat;
                count++;
            }
        } else {
            t++; // No process is ready to execute, increment time
        }
    }

    printf("\n-------------------------------------------\n");

    // Print the time axis
    printf("Time -> ");
    t = 0;
    for (int i = 0; i < complete; i++) {
        printf("%d ", t);
        t++;
    }
    printf("\n");

    // Print Waiting Time and Turnaround Time for each process
    printf("\nProcess | Arrival Time | Burst Time | Waiting Time | Turnaround Time\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("P%d      | %12d | %10d | %12d | %15d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    }

    // Print Average Waiting Time and Average Turnaround Time
    printf("\nAverage Waiting Time: %.2f\n", avgwt / n);
    printf("Average Turnaround Time: %.2f\n", avgtat / n);
}


/*
output : 
Enter the number of processes: 4

Enter Arrival Time for Process 0: 0
Enter Burst Time for Process 0: 8

Enter Arrival Time for Process 1: 2
Enter Burst Time for Process 1: 3

Enter Arrival Time for Process 2: 1
Enter Burst Time for Process 2: 5

Enter Arrival Time for Process 3: 3
Enter Burst Time for Process 3: 9

Gantt Chart:
-------------------------------------------
Time -> P0 P2 P1 P1 P1 P2 P2 P2 P2 P0 P0 P0 P0 P0 P0 P0 P3 P3 P3 P3 P3 P3 P3 
-------------------------------------------
Time -> 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 

Process | Arrival Time | Burst Time | Waiting Time | Turnaround Time
---------------------------------------------------------------
P1      |            0 |          3 |            0 |               3
P0      |            1 |          0 |            0 |               0
P3      |            3 |          3 |           17 |              20
P3      |            3 |          9 |            3 |               0

Average Waiting Time: 7.00
Average Turnaround Time: 11.75
*/