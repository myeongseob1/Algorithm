#include <iostream>

using namespace std;
int n;

int factorial(int t){
	if(t==1) return 1;
	if(t==0) return 1;
	return t * factorial(t-1);
}

int main(void){
	cin>>n;
	cout<<factorial(n)<<"\n";
}
