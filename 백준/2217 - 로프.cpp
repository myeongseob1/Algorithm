#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> ve;
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
	reverse(ve.begin(),ve.end());
	for(int i=0;i<ve.size();i++){
		answer = max(answer,(i+1)*ve[i]);
	} 
	cout<<answer<<"\n";
}
