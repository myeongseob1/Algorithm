#include <iostream>

using namespace std;
int a,b,v,result,answer;
int main(void){
	cin>>a>>b>>v;
	while(1){
		answer++;
		result = result+a;
		if(result>=v){
			break;
		}
		result = result-b;
	}
	cout<<answer<<"\n"; 
	return 0;
}
