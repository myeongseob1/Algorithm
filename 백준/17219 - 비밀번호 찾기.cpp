#include <iostream>
#include <map>

using namespace std;

map<string,string> mp;
int n,m;
int main(void){
	cin.tie(NULL);
	cout.tie(NULL) ;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		mp[a] = b;
	}
	for(int j=0;j<m;j++){
		string a;
		cin>>a;
		cout<<mp[a]<<"\n";
	}
	return 0;
}
