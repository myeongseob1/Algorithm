#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,c;
vector<int> ve;
int answer;

int main(void){
	cin>>n>>c;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		ve.push_back(t);
	}	
	sort(ve.begin(),ve.end());
	int start = 0;
	int end = ve.back() - ve.front();
	while(start<=end){
		int mid = (start+end)/2;
		int st = ve[0];
		int cnt = 1;
		for(int i=1;i<n;i++){
			int d = ve[i] - st;
			if(mid <= d){
				cnt++;
				st = ve[i];
			}
		}
		if(cnt >= c){
			answer = mid;
			start = mid + 1;
		}
		else{
			end = mid -1;
		}
	}
	cout<<answer<<"\n";
	return 0;	
}
