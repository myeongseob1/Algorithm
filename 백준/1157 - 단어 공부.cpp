#include <iostream>

using namespace std;
string a;
int visit[26];
int main(void){
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='a'&&a[i]<='z'){
			visit[a[i]-'a']++;
		}
		else if(a[i]>='A'&&a[i]<='Z'){
			visit[a[i]-'A']++;
		}
	}
	int answer = 0;
	int res;
	for(int i=0;i<26;i++){
		if(visit[i]>answer){
			res = i;
		}
		answer = max(answer,visit[i]);
	}
	int count = 0;
	for(int i=0;i<26;i++){
		if(answer==visit[i]){
			count++;
		}
	}
	if(count > 1){
		cout<<'?'<<"\n";
	}
	else{
		cout<<(char)(res+'A')<<"\n";
	}
	return 0;
}
