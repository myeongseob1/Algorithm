#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main(void){
	cin>>n;
	for(int ii=0;ii<n;ii++){
		int a,b,answer = 0;
		deque<pair<int,int> > q;
		vector<int> ve;
		cin>>a>>b;
		for(int i=0;i<a;i++){
			int t;
			cin>>t;
			q.push_back(make_pair(t,i));
			ve.push_back(t);
		}
		sort(ve.begin(),ve.end());
		reverse(ve.begin(),ve.end());
		int idx = 0;
		while(1){
			if(q[0].second==b&&ve[idx]==q[0].first){
				answer++;
				break;
			}			

			if(ve[idx]==q[0].first){
				answer++;
				idx++;
				if(idx==ve.size()) idx = 0;
				q.pop_front();

			}else{
				pair<int,int> tmp = q[0];
				q.pop_front();
				q.push_back(tmp);
			}
		}
		cout<<answer<<"\n";
	}
	
	return 0;
}
