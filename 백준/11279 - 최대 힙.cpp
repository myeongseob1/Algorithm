#include <iostream>
#include <queue>

using namespace std;
priority_queue< int, vector<int>, less<int> > pq;
int n;
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		int p;
		cin>>p;
		if(p==0){
			if(pq.empty()){
				cout<<0<<"\n";
			}
			else{
				cout<<pq.top()<<"\n";
				pq.pop();
			}
		}else{
			pq.push(p);
		} 
	}
	return 0;
}
