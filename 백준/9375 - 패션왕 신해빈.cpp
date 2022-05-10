#include <iostream>
#include <map>

using namespace std;
int n,m;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		map<string,int> mp;
		int answer = 1;
		for(int j=0;j<m;j++){
			string a,b;
			cin>>a>>b;
			mp[b]++;
		}
		map<string,int>::iterator it;
		for(it = mp.begin();it!=mp.end();it++){
			answer *= (it->second+1);
		}

		cout<<answer-1<<"\n";		
	}
	return 0;
}

