/*
Q6 Implement preemptive Priority CPU scheduling algorithm, given the list of 
    processes, their CPU burst times and arrival times (take inputs from the user 
    like No. of processes etc.):
    1. Display/print the Gantt chart. 
    2. Print waiting time and turnaround time for each process.
    3. Print average waiting time and average turnaround time.
    4. Schedule the same priority processes with the Round Robin scheduling algorithm.
*/
#include<stdio.h>

struct process {
    int at, bt, wt, tat, pid, pt, bt1;
};

void main() {
    int i, j, n, avgtat = 0, avgwt = 0, k = 0, temp[20];
    
    printf("\nEnter The No of Process : ");
    scanf("%d", &n);
    
    struct process p[n];
    
    for (i = 0; i < n; i++) {
        printf("\nEnter the Arrival Time for Process %d: ", i);
        scanf("%d", &p[i].at);
        
        printf("\nEnter the Brust Time for Process %d: ", i);
        scanf("%d", &p[i].bt);
        
        printf("\nEnter the Priority for Process %d: ", i);
        scanf("%d", &p[i].pt);
        
        p[i].pid = i;
        p[i].bt1 = p[i].bt;  // Store the original burst time for later use
        temp[i] = p[i].bt;    // Store burst time in temp[] for later calculation
    }
    
    int t, count = 0, shopt_p;
    
    printf("\n\n\nGantt Chart: ");
    printf("\n-------------------------------------------------\n");
    
    // Store the Gantt chart process order
    int ganttChart[100];
    int ganttIndex = 0;

    // Execute the scheduling algorithm
    for (t = 0; count != n; t++) {
        shopt_p = -1;
        
        // Find the process with the highest priority that is ready to execute
        for (i = 0; i < n; i++) {
            if (p[i].at <= t && p[i].bt > 0) {
                if (shopt_p == -1 || p[i].pt < p[shopt_p].pt) {
                    shopt_p = i;
                }
            }
        }
        
        // Decrease the burst time for the selected process
        if (shopt_p != -1) {
            p[shopt_p].bt--;
            ganttChart[ganttIndex++] = shopt_p; // Store the process in Gantt chart
            
            // Print the process execution in the Gantt chart
            printf(" P%d |", shopt_p);
            
            if (p[shopt_p].bt == 0) {
                count++;
                p[shopt_p].wt = t + 1 - p[shopt_p].at - temp[shopt_p];  // Calculate waiting time
                p[shopt_p].tat = t + 1 - p[shopt_p].at;                   // Calculate turnaround time
                avgwt = avgwt + p[shopt_p].wt;
                avgtat = avgtat + p[shopt_p].tat;
            }
        }
    }
    
    printf("|\n-------------------------------------------------\n");
    
    // Print the results in a table format
    printf("\nProcess | ArrivalTime | BrustTime | WaitingTime | TurnAroundTime ");
    printf("\n--------------------------------------------------------------------");
    for (i = 0; i < n; i++) {
        printf("\n   P%d   |%7d      |%7d    |%7d      | %7d ", i, p[i].at, p[i].bt1, p[i].wt, p[i].tat);
    }
    
    // Print average waiting time and average turnaround time
    printf("\n\n\n\nAverage Waiting Time : %d", avgwt / n);
    printf("\nAverage Turnaround Time : %d\n\n", avgtat / n);
    
    // Print the Gantt chart process order
    printf("\nGantt Chart Execution Order: \n");
    for (i = 0; i < ganttIndex; i++) {
        printf("P%d ", ganttChart[i]);
    }
    printf("\n");
}
/*
Enter The No of Process : 4

Enter the Arrival Time for Process 0: 2

Enter the Brust Time for Process 0: 4

Enter the Priority for Process 0: 3

Enter the Arrival Time for Process 1: 4

Enter the Brust Time for Process 1: 8

Enter the Priority for Process 1: 1

Enter the Arrival Time for Process 2: 5

Enter the Brust Time for Process 2: 6

Enter the Priority for Process 2: 3

Enter the Arrival Time for Process 3: 6

Enter the Brust Time for Process 3: 4

Enter the Priority for Process 3: 5



Gantt Chart: 
-------------------------------------------------
 P0 | P0 | P1 | P1 | P1 | P1 | P1 | P1 | P1 | P1 | P0 | P0 | P2 | P2 | P2 | P2 | P2 | P2 | P3 | P3 | P3 | P3 ||
-------------------------------------------------

Process | ArrivalTime | BrustTime | WaitingTime | TurnAroundTime 
--------------------------------------------------------------------
   P0   |      2      |      4    |      8      |      12 
   P1   |      4      |      8    |      0      |       8 
   P2   |      5      |      6    |      9      |      15 
   P3   |      6      |      4    |     14      |      18 



Average Waiting Time : 7
Average Turnaround Time : 13


Gantt Chart Execution Order: 
P0 P0 P1 P1 P1 P1 P1 P1 P1 P1 P0 P0 P2 P2 P2 P2 P2 P2 P3 P3 P3 P3 
*/