#include<stdio.h>

int main(){

    int n,burst_time[50],waiting_time[50],turnAroundTime[50],average_waiting_time=0,average_turnAroundTime=0;
    int i,j,temp,position,p[50];

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    printf("\nProcess Burst Time\n");
    for(i=0;i<n;i++){
        printf("P%d: ",i+1);
        scanf("%d",&burst_time[i]);
        p[i]=i+1;
    }

    for(i=0;i<n;i++){
        position=i;
        for(j=i+1;j<n;j++){
            if(burst_time[j]<burst_time[position])
                position=j;
        }

        temp=burst_time[i];
        burst_time[i]=burst_time[position];
        burst_time[position]=temp;

        temp=p[i];
        p[i]=p[position];
        p[position]=temp;
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
        printf("\nP%d \t\t %d \t\t %d \t\t %d",p[i],burst_time[i],waiting_time[i],turnAroundTime[i]);
    }

    average_waiting_time /= n;
    average_turnAroundTime /= n;
    printf("\n\nAverage Waiting Time:%d",average_waiting_time);
    printf("\nAverage Turnaround Time:%d\n",average_turnAroundTime);

    return 0;
}



//Another code (almost similar)

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,pro[20], waitT[20], burstT[20],turnAT[20],temp;
    float total_WT=0,total_TAT=0;

    cout << "Enter number of processes: ";
    cin >> n;

    for(int i=0; i<n; i++){
        cout << "Enter process number & its burst time: ";
        cout << "p";
        cin >> pro[i] >> burstT[i];
    }

    waitT[0]=0;

    for(int i=0; i<n; i++){
        int pos=i;
        for(int j=i+1; j<n; j++){
            if(burstT[j]<burstT[pos]){
                pos=j;
            }
            temp = burstT[i];
            burstT[i] = burstT[pos];
            burstT[pos] = temp;

            temp = pro[i];
            pro[i] = pro[pos];
            pro[pos] = temp;
        }
    }

    for(int i=0; i<n; i++){
        waitT[i] = 0;
        for(int j=0; j<i; j++){
            waitT[i] = waitT[i] + burstT[j];
        }
    }

    for(int i=0; i<n; i++){
        total_WT = total_WT + waitT[i];
        turnAT[i] = waitT[i] + burstT[i];
        total_TAT = total_TAT + turnAT[i];
    }

    cout<< "\nProcess\t Burst time\tWaiting time\tTurnaroundtime\n";
    for(int i=0; i<n; i++){
        cout << pro[i] << "\t" << burstT[i] << "\t\t" << waitT[i] << "\t\t" << turnAT[i] << endl;
    }

    cout << "\nAverage waiting time: " << total_WT/n << endl;
    cout << "\naverage  turnaroundtime: " << total_TAT/n << endl;

    return 0;
}

/*
4
1 6
2 8
3 7
4 3
*/

