#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int n,m;
int num[10];
const int INF = 1000001;
int answer;
bool isbroken(int n){
	if(n==0){
		if(num[0]==1){
			return false;
		}
		else{
			return true;
		}
	}else{
		int tmp = n;
		while(tmp){
			if(num[tmp%10]==1){
				return false;
			}
			tmp /= 10;
		}
	}
	return true;
}
int len_number(int n){
	int len_ = 0;
	if(n==0){
		return 1;
	}
	else{
		while(n){
			len_++;
			n /= 10;
		}
		return len_;
	}
}
int main(void){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		num[t] = 1;
	}
	answer = 987654321;
	int ans2 = abs(n-100);
	for(int i=0;i<=INF;i++){
		if(isbroken(i)){
			answer = min(answer,abs(i-n)+len_number(i));
		}
	}
	answer = min(answer,ans2);
	cout<<answer<<"\n";
	return 0;
}
