#include <iostream>

using namespace std;
int a,b,v,answer;
int main(void){
	cin>>a>>b>>v;
	if((v-a)%(a-b)==0){
		answer = ((v-a)/(a-b)) + 1;
	}else{
		answer = ((v-a)/(a-b)) + 2;		
	}
	cout<<answer<<"\n";
	return 0;
} 
