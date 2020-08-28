#include <iostream>
#include <algorithm>

using namespace std;
int a[1000001];
int n;
int main(void){	
	cin>>n;
	for(int i=2;i<=n;i++){
		if(i%6==0){
			a[i] = min(a[i/2]+1,a[i/3] +1);
			a[i] = min(a[i],a[i-1]+1);
		}
		else if(i%3==0){
			a[i] = min(a[i/3] +1,a[i-1]+1);
		}
		else if(i%2==0){
			a[i] = min(a[i/2]+1,a[i-1]+1);
		}
		else{
			a[i] = a[i-1]+1;
		}
	}
	cout<<a[n]<<" ";
	return 0;
}
