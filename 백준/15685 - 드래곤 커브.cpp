#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int map[101][101];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y,d,g;
		cin>>y>>x>>d>>g;
		map[x][y] = 1;
		vector<int> dir;
		dir.push_back(d);
		for(int j=0;j<g;j++){
			vector<int> tmp;
			for(int k=dir.size()-1;k>=0;k--){
				tmp.push_back((dir[k]+1)%4);
			}
			for(int k=0;k<tmp.size();k++){
				dir.push_back(tmp[k]);
			}
			
		}
		for(int j=0;j<dir.size();j++){
			int nx = x + dx[dir[j]];
			int ny = y + dy[dir[j]];
			if(nx>=0&&nx<=100&&ny>=0&&ny<=100){
				map[nx][ny] = 1;
				x = nx;
				y = ny;
			}
		}
	}
	int answer = 0;
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(map[i][j]==1&&map[i+1][j]==1&&map[i][j+1]==1&&map[i+1][j+1]==1){
				answer++;
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}
