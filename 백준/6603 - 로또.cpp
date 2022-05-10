#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main(void){
	while(1){
		int n;
		cin>>n;
		if(n==0){
			break;
		}
		vector<int> ve;
		vector<int> com;
		for(int i=0;i<n;i++){
			int t;
			cin>>t;
			ve.push_back(t);
			com.push_back(1);
		}
		for(int i=0;i<6;i++){
			com[i] = 0;
		}
		do{
			for(int i=0;i<n;i++){
				if(com[i]==0){
					cout<<ve[i]<<" ";
				}
			}
			cout<<"\n";
		}while(next_permutation(com.begin(),com.end()));
		cout<<"\n";
	}
}
