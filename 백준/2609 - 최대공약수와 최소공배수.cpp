#include <iostream>

using namespace std;
int n,m;

int gcd(int a,int b){
	while(b!=0){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;	
}

int lcm(int a,int b,int gcd){
	return (a * b) / gcd;
}

int main(void){
	cin>>n>>m;
	int answer_gcd = gcd(n,m);
	int answer_lcm = lcm(n,m,answer_gcd);
	cout<<answer_gcd<<"\n"<<answer_lcm<<"\n";
	return 0;
}
