/*
Implement Round-Robin CPU scheduling algorithm, given the list of 
processes, their CPU burst times and arrival times (take inputs from the user 
like No. of processes etc.):
    1. Display/print the Gantt chart. 
    2. Print waiting time and turnaround time for each process.
    3. Print average waiting time and average turnaround time.
*/

#include<stdio.h>  

void main()  
{  
    int i, NOP, sum=0, count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10], ganttChart[100];  
    float avg_wt, avg_tat;  
    int time = 0; // To keep track of time for the Gantt chart
    
    printf("Total number of processes in the system: ");  
    scanf("%d", &NOP);  
    y = NOP;

    // Accept arrival and burst time for each process
    for(i = 0; i < NOP; i++)  
    {  
        printf("\nEnter the Arrival and Burst time of Process[%d]\n", i + 1);  
        printf("Arrival time is: \t");  
        scanf("%d", &at[i]);  
        printf("Burst time is: \t");  
        scanf("%d", &bt[i]);  
        temp[i] = bt[i];  
    }  
    
    printf("Enter the Time Quantum for the process: \t");  
    scanf("%d", &quant);  
    
    // Print the header for the table
    printf("\nProcess No\tBurst Time\tTAT\tWaiting Time\n");  
    
    // Gantt chart printing setup
    printf("\nGantt Chart:\n");
    printf("-------------------------------------------------\n");

    int currentTime = 0; // To track the current time during execution
    int ganttIndex = 0;  // To keep track of the index for Gantt chart

    // Round Robin Scheduling Algorithm
    for(sum = 0, i = 0; y != 0; )  
    {  
        if(temp[i] <= quant && temp[i] > 0)  
        {  
            sum = sum + temp[i];  
            temp[i] = 0;  
            count = 1;  
            
            // Update Gantt chart for this process
            for (int j = currentTime; j < sum; j++) {
                ganttChart[ganttIndex++] = i + 1; // Store the process ID for Gantt chart
            }
            
            currentTime = sum;
        }     
        else if(temp[i] > 0)  
        {  
            temp[i] = temp[i] - quant;  
            sum = sum + quant;    
            
            // Update Gantt chart for this process
            for (int j = currentTime; j < sum; j++) {
                ganttChart[ganttIndex++] = i + 1;
            }
            
            currentTime = sum;
        }  

        if(temp[i] == 0 && count == 1)  
        {  
            y--;  
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);  
            wt = wt + sum - at[i] - bt[i];  
            tat = tat + sum - at[i];  
            count = 0;     
        }  

        if(i == NOP - 1)  
        {  
            i = 0;  
        }  
        else if(at[i + 1] <= sum)  
        {  
            i++;  
        }  
        else  
        {  
            i = 0;  
        }  
    }  
    
    avg_wt = wt * 1.0 / NOP;  
    avg_tat = tat * 1.0 / NOP;  

    // Print Gantt chart
    printf("\nGantt Chart Execution Order: \n");
    for (int i = 0; i < ganttIndex; i++) {
        printf("P%d ", ganttChart[i]);
    }
    
    printf("\n-------------------------------------------------\n");

    // Print the results
    printf("\nAverage Turn Around Time: \t%f", avg_tat);  
    printf("\nAverage Waiting Time: \t%f", avg_wt);  
}  
/*
Total number of processes in the system: 4

Enter the Arrival and Burst time of Process[1]
Arrival time is:    2
Burst time is:      3

Enter the Arrival and Burst time of Process[2]
Arrival time is:    6
Burst time is:      5

Enter the Arrival and Burst time of Process[3]
Arrival time is:    1
Burst time is:      8

Enter the Arrival and Burst time of Process[4]
Arrival time is:    3
Burst time is:      9

Enter the Time Quantum for the process:  2

Process No   Burst Time   TAT   Waiting Time

Gantt Chart:
-------------------------------------------------
P3 P1 P4 P2 P3 P1 P4 P2 P3 P1 P4
-------------------------------------------------

Average Turn Around Time:  8.500000
Average Waiting Time:  3.500000

*/