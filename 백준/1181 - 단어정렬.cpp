#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> ve;
int n;

bool compare(string a,string b){
	if(a.length()==b.length()){
		return a<b;
	}
	return a.length()<b.length();
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		string a;
		cin>>a;
		ve.push_back(a);
	}
	sort(ve.begin(),ve.end(),compare);
	ve.erase(unique(ve.begin(),ve.end()),ve.end());
	for(int i=0;i<ve.size();i++){
		cout<<ve[i]<<"\n";
	}
	
	return 0;
}
