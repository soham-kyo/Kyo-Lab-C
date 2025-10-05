#include <stdio.h>
int main()
{
    int n = 4;
    int burst_time[4] = {21, 6, 3, 2};
    int processes[4] = {1, 2, 3, 4};
    int waiting_time[4], turnaround_time[4];
    int total_wt = 0, total_tat = 0;
    int i;
    float avg_wt, avg_tat;
    waiting_time[0] = 0;
    for (i=0 ; i < n ; i++)
    {
        waiting_time[i] = burst_time[i-1] + waiting_time[i-1];
    }
    for (i=0 ; i < n ; i++)
    {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }
    printf("-- FCFS SCHEDULING RESULTS --\n");
    printf("-----------------------------------------------------------------\n");
    printf("Process \t Burst Time \t Waiting Time \t Turnaround Time \n");
    printf("-----------------------------------------------------------------\n");
    for (i=0 ; i < n ; i++)
    {
        total_wt = total_wt + waiting_time[i];
        total_tat = total_tat + turnaround_time[i];
        printf("P%d\t \t\t%d \t\t %d \t\t %d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
        avg_wt = (float) total_wt / n;
        avg_tat = (float) total_tat / n;
        printf("-----------------------------------------------------------------\n");
        printf("Average Waiting Time: %.2f\n", avg_wt);
        printf("Average Turnaround Time: %.2f\n", avg_tat);
        return 0;
     }
}     
/*
sohampatil@Soham-Patil Kyo-Lab-C % clang FCFS.c -o FCFS && ./FCFS
-- FCFS SCHEDULING RESULTS --
-----------------------------------------------------------------
Process 	 Burst Time 	 Waiting Time 	 Turnaround Time
-----------------------------------------------------------------
P1	 		21 		 4 		 25
-----------------------------------------------------------------
Average Waiting Time: 1.00
Average Turnaround Time: 6.25
*/
