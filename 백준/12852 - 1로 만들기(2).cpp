#include <iostream>
#include <algorithm>

using namespace std;
int a[1000001];
int b[1000001];
int n;
int main(void){	
	cin>>n;
	for(int i=2;i<=n;i++){
		a[i] = a[i-1] + 1;
		b[i] = i-1;
		if(i%3==0&&a[i/3]<a[i-1]&&a[i]>a[i/3]+1){
				a[i] = a[i/3] + 1;
				b[i] = i/3;
		}
		if(i%2==0&&a[i/2]<a[i-1]&&a[i]>a[i/2]+1){
				a[i] = a[i/2]+1;
				b[i] = i/2;
		}
	}
	cout<<a[n]<<"\n";
	cout<<n<<" ";
	for(int i=n;i>1;i=b[i]){
		cout<<b[i]<<" ";
	}
	return 0;
}
