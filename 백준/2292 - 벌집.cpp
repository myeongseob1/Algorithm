#include <iostream>

using namespace std;
int n;
int main(void){
	cin>>n;
	int answer;
	for(int i=1;i<=50000;i++){
		if(3*i*i-3*i+1>=n){
			answer = i;
			break;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
