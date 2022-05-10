#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> ve1,ve2;

bool compare(int i,int j){
	return j<i;
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		ve1.push_back(a);
	}
	for(int j=0;j<n;j++){
		int a;
		cin>>a;
		ve2.push_back(a);
	}
	int answer = 0;
	sort(ve1.begin(),ve1.end());
	sort(ve2.begin(),ve2.end(),compare);
	for(int i=0;i<ve1.size();i++){
		answer += ve1[i] * ve2[i];
	}
	cout<<answer<<"\n";
	return 0;
}
