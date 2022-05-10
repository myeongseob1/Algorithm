#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int k,n;
vector<int> ve;
long long answer;

int main(void){
	cin>>k>>n;
	for(int i=0;i<k;i++){
		int a;
		cin>>a;
		ve.push_back(a);		
	}
	long long start = 0;
	long long end = LLONG_MAX;
	while(start<=end){
		long long mid = (start+end)/2;
		long long leng = 0;
		for(int i=0;i<ve.size();i++){
			leng += ve[i]/mid;
		}
		if(leng>=n){
			answer = max(answer,mid);
			start = mid+1;
		}else{
			end = mid-1;
		}
	}
	
	cout<<answer<<"\n";
	return 0;
}
