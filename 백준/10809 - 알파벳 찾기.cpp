#include <iostream>

using namespace std;
string a;
int visit[101];
int main(void){
	cin>>a;
	for(int i=0;i<26;i++){
		visit[i] = -1;
	}
	for(int i=0;i<a.size();i++){
		if(visit[a[i]-'a'] == -1)visit[a[i]-'a'] = i;
	}
	for(int i=0;i<26;i++){
		cout<<visit[i]<<" ";
	}
	cout<<"\n";
	
	return 0;
}
