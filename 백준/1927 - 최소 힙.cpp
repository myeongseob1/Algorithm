#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp{
	bool operator()(int a,int b){
		if(abs(a)==abs(b)){
			return a>b;
		}
		return abs(a)>abs(b);
	}
};


priority_queue<int,vector<int>,cmp > pq;
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
		else pq.push(t);
	}	
	
	return 0;
} 
