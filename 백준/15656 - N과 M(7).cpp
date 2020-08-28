#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int answer[8];
void go(int iter,int N,int M, vector<int> &a){
	if(iter == M){
		for(int i=0;i<iter;i++){
			cout<<answer[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	
	for(int i=0;i<N;i++){
		answer[iter] = a[i];
		go(iter+1,N,M,a);
	}
	
}

int main(void){
	int N,M;
	cin>>N>>M;
	vector<int> num(N);
	for(int i=0;i<N;i++){
		cin>>num[i];
	}
	sort(num.begin(),num.end());
	go(0,N,M,num);
	return 0;
}
