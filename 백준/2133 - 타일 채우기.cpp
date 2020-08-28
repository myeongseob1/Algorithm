#include <iostream>

using namespace std;
int d[31];
int n;
int main(void){
	cin>>n;
	d[0] = 1;
	d[2] = 3;
	
	for(int i=4;i<=n;i=i+2){
		d[i] = 3*d[i-2];
		for(int k=0;k<=i-4;k=k+2){
			d[i] += 2*d[k];	
		}
	} 	
	cout<<d[n]<<"\n";
	
	return 0;
}
