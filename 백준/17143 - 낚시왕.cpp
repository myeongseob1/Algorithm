#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

struct shark{
	int x;
	int y;
	int size;
	int speed;
	int dir;
	int num;
	bool exis;
};

vector<shark> sh;
int r,c,m;
int dx[4] = {-1,1,0, 0};
int dy[4] = { 0,0,1,-1};
int shark[101][101];

int spin(int direction){
	if(direction==0){
		return 3;
	}
	else if(direction==1){
		return 2;
	}
	else if(direction==2){
		return 1;
	}
	else return 0;
}

int main(void){
	cin>>r>>c>>m;
	for(int i=0;i<m;i++){
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		sh.push_back({a,b,c,d%4,e,true});
	}
		
	return 0;
}
