#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<bits/stdc++.h>
using namespace std;

map<string, int> mp1; //���ڿ� �Է� �� ���ڸ� ����ϴ� �� 
map<int, string> mp2; //���ڸ� �Է½� ���ڿ��� ����ϴ� ��int n,m;
int n,m;

int main(void){
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string nm;
		cin>>nm;
		mp1[nm] = i+1;
		mp2[i+1] = nm;
	}
	for(int i=0;i<m;i++){
		char qu[21];
		cin>>qu;
		if(qu[0]=='0'||qu[0]=='1'||qu[0]=='2'||qu[0]=='3'||qu[0]=='4'||qu[0]=='5'||qu[0]=='6'||qu[0]=='7'||qu[0]=='8'||qu[0]=='9'){
			cout<<mp2[atoi(qu)]<<"\n";
		}
		else{
			cout<<mp1[qu]<<"\n";
		}
	}
	return 0;
}
