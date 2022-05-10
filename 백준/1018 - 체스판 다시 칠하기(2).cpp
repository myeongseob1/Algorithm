#include <iostream>

using namespace std;

string lb[8]= { "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB" };
string lw[8] = {"WBWBWBWB" ,"BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW" };

string map[51];
int n,m;

int answer = 100;
int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>map[i];
	}
	
	for(int i=0;i<=n-8;i++){
		for(int j=0;j<=m-8;j++){
			int rslt = 0;
			int rslt2 = 0;
			for(int ii=i;ii<i+8;ii++){
				for(int jj=j;jj<j+8;jj++){
					if(lb[ii-i][jj-j]==map[ii][jj]){
						rslt++;
					}
					if(lw[ii-i][jj-j]==map[ii][jj]){
						rslt2++;
					}

				}
			}
			answer = min(rslt,answer);
			answer = min(rslt2,answer);
		}
	}
	cout<<answer<<"\n";
	return 0;
}
