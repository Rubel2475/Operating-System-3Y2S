// Banker's Algorithm
#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,m,i,j,k;

	cout << "Enter the number of processes: ";
	cin >> n;
	cout << "Enter the number of resourses: ";
	cin >> m;

	int TotalIns[m]={0},available[m]={0}, res[m]={0};

	cout<< "Enter the total instances: \n";
	for(i=0; i<m; i++){
        cin>> TotalIns[i];
    }

	int allocate[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix
						{ 2, 0, 0 }, // P1
						{ 3, 0, 2 }, // P2
						{ 2, 1, 1 }, // P3
						{ 0, 0, 2 } }; // P4

	int request[5][3] = { { 0, 0, 0 }, // P0 // MAX Matrix
					{ 2, 0, 2 }, // P1
					{ 0, 0, 0 }, // P2
					{ 1, 0, 0 }, // P3
					{ 0, 0, 2 } }; // P4

	/*int allocate[n][m];
	int max_demand[n][m];

	for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin>> allocate[i][j];
        }
	}

	for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin>> max_demand[i][j];
        }
	}*/

	for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            res[i] =  res[i] + allocate[j][i];
        }
        available[i] = TotalIns[i] - res[i];
	}

	int finish[n], ans[n], ind=0;

	for(k=0; k<n; k++){
		finish[k]=0;
	}

	int y=0;
	for(k=0; k<5; k++){
		for(i=0; i<n; i++){
			if(finish[i]==0){
				int flag=0;
				for(j=0; j<m; j++){
					if(request[i][j] > available[j]){
						flag=1;
						break;
					}
				}

				if (flag==0){
					ans[ind++]=i;
					for(y=0; y<m; y++)
						available[y] += allocate[i][y];
                        finish[i] = 1;
				}
			}
		}
	}

	printf("The safe Sequence: ");
	for (i=0; i<n-1; i++)
		printf("  P%d ->", ans[i]);
	printf(" P%d\n", ans[n-1]);

	return (0);
}


