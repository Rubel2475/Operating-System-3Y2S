#include<stdio.h>

int main(){

    int n,burst_time[50],waiting_time[50],turnAroundTime[50],average_waiting_time=0,average_turnAroundTime=0;
    int i,j;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    printf("\nProcess Burst Time\n");
    for(i=0;i<n;i++){
        printf("P%d: ",i+1);
        scanf("%d",&burst_time[i]);
    }

    waiting_time[0]=0;

    for(i=1;i<n;i++){
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i] = waiting_time[i]+burst_time[j];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++){
        turnAroundTime[i] = burst_time[i]+waiting_time[i];
        average_waiting_time += waiting_time[i];
        average_turnAroundTime += turnAroundTime[i];
        printf("\nP%d \t\t %d \t\t %d \t\t %d",i+1,burst_time[i],waiting_time[i],turnAroundTime[i]);
    }

    average_waiting_time /= n;
    average_turnAroundTime /= n;
    printf("\n\nAverage Waiting Time:%d",average_waiting_time);
    printf("\nAverage Turnaround Time:%d\n",average_turnAroundTime);

    return 0;
}
