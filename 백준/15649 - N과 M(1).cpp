#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> result;
int answer[8];
vector<int> tmp;
void go(int iter,int a, int b){
	if(iter == b){
		for(int i=0;i<b;i++){
			cout<<answer[i]<<" ";			
		}
		cout<<"\n";

		return;
	}
	for(int i=0;i<a;i++){
		if(tmp[i]==0) continue;
		tmp[i]=0;
		answer[iter]=i+1;
		go(iter+1,a,b);
		tmp[i]=1;	
	}
	
}


int main(void){
	
	int a,b;
	cin>>a>>b;

	for(int i=0;i<a;i++){
		tmp.push_back(1);
	}
	go(0,a,b);
	return 0;
}
