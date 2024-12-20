/*
Q1. Implement FCFS CPU scheduling algorithm, given the list of processes, their CPU burst times and arrival times 
    (take inputs from the user like No. of processes etc.):
    1. Display/print the Gantt chart. 
    2. Print waiting time and turnaround 
        time for each process.
    3. Print average waiting time and 
        average turnaround time.
*/

#include<stdio.h>

void main() {
    int i, j, n;
    printf("\nEnter The No of Process: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n], tat[n], temp[n + 1], p[n];
    float avgwt = 0, avgtat = 0;

    // Input arrival time and burst time for each process
    for (i = 0; i < n; i++) {
        printf("\nEnter the Arrival Time for Process %d: ", i);
        scanf("%d", &at[i]);
        printf("Enter the Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);
        p[i] = i;  // Storing process IDs for later reference
    }

    // Sorting processes by arrival time using a simple sorting algorithm
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                // Swap the arrival times
                int temp_at = at[i];
                at[i] = at[j];
                at[j] = temp_at;
                
                // Swap the burst times
                int temp_bt = bt[i];
                bt[i] = bt[j];
                bt[j] = temp_bt;
                
                // Swap the process IDs
                int temp_pid = p[i];
                p[i] = p[j];
                p[j] = temp_pid;
            }
        }
    }

    // Initializing waiting time and turnaround time
    wt[0] = 0;  // The waiting time for the first process is always 0
    temp[0] = 0;
    for (i = 1; i < n; i++) {
        // Waiting time for process i is the time spent by all previous processes
        wt[i] = bt[i - 1] + wt[i - 1] - at[i];
        if (wt[i] < 0) {  // If waiting time is negative, set it to 0 (cannot wait for negative time)
            wt[i] = 0;
        }
    }

    // Calculating turnaround time and total times
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    // Displaying Gantt chart
    printf("\n\nGantt Chart: ");
    printf("\n-------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("|   P%d   ", p[i]);
    }
    printf("|\n-------------------------------------------------\n");

    // Printing the time slots
    temp[0] = 0;
    for (i = 0; i < n; i++) {
        temp[i + 1] = temp[i] + bt[i];
    }
    for (i = 0; i < n + 1; i++) {
        printf("%d        ", temp[i]);
    }
    printf("\n\n");

    // Displaying process details
    printf("\nProcess | ArrivalTime | BurstTime | WaitingTime | TurnAroundTime ");
    printf("\n---------------------------------------------------------------");
    for (i = 0; i < n; i++) {
        printf("\n   P%d   |%7d      |%7d    |%7d      | %7d ", p[i], at[i], bt[i], wt[i], tat[i]);
    }

    // Displaying average times
    printf("\n\nAverage Waiting Time: %.2f", avgwt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avgtat / n);
}

/*

required output : 

Enter The No of Process: 4

Enter the Arrival Time for Process 0: 0
Enter the Burst Time for Process 0: 8

Enter the Arrival Time for Process 1: 2
Enter the Burst Time for Process 1: 3

Enter the Arrival Time for Process 2: 1
Enter the Burst Time for Process 2: 5

Enter the Arrival Time for Process 3: 3
Enter the Burst Time for Process 3: 9


Gantt Chart: 
-------------------------------------------------
|   P0   |   P2   |   P1   |   P3   |
-------------------------------------------------
0        8        13        16        25        


Process | ArrivalTime | BurstTime | WaitingTime | TurnAroundTime 
---------------------------------------------------------------
   P0   |      0      |      8    |      0      |       8 
   P2   |      1      |      5    |      7      |      12 
   P1   |      2      |      3    |     10      |      13 
   P3   |      3      |      9    |     10      |      19 

Average Waiting Time: 6.75
Average Turnaround Time: 13.00

*/