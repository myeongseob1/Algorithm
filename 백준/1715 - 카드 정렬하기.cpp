#include <iostream>
#include <queue>

using namespace std;
int n;
priority_queue<int,vector<int>,greater<int> > pq;
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		pq.push(t);
	}
	int answer = 0;
	while(pq.size()>1){
		int a = 0;
		a = pq.top();
		pq.pop();
		a += pq.top();
		pq.pop();
		answer += a;
		pq.push(a);
	}
	cout<<answer<<"\n";
	return 0;
}
