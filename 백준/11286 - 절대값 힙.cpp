#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int n;
priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int b;
		cin>>b;
		if(b==0){
			if(pq.empty()){
				cout<<0<<"\n";
			}else{
				cout<<pq.top().second<<"\n";
				pq.pop();
			}
		}else{
			pq.push(make_pair(abs(b),b));
		}
	}
	return 0;
}
