#include <iostream>
#include <cmath>
using namespace std;

int zari(int n){
	if(n==0) return 1;
	int t = 0;
	while(n!=0){
		n /= 10;
		t++;
	}
	return pow(10,t-1);
}

int main(void){
	int x = 0;
	cout<<zari(x)<<" ";
	cout<<(x%10)*zari(x) + x/10<<" "<<x%zari(x) * 10  + x/zari(x)<<"\n";
	return 0;
}
