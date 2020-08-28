#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

void print(int iter, vector<int> b){
	vector<int> help(iter);
	for(int i=0;i<iter;i++){
		help[i]=0;
	}
	for(int i=6;i<iter;i++){
		help[i] =1;
	}
	do{
		for(int i=0;i<iter;i++){
			if(help[i]==0){
				cout<<b[i]<<" ";
			}
		}
		cout<<'\n';
	}while(next_permutation(help.begin(),help.end()));
	
}


int main(){
	int iter;
	while(cin>>iter&&iter){
		vector<int> num(iter);
		for(int i=0;i<iter;i++){
			cin>>num[i];
		}
		print(iter,num);		

	}


	return 0;
}
