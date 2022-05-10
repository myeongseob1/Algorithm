#include <iostream>

using namespace std;
int n;
int main(void){
	cin>>n;
	int answer = 0;
	for(int i=1;i<=n;i++){
		int tmp = i;
		int de = 0;
		while(1){
			if(tmp==0) break;
			de += tmp%10;
			tmp /= 10;
		}
		if(de+i==n){
			answer = i;	
			break;
		} 
	}
	cout<<answer<<"\n";
	return 0;
}
