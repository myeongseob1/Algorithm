#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ve;
int n,m;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		ve.push_back(a);
	}
	sort(ve.begin(),ve.end());
	cin>>m;
	for(int i=0;i<m;i++){
		int a;
		cin>>a;
		int start = 0;
		bool find = false;
		int end = ve.size()-1;
		while(start<=end){
			int mid = (start+end)/2;
			if(ve[mid]==a){
				find = true;
				cout<<1<<" ";
				break;
			}
			else if(ve[mid] < a){
				start = mid + 1;
			}
			else{
				end = mid-1;
			}
		}
		if(find==false){
			cout<<"0"<<" ";
		}
	}	
	
	return 0;
}
