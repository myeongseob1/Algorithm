#include <iostream>
#include <algorithm> 

using namespace std;
int t;
long long int a[6],answer;
int main(void){
	cin>>t;
	for(int i=0;i<6;i++){
		cin>>a[i];
	}
	sort(a,a+6);
	answer = a[0]*(t-2)*4*(t-1) + (a[0]+a[1])*4*(t-1) + (a[0]+a[1]+a[2])*4 + (a[0]+a[1])*(t-2)*4 +(t-2)*(t-2);
	
	if(t!=1){
		printf("%lld",answer);	
	}
	else{
		cout<<a[0]+a[1]+a[2]+a[3]+a[4]<<"\n";
	}
	
	return 0;
}
