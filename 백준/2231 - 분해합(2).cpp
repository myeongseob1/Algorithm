#include <iostream>

using namespace std;
int n,answer;

int divsum(int num){
	int rslt = num;
	while(num!=0){
		rslt += num%10;
		num /= 10;
	}
	return rslt;
}

int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		if(divsum(i)==n){
			answer = i;
			break;
		}
		if(i==n){
			answer = 0;
		}
	}
	cout<<answer<<"\n"; 
	return 0;
}
