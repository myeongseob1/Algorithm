#include <iostream>
#include <queue>
using namespace std;
int n;
queue<int> q;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		string inp;
		int num;
		cin>>inp;
		if(inp=="push"){
			cin>>num;
		}
		if(inp=="front"){
			if(q.empty()){
				cout<<-1<<"\n";
				continue;
			}
			else cout<<q.front()<<"\n";
		}
		else if(inp=="pop"){
			if(q.empty()){
				cout<<-1<<"\n";
				continue;
			}
			else{
				int n = q.front();
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
		}else if(inp=="back"){
			if(q.empty()){
				cout<<-1<<"\n";
			}else{
				int n = q.back();
				cout<<n<<"\n";
			}		
		}
		else if(inp[0]=='p'&&inp[1]=='u'){
			q.push(num);
		}
	}
	
	return 0;
}
