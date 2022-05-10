#include <iostream>
#include <deque>
using namespace std;
int n,k;
deque<int> dq;
int main(void){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		dq.push_back(i);
	}
	cout<<"<";
	while(!dq.empty()){
		for(int i=0;i<k-1;i++){
			int tmp = dq[0];
			dq.pop_front();
			dq.push_back(tmp);
		}
		int tmp2 = dq[0];
		cout<<tmp2;
		dq.pop_front();
		if(!dq.empty()){
			cout<<", ";
		}		
	}
	cout<<">"<<"\n";
	return 0;
}
