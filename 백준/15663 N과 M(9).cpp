#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int answer[8],cnt[8];
vector<int> p;
void go(int iter,int N,int M){
	if(iter == M){
		for(int i=0;i<M;i++){
			cout<<p[answer[i]]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i=0;i<N;i++){
		if(cnt[i]>0){
			cnt[i] -= 1;
			answer[iter] = i;
			go(iter+1,N,M);
			cnt[i]+=1;
		}
	}
} 


int main(void){	
	int N,M,ju=0;
	cin>>N>>M;
	vector<int> num(N);
	for(int i=0;i<N;i++){
		cin>>num[i];
		cnt[i] = 0;
	}
	sort(num.begin(),num.end());
	p.push_back(num[0]);
	cnt[0]++;
	for(int i=1;i<N;i++){
		if(num[i]==num[i-1]){
			cnt[ju]++;
		}
		else{
			p.push_back(num[i]);
			ju++;
			cnt[ju] =1;
		}
	}
	go(0,N,M);
	
	return 0;
}
