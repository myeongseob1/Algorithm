#include <iostream>
#include <deque>

using namespace std;

int n;
deque<int> deq;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		string inp;
		cin>>inp;
		if(inp=="push_back"){
			int num;
			cin>>num;
			deq.push_back(num);
		}
		else if(inp=="push_front"){
			int num2;
			cin>>num2;
			deq.push_front(num2);
		}
		else if(inp=="pop_front"){
			if(deq.empty()){
				cout<<-1<<"\n";
			}else{
				cout<<deq.front()<<"\n";
				deq.pop_front();
			}
		}
		else if(inp=="pop_back"){
			if(deq.empty()){
				cout<<-1<<"\n";
			}else{
				cout<<deq.back()<<"\n";
				deq.pop_back();
			}
			
		}
		else if(inp=="size"){
			cout<<deq.size()<<"\n";
		}
		else if(inp=="front"){
			if(deq.empty()){
				cout<<-1<<"\n";
			}else{
				cout<<deq.front()<<"\n";
			}
		}
		else if(inp=="back"){
			if(deq.empty()){
				cout<<-1<<"\n";
			}else{
				cout<<deq.back()<<"\n";
			}
		}
		else if(inp=="empty"){
			if(deq.empty()){
				cout<<1<<"\n";
			}else{
				cout<<0<<"\n";
			}
		}
	}
	
	return 0;
}
