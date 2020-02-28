#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m,i,j,k,s=0,e,r;

    cout<< "Enter number of processes: ";
    cin >> n;
    cout<< "Enter number of resources: ";
    cin>> m;

    int Max[n][m], Allocation[n][m], Need[n][m],Request[n][m];  //Request[1][m]
    int Available[m], Work[m], Finish[n], Sequence[n];
    bool Flag, Unsafe=false;

    cout<< "Enter available instances of each resources: ";
    for(i=0; i<m; i++){
        cin>> Available[i];
    }

    cout<<"Enter max demand of each resource: ";
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> Max[i][j];
        }
    }

    cout<<"Enter allocated resources of each type: ";
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> Allocation[i][j];

            Need[i][j] = Max[i][j]-Allocation[i][j];
            Work[j] = Available[j];
        }
        Finish[i]=0;
    }

    safety:
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            Flag=true;
            for(k=0; k<m; k++){
                if(!(Finish[j]==0 && Need[j][k]<=Work[k])){
                    Flag=false;
                }
            }
            if(Flag==true){
                Finish[j]=1;
                for(k=0; k<m; k++){
                    Work[k] = Work[k]+Allocation[j][k];
                }

                Sequence[s]=j;
                s++;
            }
        }
    }

    for(i=0; i<n; i++){
        if(Finish[i]==0){
            Unsafe=true;
        }
    }

    if(Unsafe==true){
        cout<< "\nthe system is in unsafe state" << endl;
    }
    else{
        cout<< "\nThe system is in safe state" << endl;
        cout<< "the safe sequence is: ";
        for(s=0; s<n; s++){
            cout << "P[" << Sequence[s] << "]" << " ";
        }
        cout<<endl;
    }



    //Resource Request taking for a specific

    cout<< "Enter 1 to request and 0 to end: ";
    cin >> e;
    if(e==1){
        cout<< "enter request for process [0-"<<n-1 << "]: ";
        cin>> r;

        Unsafe=false;
        s=0;

        cout<<"Enter Instances of Resources for P["<<r<<"]: ";
        for(j=0; j<m; j++){
            cin>> Request[r][j];

            Available[j] = Available[j]-Request[r][j];
            Allocation[r][j] = Allocation[r][j]+Request[r][j];
            Need[r][j] = Need[r][j]-Request[r][j];

            Work[j]=Available[j];
        }

        for(i=0; i<n; i++){
            Finish[i]=0;
        }
        goto safety;
    }
    else
        return 0;
}

/*
5
3
3 3 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

0 1 0
2 0 0
3 0 2
2 1 1
0 2 2
*/




