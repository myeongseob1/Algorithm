#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,k,t,answer=0;
vector<int> p;

void sum(int iter, int ac){
	if(ac == k){
		answer++;
		return;
	}
	if(ac>k){
		return;
	}
	if(iter>=n){
		return;
	}
	sum(iter+1,p[iter]+ac);
	sum(iter+1,ac);	
}


int main(void){
	int iter;
	cin>>iter;
	for(int i=0;i<iter;i++){
		cin>>n>>k;
		for(int j=0;j<n;j++){
			cin>>t;
			p.push_back(t);
		}
		sum(0,0);
		cout<<"#"<<i+1<<" "<<answer<<"\n";
		answer =0;
		p.clear();
	}
	return 0;
}
