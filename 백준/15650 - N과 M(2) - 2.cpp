#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int N,M;
	cin>>N>>M;
	vector<int> whole(N),tmp(N);
	for(int i=0;i<N;i++){
		whole[i] = i+1;
		tmp[i] = 1;
	}
	for(int i=0;i<M;i++){
		tmp[i] = 0;
	}
	
	do{
		for(int i=0;i<N;i++){
			if(tmp[i]==0){
				cout<<whole[i]<<" ";
			}
		}
		cout<<"\n";	
		
	}while(next_permutation(tmp.begin(),tmp.end()));
	
	return 0;
}
