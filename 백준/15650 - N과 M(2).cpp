#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int ve[9];
vector<int> com;

int main(void){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		com.push_back(0);
	}
	for(int i=m;i<n;i++){
		com.push_back(1);
	}
	for(int i=0;i<n;i++){
		ve[i] = i+1;
	}
	do{
		for(int i=0;i<n;i++){
			if(com[i]==0){
				cout<<ve[i]<<" ";
			}
		}
		cout<<"\n";		
	}while(next_permutation(com.begin(),com.end()));
	return 0;
}
