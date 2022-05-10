#include <iostream>

using namespace std;
int answer = 987654321;
int main(void){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(3*i+5*j==n){
				answer = min(i+j,answer);
			}
		}
	}
	if(answer==987654321) answer = -1;	
	cout<<answer<<"\n";
	return 0;
} 
