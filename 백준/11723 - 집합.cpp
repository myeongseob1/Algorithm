#include <iostream>

using namespace std;
int n;
bool state[21];
int main(void){

	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n;
	for(int i=0;i<n;i++){
		string a;
		int b;
		cin>>a;
		if(a=="all"){
			for(int i=1;i<=20;i++){
				state[i] = true;
			}
		}
		else if(a=="empty"){
			for(int i=1;i<=20;i++){
				state[i] = false;
			}		
		}
		else{
			cin>>b;
			if(a=="add"){
				if(state[b]==false) state[b] = true;
			}
			else if(a=="remove"){
				if(state[b]==true) state[b] = false;				
			}
			else if(a=="check"){
				if(state[b]==true) cout<<1<<"\n";
				else cout<<0<<"\n";
			}
			else if(a=="toggle"){
				if(state[b]==true) state[b] = false;
				else state[b] = true;
				
			}
			
		}
	}
	
	return 0;
} 
