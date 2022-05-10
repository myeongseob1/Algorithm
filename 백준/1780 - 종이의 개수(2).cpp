#include <iostream>

using namespace std;

int map[3000][3000];
int n;
int answer[3];

void divide_paper(int x,int y,int sz){
	int num = map[x][y];
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
		answer[num]++;	
	}
	else{
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				divide_paper(x+(i*sz/3),y+(j*sz/3),sz/3);
			}
		}
	}
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			map[i][j]++;
		}
	}
	divide_paper(0,0,n);
	cout<<answer[0]<<"\n"<<answer[1]<<"\n"<<answer[2]<<"\n";
	return 0;
}
