#include <iostream>

using namespace std;

int n;
string map[65];
string answer = "";

void quad_tree(int x,int y,int sz){
	char num = map[x][y];
	bool t = true;
	for(int i=x;i<x+sz;i++){
		for(int j=y;j<y+sz;j++){
			if(map[i][j]!=num){
				t = false;
				break;
			}
		}
		if(!t) break;

	}
	if(t){
		answer.push_back(num);
	}else{
		answer.push_back('(');
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				quad_tree(x+(i*sz/2),y+(j*sz/2),sz/2);
			}
		}
		answer.push_back(')');		
	}
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>map[i];
	}
	quad_tree(0,0,n);
	cout<<answer<<"\n";
	return 0;
}
