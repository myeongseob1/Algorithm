#include <iostream>

using namespace std;
int n,m;
string s;
int answer;
int main(void){
	cin>>n>>m>>s;
	for(int i=1;i<m-1;i++){
		int cnt = 0;
		if(s[i-1]=='I'){
			while(1){
				if(s[i]=='O'&&s[i+1]=='I'){
					i = i+2;
					cnt++;
				}else{
					break;
				}
				if(cnt==n){
					answer++;
					cnt--;
				}		
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}
