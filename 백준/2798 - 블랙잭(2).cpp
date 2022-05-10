#include <iostream>

using namespace std;
int card[101];
int main(void){
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>card[i];
	}
	int answer = 0;
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			for(int k=0;k<a;k++){
				if(i==j||i==k||j==k) continue;
				if(card[i]+card[j]+card[k]<=b){
					answer = max(answer,card[i]+card[j]+card[k]);	
				}
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}
