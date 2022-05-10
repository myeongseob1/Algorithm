#include <iostream>

using namespace std;

int n,m;

int gcd(int a,int b){
	int c;
	while(b!=0){
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a,int b){
	return a*b/gcd(a,b);
}

int main(void){
	cin>>n>>m;
	cout<<gcd(n,m)<<"\n"<<lcm(n,m)<<"\n";
	return 0;
}
