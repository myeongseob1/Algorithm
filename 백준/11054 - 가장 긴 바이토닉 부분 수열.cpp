#include <iostream>

using namespace std;
int n;
int num[1001];
int dp_in[1001];
int dp_de[1001];
int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		dp_in[i] = 1;
		dp_de[i] = 1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(num[i]>num[j]){
				dp_in[i] = max(dp_in[i],dp_in[j]+1);
			}
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=n;j>i;j--){
			if(num[i]>num[j]){
				dp_de[i] = max(dp_de[i],dp_de[j]+1);
			}
		}
	}
	int answer = 0;
	for(int i=1;i<=n;i++){
		answer = max(answer,dp_in[i]+dp_de[i]);
	}
	cout<<answer-1<<"\n";
	return 0;
}
