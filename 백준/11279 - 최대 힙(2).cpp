#include <iostream>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,less<int> > pq;
int n;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(t==0){
			if(pq.empty()){
				cout<<0<<"\n";
			}
			else{
				cout<<pq.top()<<"\n";
				pq.pop();
			}
		}
		else if(t>0)pq.push(t);
	}	
	
	return 0;
} 
