#include <iostream>

using namespace std;
int n,k;
int coi[11];
int answer;
int main(void){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>coi[i];
	}
	while(1){
		int idx = 0;
		if(k>=coi[n-1]){
			k-= coi[n-1];
			answer++;
		} 
		for(int i=n-1;i>=1;i--){
			if(k>=coi[i-1]&&k<coi[i]){
				k -= coi[i-1];
				answer++;
				break;
			}
		}
		if(k==0){
			break;
		}
	}
	cout<<answer<<"\n";
	return 0;
} 
