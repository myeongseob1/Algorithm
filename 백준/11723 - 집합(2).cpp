#include <iostream>

using namespace std;

int n;
bool a[21];

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++){
		string aa;
		cin>>aa;
		int b;
		if(aa=="add"){
			cin>>b;
			a[b] = true;		
		}
		else if(aa=="check"){
			cin>>b;
			if(a[b]){
				cout<<1<<"\n";
			}
			else{
				cout<<0<<"\n";
			}
		}
		else if(aa=="remove"){
			cin>>b;
			if(a[b]){
				a[b] = false;				
			}
		}
		else if(aa=="toggle"){
			cin>>b;
			if(a[b]){
				a[b] = false;
			}else{
				a[b] = true;
			}
		}
		else if(aa=="all"){
			for(int i=1;i<=20;i++){
				a[i] = true;
			}
		}
		else if(aa=="empty"){
			for(int i=1;i<=20;i++){
				a[i] = false;
			}			
		}
	}
	return 0;
}
