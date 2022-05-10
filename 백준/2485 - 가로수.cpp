#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ve;
vector<int> ve2;
int n;
int answer;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		ve.push_back(t);
	}	
	sort(ve.begin(),ve.end());
	for(int i=1;i<ve.size();i++){
		ve2.push_back(ve[i]-ve[i-1]);
	}
	sort(ve2.begin(),ve2.end());
	int t = ve2[0];
	bool de = true;
	for(int i=ve2[0];i>=1;i--){
		t = i;
		for(int j=0;j<ve2.size();j++){
			if(ve2[j]%i!=0){
				de = false;
				break;
			}
		}
		if(de) break;
		de = true;
	}
	cout<<t<<"\n";

	int p = ve[0];
	int idx = 1;
	while(1){
		if(ve[idx]-p==t){
			p = ve[idx];			
			idx++;
		}
		else{
			answer++;
			p += t;
		}
		if(idx>=ve.size()) break;
	}
	cout<<answer<<"\n";
	return 0;
} 
