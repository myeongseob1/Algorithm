#include <iostream>
#include <vector>
using namespace std;

int n,x;
vector<int> ve;
int main(void){
	cin>>n>>x;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		ve.push_back(a);
		
	}
	for(int i=0;i<ve.size();i++){
		if(ve[i]<x) cout<<ve[i]<<" ";
	}
	return 0;
} 
