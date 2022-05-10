#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,k;
vector<int> answer;
queue<int> q;
int main(void){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	while(!q.empty()){
		for(int i=0;i<k-1;i++){
			if(!q.empty()){
				int n = q.front();
				q.pop();
				q.push(n);
			}
		}
		if(!q.empty()){
			answer.push_back(q.front());
			q.pop();
		}  
		
	}
	cout<<"<";
	for(int i=0;i<answer.size()-1;i++){
		cout<<answer[i]<<", ";
	}
	cout<<answer[answer.size()-1]<<">";
	return 0;
}

