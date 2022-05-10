#include <iostream>

using namespace std;
int n;

long long fibonacci(long long n){
	if(n==0) return 0;
	if(n==1) return 1;
	return fibonacci(n-2)+fibonacci(n-1);
}

int main(void){
	cin>>n;
	cout<<fibonacci(n)<<"\n";
	return 0;
} 
