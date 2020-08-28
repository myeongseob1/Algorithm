#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int answer[8],option[8];
void go(int iter,vector<int> &num,int N,int M){
	if(iter == M){
		for(int i=0;i<M;i++){
			cout<<answer[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=0;i<N;i++){
		if(option[i]==0) continue;
		option[i] = 0;
		answer[iter] = num[i];
		go(iter+1,num,N,M);
		option[i] = 1;
	}
} 


int main(void){	
	int N,M;
	cin>>N>>M;
	vector<int> num(N);
	for(int i=0;i<N;i++){
		cin>>num[i];
		option[i] = 1;
	}
	sort(num.begin(),num.end());
	go(0,num,N,M);
	
	return 0;
}
