#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> t;
int main(void){
	int iter;
	cin>>iter;
	for(int i=0;i<iter;i++){
		long long int a,b,answer;
		cin>>a>>b;
		if(b%4==0){
			answer = pow(a,4);
		}
		else{
			answer = pow(a,b%4);		
		}
		if(a%10==0){
			cout<<10<<"\n";
		}
		else cout<<answer%10<<"\n";
	}

}
