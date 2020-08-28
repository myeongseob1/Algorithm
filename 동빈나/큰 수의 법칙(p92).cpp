#include <iostream>
#include <algorithm>

using namespace std;

int n,m,k,answer;
int a[10001];
int main(void){
	
	cin>>n>>m>>k;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int iter=0;
	int bigiter = 0;
	while(1){
		if(bigiter==m){
			break;
		}

		answer += a[n-1];
		iter++;
		bigiter++;
		if(iter==k){
			iter = 0;
			answer += a[n-2];
			bigiter++;
			continue;
		}
	}
	cout<<answer;
	return 0;
}
