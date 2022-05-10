#include <iostream>

using namespace std;
int n,m;
int inp[101];
int answer = 0;
int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>inp[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) continue;
			for(int k=0;k<n;k++){
				if(j==k||i==k) continue;
				if(inp[i]+inp[j]+inp[k]<=m) answer = max(answer,inp[i]+inp[j]+inp[k]);				
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}
