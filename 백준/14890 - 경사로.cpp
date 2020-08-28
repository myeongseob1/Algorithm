#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[101][101];
int a_reverse[101][101];
int d_r[101][101];
int d_c[101][101];
int n,l,answer;
int main(void){
	cin>>n>>l;
	int fail_r[101] = {0,};
	int fail_c[101] = {0,};
	int answer = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j] = a_reverse[101][101];
		}
	}
	//행의 모든 숫자가 다 같을경우 
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(a[i][j]-a[i][j+1]==1){
				if(j+l>=n){
					fail_r[i]++;
					continue;	
				} 
				for(int t=j+1;t<j+l+1;t++){
					d_r[i][t]++;
				}
			}
			if(a[i][j]-a[i][j+1]==-1){
				if(j-l+1<0){
					fail_r[i]++;
					continue;	
				}
				for(int t=j;t>j-l;t--){
					d_r[i][t]++;
				} 
			}
			if(a[i][j]-a[i][j+1]>1||a[i][j]-a[i][j+1]<-1){
				fail_r[i]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(d_r[i][j]>1) fail_r[i]++;
		}
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<n-1;i++){
			if(a[i][j]-a[i+1][j]==1){
				if(i+l>=n){
					fail_c[j]++;
					continue;	
				} 
				for(int t=i+1;t<i+l+1;t++){
					d_c[t][j]++;
				}
			}
			if(a[i][j]-a[i+1][j]==-1){
				if(i-l+1<0){
					fail_c[j]++;
					continue;	
				}
				for(int t=i;t>i-l;t--){
					d_c[t][j]++;
				} 
			}
			if(a[i][j]-a[i+1][j]>1||a[i][j]-a[i+1][j]<-1){
				fail_c[j]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(d_c[j][i]>1) fail_c[i]++;
		}
	}

	for(int i=0;i<n;i++){
		if(fail_r[i]==0) answer++;
		if(fail_c[i]==0) answer++;

	}
	cout<<answer<<"\n";
	
	return 0;
}
