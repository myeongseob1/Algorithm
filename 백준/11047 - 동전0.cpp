#include <iostream>
#include <algorithm>

using namespace std;
int n,k,answer;
int a[11];
int main(void){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	sort(a,a+n);
	while(1){
		if(k>=a[n-1]){
			k-=a[n-1];
			answer++;
		}
		for(int i=0;i<n-1;i++){
			if(k>=a[i]&&k<a[i+1]){
				k-=a[i];
				answer++;	
			}
		}
		if(k==0){
			break;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
