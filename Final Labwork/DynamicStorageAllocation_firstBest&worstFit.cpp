#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,j;
    cout<<"Enter Number of Holes: ";
    cin>>n;

    int Hole[n],Process;
    cout<<"Enter Size of Holes: ";
    for(i=0;i<n;i++)
        cin>>Hole[i];

    cout<<"Enter Process Size: ";
    cin>>Process;

    cout<<"First Fit Hole is of Size: "<<Hole[0]<<endl;

    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(Hole[j]<Hole[i])
                swap(Hole[j], Hole[i]);
        }
    }
    for(i=0;i<n;i++){
        if(Process<=Hole[i]){
            cout<<"Best Fit Hole is of Size: "<<Hole[i]<<endl;
            break;
        }
    }
    cout<<"Worst Fit Hole is of Size: "<<Hole[n-1]<<endl;
    return 0;
}
