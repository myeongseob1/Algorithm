#include <iostream>

using namespace std;

int main(void){
	int n;
	cin>>n;
	int answer,answer2;
	for(int i=1;i<=10000;i++){
		if((i*(i-1))/2+1<=n&&n<(i*(i+1))/2+1){
			answer = i;
			answer2 = (i*(i-1))/2+1;
			break;
		}
	}
	if(answer%2==1){
		cout<<answer-n+answer2<<"/"<<1+n-answer2<<"\n";
	}
	else{
		cout<<1+n-answer2<<"/"<<answer-n+answer2<<"\n";		
	}
	return 0;
} 
