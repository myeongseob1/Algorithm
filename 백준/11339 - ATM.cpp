#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> ve;
int n;

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		ve.push_back(a);
	}
	sort(ve.begin(),ve.end());
	int answer = 0;
	for(int i=0;i<ve.size();i++){
		for(int j=0;j<=i;j++){
			answer += ve[j];		
		}
	}
	cout<<answer<<"\n";
	return 0;
}
