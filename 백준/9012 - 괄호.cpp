#include <iostream>
#include <vector>

using namespace std;

int n;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		string a;
		cin>>a;
		string answer = "YES";
		vector<int> ve;
		for(int j=0;j<a.size();j++){
			if(a[j]=='('){
				ve.push_back(1);
			}
			else if(a[j]==')'){
				if(!ve.empty()) ve.pop_back();
				else answer = "NO";
			}
		}
		if(!ve.empty()){
			answer = "NO";
		}
		cout<<answer<<"\n"; 
	}
	
	return 0;
}
