#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[8],answer[8];
vector<int> p;
void go(int iter,int start,int N,int M){
	if(iter == M){
		for(int i=0;i<M;i++){
			cout<<p[answer[i]]<<" ";		
		}
		cout<<"\n";
		return;
	}
	for(int i=start;i<N;i++){
		if(cnt[i]>0){
			cnt[i]--;
			answer[iter] = i;
			go(iter+1,i,N,M);
			cnt[i]++;			
		}
	}
		
}


int main(void){
	int n,m,temp[8],ju=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>temp[i];	
	}
	sort(temp,temp+n);
	p.push_back(temp[0]);
	cnt[ju]=1;
	for(int i=1;i<n;i++){
		if(temp[i]==temp[i-1]){
			cnt[ju]++;
		}
		else{
			p.push_back(temp[i]);
			ju++;
			cnt[ju] = 1;
		}
	}
	go(0,0,n,m);
	return 0;
}
