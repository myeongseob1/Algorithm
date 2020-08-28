#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int answer[8];
void go(int iter,int N,int M){
	if(iter == M){
		for(int i=0;i<iter;i++){
			cout<<answer[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	
	for(int i=0;i<N;i++){
		answer[iter] = i+1;
		go(iter+1,N,M);	
	}
}



int main(void){
	int N,M;
	cin>>N>>M;
	go(0,N,M);
	
	
	return 0;
}
