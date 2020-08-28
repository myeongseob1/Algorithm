#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct fish{
	int x;
	int y;
	int num;
	int direction;
	bool eat; 
};

struct shark{
	int x;
	int y;
	int num;
	int direction;
};

vector<fish> p[4];
int dx[8] = {-1,-1,-1, 0, 1,1,1,0};//1시 방향부터 반시계방향 45도씩 
int dy[8] = {1,  0,-1,-1,-1,0,1,1}; 

shark sh;
vector<fish> v;

bool compare(fish t,fish s){
	if(t.num>s.num){
		return false;
	}
	return true;
}

void move_fish(int x,int y,int c){
	for(int i=c;i<v.size();i++){
		int nx = v[i].x +dx[v[i].direction];
		int ny = v[i].y +dy[v[i].direction];
		while(1){
			if((nx == x&&ny==y)||(nx<0||nx>3||ny<0||ny>3)){
				v[i].direction = (v[i].direction+1)%8;
				nx = v[i].x+dx[v[i].direction];
				ny = v[i].y+dy[v[i].direction];
			}
			else{
				break;
			}			
		}
		for(int j=c;j<v.size();j++){
			if(p[nx][ny].num==v[j].num){
				swap(p[v[i].x][v[i].y],p[nx][ny]);
				swap(v[i].x,v[j].x);
				swap(v[i].y,v[j].y); 
				break;
			}
		}
	}
}


void dfs(){
	
	
}

int main(void){
	int a,b;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cin>>a>>b;
			fish tmp;
			tmp.x = i;
			tmp.y = j;
			tmp.num = a;
			tmp.direction = b%8;
			tmp.eat = false;
			v.push_back(tmp);
			p[i].push_back(tmp);
		}
	}
	v[0].eat = true;
	v[0].num = 0;
	sh.x = 0;
	sh.y = 0;
	p[0][0].num = 0;
	sh.direction = v[0].direction;	
	sort(v.begin()+1,v.end(),compare);
	move_fish(sh.x,sh.y,1);
	
	cout<<sh.direction<<"\n";	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<p[i][j].num<<" ";
		}
		cout<<"\n";
	}	
	
	return 0;
}
