#include<bits/stdc++.h>
using namespace std;
int main(){
    queue <int>que;
    int i, j, m, n, fault=0, last=0, point=0, temp1, temp2;
    bool flag =false;
    cout<<"Total Number of Reference Pages: ";
    cin>>n;
    cout<<"Enter Frame Size: ";
    cin>>m;
    int refstr[n], frame[m];
    cout<<"Enter Reference String: ";
    for(i=0;i<n;i++){
        cin>>refstr[i];
    }
    for(i=0;i<m;i++){
        frame[i]=0;
    }
    for(i=0;i<n;i++){
        que.push(refstr[i]);
        if(i>=m){
            point=que.front();
            que.pop();
            for(j=0;j<m;j++)if(frame[j]==point)last=j;
        }
        for(j=0;j<m;j++){
            if(frame[j]==refstr[i])flag=true;
        }
        if(flag==false){
            fault++;
            frame[last]=refstr[i];
            cout<<refstr[i]<<"||"<<endl;
            for(j=0;j<m;j++)cout<<frame[j]<<endl;
            if(i<m)last++;
        }
        else{
            if(refstr[i] != point){
                temp1=point;
                point=que.front();
                que.pop();
                temp2=que.front();
                while(!que.empty())que.pop();
                que.push(temp1);
                que.push(temp2);
                que.push(refstr[i]);
                if(refstr[i] != point){
                    temp2=point;
                    point=que.front();
                    que.pop();
                    while(!que.empty())que.pop();
                    que.push(temp1);
                    que.push(temp2);
                    que.push(refstr[i]);
                }
            }
            flag=false;
        }
    }
    cout<<"Number of Page Faults: "<<fault<<endl;
    return 0;
}
