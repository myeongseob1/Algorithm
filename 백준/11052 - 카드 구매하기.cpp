#include <iostream>

using namespace std;
int a[1001];
int d[1001];
int n;
int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	d[1] = a[1];
	d[2] = max(a[1]*2,a[2]); 
	for(int i=3;i<=n;i++){
		for(int k=0;k<=i;k++){
			d[i] = max(d[i-k]+a[k],d[i]);
		}
	}
	cout<<d[n]<<"\n";
	return 0;
} 
