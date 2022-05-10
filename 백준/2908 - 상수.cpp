#include <iostream>

using namespace std;

int main(void){
	int a,b;
	cin>>a>>b;
	int aa = a/100 + (a%10)*100 + ((a%100)/10)*10;
	int bb = b/100 + (b%10)*100 + ((b%100)/10)*10;
	cout<<max(aa,bb)<<"\n";
}
