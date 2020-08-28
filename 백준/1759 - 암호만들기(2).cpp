#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

bool check(string password){
	int vowel=0;
	for(int i=0;i<password.length();i++){
		if(password[i]=='a'||password[i]=='e'||password[i]=='o'||password[i]=='u'||password[i]=='i'){
			vowel++;	
		}
		
	}
	if(vowel>=1&&password.length()-vowel>=2){
		return true;
	}
	return false;
}


void go(int n,vector<char> &alpha,string password,int i){
	if(n==password.length()){
		if(check(password)){
			cout<<password<<'\n';
		}
		return;
	}
	if(i>=alpha.size()){
		return;
	}
	go(n,alpha,password+alpha[i],i+1);
	go(n,alpha,password,i+1);
}


int main(void){
	int L,C;
	cin>>L>>C;
	vector<char> alpha(C);
	string pw;
	for(int i=0;i<C;i++){
		cin>>alpha[i];
	}
	sort(alpha.begin(),alpha.end());
	go(L,alpha,pw,0);	
	return 0;
} 
