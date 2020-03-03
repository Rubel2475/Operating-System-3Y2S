#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct proccess
{
	int bt,ct,wt,btt;
	string pro_id;
	//bt->burst time
	//ct->compete time
	//wt->waiting time
	//btt->copy of bt

}Schedule;


int main()
{
	Schedule pro[10];
	//An array of Processes
	int n,i,j,pcom,q;
	//n = number of processes, i= iteration variable,pcom=number of complete program,q=quantum time

	cout<<"Enter the number of Process::";
	cin>>n;

	cout<<"Enter the value of quantum time::";
	cin>>q;

	cout<<"Enter the Process id  burst time :::";

	for(i=0;i<n;i++){
		cin>>pro[i].pro_id;
		cin>>pro[i].bt;
		pro[i].btt=pro[i].bt;
	}

	int ctime=0;//ctime=current time
	pcom=0;
	while(pcom<n){
		for(j=0;j<n;j++){
			if(pro[j].bt>q){
                pro[j].bt-=q;
                ctime+=q;
			}
			else if(pro[j].bt>0){

                ctime+=pro[j].bt;
                pro[j].ct=ctime;
                pcom=pcom+1;
                pro[j].bt=0;
			}
		}
	}
    double AverageWaiting=0;
	cout<<"ProID\tBurst time\tComplete time\tWaiting time\n";

	for(i=0;i<n;i++){
		pro[i].wt=pro[i].ct-pro[i].btt;
		AverageWaiting+=pro[i].wt;

		cout<<pro[i].pro_id<<"\t"<<pro[i].btt<<"\t"<<pro[i].ct<<"\t"<<pro[i].wt<<endl;
	}
	cout<<"Average waiting time :"<<AverageWaiting/n<<endl;

	return 0;
}


//code without typedefine

//Round robin CPU Scheduling for some processes of same arrival time=0

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,q, pro[20], waitT[20], burstT[20], main_burstT[20], completionT[20], turnAT[20];
    float total_WT=0,total_TAT=0;

    cout << "Enter number of processes: ";
    cin >> n;

    cout<<"Enter the value of time quantum: ";
	cin>>q;

    for(int i=0; i<n; i++){
        cout << "Enter process burst time: ";
        cout << "p" << i+1 << ": ";
        cin >> burstT[i];
        pro[i] = i+1;
        main_burstT[i] = burstT[i];
    }

    int pcom=0; //process completed
    int ctm=0; //current time

    while(pcom<n){

        for(int j=0; j<n; j++){
            if(burstT[j]>q){
                burstT[j] = burstT[j]-q;
                ctm = ctm + q;
            }
            else if(burstT[j]>0){
                ctm = ctm + burstT[j];
                completionT[j] = ctm;
                pcom++;
                burstT[j]=0;
            }
        }

    }

    for(int i=0; i<n; i++){

        waitT[i] = completionT[i] - main_burstT[i];
        total_WT = total_WT + waitT[i];

        turnAT[i] = waitT[i] + main_burstT[i];
        total_TAT = total_TAT + turnAT[i];
    }

    cout<< "\nProcess\t Burst time\t completion time \tWaiting time\tTurnaroundtime\n";
    for(int i=0; i<n; i++){
        cout << pro[i] << "\t" << main_burstT[i] << "\t\t" << completionT[i] << "\t\t\t" << waitT[i] << "\t\t\t" << turnAT[i] << endl;
    }

    cout << "\nAverage waiting time: " << total_WT/n << endl;
    cout << "\naverage  turnaroundtime: " << total_TAT/n << endl;

    return 0;
}



/*
6 --process
3 -- time quantam
5 ...burst time
6
7
9
2
3
*/








