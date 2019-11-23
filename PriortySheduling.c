#include<stdio.h>

int main(){

    int burst_time[20],priority[20],p[20],waiting_time[20],turnAroundTime[20];
    int i,j,n,total_wt=0,total_tat=0,pos,temp,avg_wt,avg_tat;

    printf("Enter Total Number of Processes: ");
    scanf("%d",&n);

    printf("\nEnter Burst Time and Priority for every process\n");
    for(i=0;i<n;i++){
        printf("\nproess: P[%d]\n",i+1);
        printf("Burst Time: ");
        scanf("%d",&burst_time[i]);
        printf("Priority: ");
        scanf("%d",&priority[i]);
        p[i]=i+1;           //contains process number
    }

    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++){

        pos=i;
        for(j=i+1;j<n;j++){
            if(priority[j]<priority[pos])
                pos=j;
        }

        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;

        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    waiting_time[0]=0;	//waiting time for first process is zero

    //calculate waiting time
    for(i=1;i<n;i++){
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i] = waiting_time[i]+burst_time[j];

        total_wt += waiting_time[i];
    }

    avg_wt=total_wt/n;      //average waiting time

    printf("\nProcess \tBurst Time \tWaiting Time \tTurnaround Time");
    for(i=0;i<n;i++){
        turnAroundTime[i]=burst_time[i]+waiting_time[i];     //calculate turnaround time
        total_tat += turnAroundTime[i];
        printf("\nP[%d]\t\t %d\t\t %d\t\t %d",p[i],burst_time[i],waiting_time[i],turnAroundTime[i]);
    }

    avg_tat=total_tat/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);

	return 0;
}
