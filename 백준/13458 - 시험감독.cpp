#include <iostream>

using namespace std;
int n;
int a[1000001];
int b,c;
long long int answer;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>b>>c;
	for(int i=0;i<n;i++){
		if(a[i] > 0){
			if(a[i]-b<=0){
				a[i] = 0;
				answer++;
			}else{
				a[i] -= b;
				answer++;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]>0){
			if(a[i]%c==0){
				answer += a[i]/c;
			}else{
				answer += a[i]/c +1;
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}
