#include <iostream>

using namespace std;
int n,k;
int main(void){
	cin>>n>>k;
	int answer = 1;
	for(int i=n;i>n-k;i--){
		answer *= i;
	}
	for(int i=1;i<=k;i++){
		answer /= i;
	}
	cout<<answer<<"\n";
	return 0;
}
