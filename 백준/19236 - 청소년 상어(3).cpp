#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[8] = {-1,-1,-1, 0, 1,1,1,0};//1시 방향부터 반시계방향 45도씩 
int dy[8] = {1,  0,-1,-1,-1,0,1,1}; 

struct fish{
	int x;
	int y;
	int num;
	int direction;
	int sum;
	bool eat; 
};


vector<fish> v;
fish sh;
int fish_num[5][5];

bool compare(fish t,fish s){
	if(t.num>s.num){
		return false;
	}
	return true;
}

int main(void){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			int a,b;
			cin>>a>>b;
			if(i==0&&j==0){
				sh.x = i;
				sh.y = j;
				sh.direction = b%8;
				sh.sum = a;
				fish_num[i][j] = 30;
			}
			else{
				fish_num[i][j] = a;	
				v.push_back({i,j,a,b%8,false});			
			}
		}
	}
	while(1){
		int eat = 0;
		for(int ii=1;ii<=3;ii++){
			int sh_nx = sh.x + dx[sh.direction]*ii;
			int sh_ny = sh.y + dy[sh.direction]*ii;
			if(sh_nx>=4||sh_nx<0||sh_ny>=4||sh_ny<0) continue;
			if(a[sh_nx][sh_ny]==30) continue;
			sh.x = sh_nx; sh.y = sh_ny;
			eat++;
		}
		if(eat==0){
			break;
		}

	}
	sort(v.begin(),v.end(),compare);
	for(int i=0;i<v.size();i++){
		while(1){
			int nx = v[i].x + dx[v[i].direction];
			int ny = v[i].y + dy[v[i].direction];
			if(nx>=0&&nx<4&&ny>=0&&ny<4){
				if(nx!=sh.x||ny!=sh.y){
					for(int t=0;t<v.size();t++){
						if(v[t].num==fish_num[nx][ny]){
							 v[t].x = v[i].x;
							 v[t].y = v[i].y;
							 break;
						}
					}
					swap(fish_num[nx][ny],fish_num[v[i].x][v[i].y]);
					v[i].x = nx; v[i].y = ny;
					break;
				}
			}
			v[i].direction = (v[i].direction+1)%8;			
		}
	}
	return 0;
}
