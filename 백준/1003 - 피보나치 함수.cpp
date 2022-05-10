#include <iostream>

using namespace std;
int a,b,n;
int dp_z[41],dp_o[41];

void fibonacci(int n){
	if(n==0){
		cout<<1<<" "<<0<<"\n";
		return;
	}
	else if(n==1){
		cout<<0<<" "<<1<<"\n";
		return;
	}
	else{
		dp_z[0] = 1;
		dp_o[1] = 1;
		for(int i=2;i<=n;i++){
			dp_z[i] = dp_z[i-1] + dp_z[i-2];
			dp_o[i] = dp_o[i-1] + dp_o[i-2];
		}
		cout<<dp_z[n]<<" "<<dp_o[n]<<"\n";
		return
	}
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		fibonacci(t);
	}
	
	return 0;
}
