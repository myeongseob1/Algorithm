#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n,m;
char a[16];
char tmp[16];
bool check(string a){
	int num_vo = 0;
	int num = 0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
			num_vo++;
		}
		else{
			num ++;
		}
	}
	if(num>1&&num_vo>0) return true;
	else return false;
}
void go(int iter,string num){
	if(num.length() == n&&check(num)==true){
		for(int i=0;i<n;i++){
			cout<<num[i];
		}
		cout<<"\n";
		return;
	}
	if(iter>=m){
		return;
	}
	go(iter+1,num+a[iter]);
	go(iter+1,num);
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	sort(a,a+m);
	go(0,"");
	return 0;
}
