#include <stdio.h>
#define MAX_PROCESSES 20
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() 
{
    int n, i, j;
    float total_wt = 0.0, total_tat = 0.0;
    int p[MAX_PROCESSES], bt[MAX_PROCESSES], wt[MAX_PROCESSES], tat[MAX_PROCESSES];
    printf("Enter the number of processes (max %d):\n ", MAX_PROCESSES);
    scanf("%d", &n);
    printf("\nEnter the Burst Time for each process:\n");
    for (i = 0; i < n; i++) 
    {
        p[i] = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    for (i = 0; i < n - 1; i++) 
    {
        for (j = i + 1; j < n; j++) 
        {
            if (bt[i] > bt[j]) 
            {
                swap(&bt[i], &bt[j]);
                swap(&p[i], &p[j]);
            }
        }
    }
    wt[0] = 0;
    for (i = 1; i < n; i++) 
    {
        wt[i] = 0;
        for (j = 0; j < i; j++) 
        {
            wt[i] += bt[j];
        }
    }
    printf("\n--- SJF Scheduling Results ---\n");
    printf("Process  Burst Time  Waiting Time  Turnaround Time\n");
    printf("-----------------------------------------------------\n");
    for (i = 0; i < n; i++) 
    {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf(" P%d \t\t%d \t%d\t\t%d \n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("-----------------------------------------------------\n");
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
    return 0;
}
