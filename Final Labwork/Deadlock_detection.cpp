#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n, i, j, k, l=0;
    cout<<"Enter Number of Processes: ";
    cin>>n;
    cout<<"Enter Number of Resources: ";
    cin>>m;
    int Allocation[n][m], Request[n][m];
    int Available[m], Finish[n], Work[m], Sequence[n], PrAlloc[n];
    bool Flag, Deadlock = false;

    cout<<"Enter Total Number of Instances: "<<endl;
    for(i=0; i<m; i++){
        cin>>Available[i];
    }
    cout<<"Enter Allocation of Processes: ";
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin>>Allocation[i][j];
            PrAlloc[i] = PrAlloc[i] + Allocation[i][j];
            Available[j] = Available[j] - Allocation[i][j];
            Work[j] = Available[j];
        }
        if(PrAlloc!=0)Finish[i] = 0;
        else Finish[i] = 1;
    }
    cout<<"Enter Request of Processes: ";
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin>>Request[i][j];
        }
    }
    cout<<endl;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            Flag = true;
            for(k=0; k<m; k++){
                if(!(Finish[j]==0 && Request[j][k]<=Work[k]))Flag = false;
            }
            if(Flag==true){
                Finish[j]=1;
                for(k=0; k<m; k++){
                    Work[k] = Work[k] + Allocation[j][k];
                }
                Sequence[l] = j;
                l++;
            }
        }
    }

    for(i=0; i<n; i++){
        if(Finish[i]==0)Deadlock = true;
    }
    if(Deadlock==true){
        cout<<"There is a Deadlock State in The System."<<endl;
        cout<<"Deadlocked Processes are: ";
        for(i=0;i<n;i++)if(Finish[i]==0)cout<<"P["<<i<<"] ";
    }
    else{
        cout<<"There is No Deadlock in the System."<<endl;
        cout<<"Sequence: ";
        for(i=0; i<n; i++){
            cout<<"P["<<Sequence[i]<<"] ";
        }
    }
    return 0;
}
