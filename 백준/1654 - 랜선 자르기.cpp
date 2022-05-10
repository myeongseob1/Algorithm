#include <iostream>
#include <climits>
using namespace std;
int k,n;
long long a[10001];
long long result = 0;
int main(void){
	ios_base::sync_with_stdio(0);
    cin.tie(0); 
	cin>>k>>n;
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	long long start = 0;
	long long end = LLONG_MAX;
	while(start<=end){
		long long mid = (start + end)/2;
		long long answer = 0;
		for(int i=0;i<k;i++){
			answer += a[i]/mid;
		}
		if(answer>=n){
			result = max(result,mid);
			start = mid+1;
		}
		if(answer<n){
			end = mid-1;
		}
	}
	cout<<result<<"\n";
	return 0;
} 
