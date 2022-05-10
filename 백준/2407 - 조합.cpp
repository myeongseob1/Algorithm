#include <iostream>

using namespace std;
int n,m;
long long ans = 1;
int main(void){
	cin>>n>>m;
	for(int i=n;i>n-m;i--){
		ans *= i;
	}
	for(int i=m;i>1;i--){
		ans /= i;
	}
	cout<<ans<<"\n";
	return 0;
}
