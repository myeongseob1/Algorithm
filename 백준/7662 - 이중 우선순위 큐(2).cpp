#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int,vector<int>,less<int> >  pq;

void min_pop(){
	priority_queue<int,vector<int>,greater<int> > min_pq;
	while(!pq.empty()){
		min_pq.push(pq.top());
		pq.pop();
	}
	min_pq.pop();
	while(!min_pq.empty()){
		pq.push(min_pq.top());
		min_pq.pop();
	}

}

int min_print(){
	priority_queue<int,vector<int>,greater<int> > min_pq;
	while(!pq.empty()){
		min_pq.push(pq.top());
		pq.pop();
	}
	return min_pq.top();	
}

int main(void){
	int test_case;
	cin>>test_case;
	for(int iii=0;iii<test_case;iii++){
		int t;
		priority_queue<int,vector<int>,less<int> > clr;
		pq = clr;
		cin>>t;
		for(int i=0;i<t;i++){
			string a;
			int b;
			cin>>a>>b;
			if(a=="I"){
				pq.push(b);
			}
			else if(a=="D"){
				if(b==-1){
					if(!pq.empty()){
						min_pop();
					}
				}
				else if(b==1){
					if(!pq.empty()){
						pq.pop();
					}
				}
			}
		}
		if(pq.empty()){
			cout<<"EMPTY"<<"\n";
		}
		else{
			cout<<pq.top()<<" ";
			cout<<min_print()<<"\n";
		}
		
	}
	
	return 0;
}
