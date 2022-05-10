#include <iostream>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,less<int> > max_pq;
priority_queue<int,vector<int>,greater<int> > min_pq;

int n;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(max_pq.size()>min_pq.size()){
			min_pq.push(t);
		}else{
			max_pq.push(t);
		}
		if(!max_pq.empty()&&!min_pq.empty()){
			if(max_pq.top()>min_pq.top()){
				int max_tp = max_pq.top();
				max_pq.pop();
				int min_tp = min_pq.top();
				min_pq.pop();
				min_pq.push(max_tp);
				max_pq.push(min_tp);
			}
		}
		cout<<max_pq.top()<<"\n";
	}	
	
	return 0;
} 
