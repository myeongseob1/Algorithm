#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int man[1000010];
int total, sub;
long long int answer=0;
int main(void){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>man[i];
	}
	cin>>total>>sub;
	answer += n;
	for(int i=0;i<n;i++){
		if(total>man[i]){
			man[i] = 0;
		}
		else{
			man[i] -= total;		
		}
	}
	for(int i=0;i<n;i++){
		if(man[i]%sub == 0){
			man[i] = man[i]/sub;
		}
		else{
			man[i] = man[i]/sub +1;
		}
	}
	for(int i=0;i<n;i++){
		answer += man[i];
	}
	cout<<answer<<"\n";
	return 0;
}
