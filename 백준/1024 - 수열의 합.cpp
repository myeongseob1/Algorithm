#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

int main(void){
	int n,l;
	vector<int> p;
	cin>>n>>l;

	for(int i=l;i<=100;i++){
		int answer=0;
		if(n%i==i/2&&i%2==0){
			if(n/i-i/2+1<0){
				continue;
			}
			for(int k=n/i-i/2+1;k<=n/i+i/2;k++){
				answer += k;	
			}
			if(answer == n){
				for(int k=n/i-i/2+1;k<=n/i+i/2;k++){
					p.push_back(k);	
				}
				break;							
			}

		}
		else if(n%i==0&&i%2==1){
			if(n/i-i/2<0){
				continue;
			}
			for(int k=n/i-i/2;k<=n/i+i/2;k++){
				answer += k;	
			}
			if(answer == n){
				for(int k=n/i-i/2;k<=n/i+i/2;k++){
					p.push_back(k);	
				}
				break;							
			}	
		}
	
	}
	if(p.size()==0){
		cout<<-1<<"\n";
	}
	else{
		for(int i=0;i<p.size();i++){
			cout<<p[i]<<" ";
		}	
	}
	return 0;
}
