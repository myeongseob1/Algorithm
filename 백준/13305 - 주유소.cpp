#include <iostream>

using namespace std;
long long int village[100001];
long long int road[100001];
int n;
int main(void){
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>road[i];
	}
	for(int i=0;i<n;i++){
		cin>>village[i];
	}
	long long int oil = village[0];
	long long int answer = 0;
	for(int i=0;i<n-1;i++){
		answer += oil * road[i];
		oil = min(oil,village[i+1]);
	}
	cout<<answer<<"\n";
	return 0;
}
