#include <iostream>
#include <stack>
using namespace std;
int n;
stack<int> q;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		string inp;
		int num;
		cin>>inp;
		if(inp=="push"){
			cin>>num;
			q.push(num);
		}
		if(inp=="top"){
			if(q.empty()){
				cout<<-1<<"\n";
				continue;
			}
			else cout<<q.top()<<"\n";
		}
		else if(inp=="pop"){
			if(q.empty()){
				cout<<-1<<"\n";
				continue;
			}
			else{
				int n = q.top();
				q.pop();
				cout<<n<<"\n";	
			} 
		}
		else if(inp=="size"){
			cout<<q.size()<<"\n";
		}
		else if(inp=="empty"){
			if(q.empty()){
				cout<<1<<"\n";
			}else{
				cout<<0<<"\n";
			}
		}
	}
	
	return 0;
}
