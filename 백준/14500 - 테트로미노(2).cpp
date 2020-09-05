#include <iostream>

using namespace std;
int a[501][501];
int n,m;
int answer;
int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j+3<m) answer = max(answer,a[i][j]+a[i][j+1]+a[i][j+2]+a[i][j+3]);
			if(i+3<n) answer = max(answer,a[i][j]+a[i+1][j]+a[i+2][j]+a[i+3][j]);
			if(i+1<n&&j+1<m) answer = max(answer,a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1]);
			if(i+2<n&&j+1<m){
				answer = max(answer,a[i][j]+a[i+1][j]+a[i+2][j]+a[i+2][j+1]);
				answer = max(answer,a[i+2][j]+a[i+2][j+1]+a[i+1][j+1]+a[i][j+1]);
				answer = max(answer,a[i][j]+a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]);
				answer = max(answer,a[i][j]+a[i+1][j]+a[i+2][j]+a[i][j+1]);
				answer = max(answer,a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i+2][j]);
				answer = max(answer,a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+2][j+1]);
				answer = max(answer,a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]+a[i+1][j]);
				answer = max(answer,a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+2][j]);
			}
			if(i+1<n&&j+2<m){
				answer = max(answer,a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j]);				
				answer = max(answer,a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+2]);
				answer = max(answer,a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]);
				answer = max(answer,a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]+a[i][j+2]);
				answer = max(answer,a[i][j]+a[i][j+1]+a[i+1][j+1]+a[i+1][j+2]);
				answer = max(answer,a[i+1][j]+a[i+1][j+1]+a[i][j+1]+a[i][j+2]);
				answer = max(answer,a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]);
				answer = max(answer,a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1]);

			}
			
		}
	}
	
	cout<<answer<<"\n";
	return 0;	
} 
