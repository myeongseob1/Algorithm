#include <iostream>

using namespace std;
string a;
bool visit[105];
int answer;
int main(void){
	cin>>a;
	if(a.size()<=1){
		cout<<1<<"\n";
		return 0;
	}
	for(int i=0;i<a.size()-2;i++){
		if(a[i]=='d'&&a[i+1]=='z'&&a[i+2]=='='){
			visit[i] = true;
			visit[i+1] = true;
			visit[i+2] = true;
			answer++;
		}
	}

	for(int i=0;i<a.size()-1;i++){
		if(visit[i]==true||visit[i+1]==true) continue; 
		if(a[i]=='c'&&a[i+1]=='='){
			visit[i] = true;
			visit[i+1] = true;
			answer++;
		}
		else if(a[i]=='c'&&a[i+1]=='-'){
			visit[i] = true;
			visit[i+1] = true;
			answer++;			
		}
		else if(a[i]=='d'&&a[i+1]=='-'){
			visit[i] = true;
			visit[i+1] = true;
			answer++;			
		}
		else if(a[i]=='l'&&a[i+1]=='j'){
			visit[i] = true;
			visit[i+1] = true;
			answer++;			
		}
		else if(a[i]=='n'&&a[i+1]=='j'){
			visit[i] = true;
			visit[i+1] = true;
			answer++;			
		}
		else if(a[i]=='s'&&a[i+1]=='='){
			visit[i] = true;
			visit[i+1] = true;
			answer++;			
		}
		else if(a[i]=='z'&&a[i+1]=='='){
			visit[i] = true;
			visit[i+1] = true;
			answer++;			
		}

	}
	for(int i=0;i<a.size();i++){
		if(visit[i]==false){
			answer++;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
