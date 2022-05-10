#include <iostream>

using namespace std;
int n;
int paper[130][130];
int answer[2];
void divide_paper(int x,int y, int sz){
	bool div = true;
	int num = paper[x][y];
	for(int i=x;i<x+sz;i++){
		for(int j=y;j<y+sz;j++){
			if(paper[i][j]!=num){
				div = false;
				break;
			}
		}
	}
	if(div==true){
		answer[num]++;
	}
	else{
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				divide_paper(x+(i*sz/2),y+(j*sz/2),sz/2);
			}
		}
	}
} 

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>paper[i][j];
		}
	}
	divide_paper(0,0,n);
	cout<<answer[0]<<"\n"<<answer[1]<<"\n";
	return 0;
}
