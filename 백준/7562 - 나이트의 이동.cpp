#include <iostream>
#include <queue>

using namespace std;
int dx[8] = {2,2,1,1,-1,-1,-2,-2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};
int dist[301][301];
bool visit[301][301];
int test_case;

void init(){
	for(int i=0;i<301;i++){
		for(int j=0;j<301;j++){
			visit[i][j] = false;
			dist[i][j] = false;
		}
	}
}

int main(void){
	cin>>test_case;
	for(int i=0;i<test_case;i++){
		int n,s_x,s_y,e_x,e_y;
		cin>>n;
		cin>>s_x>>s_y;
		cin>>e_x>>e_y;
		init();
		queue<pair<int,int> > q;
		q.push(make_pair(s_x,s_y));
		visit[s_x][s_y] = true;
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int k=0;k<8;k++){
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(visit[nx][ny]==false){
					if(nx>=0&&nx<n&&ny>=0&&ny<n){
						dist[nx][ny] = dist[x][y] + 1;
						visit[nx][ny] = true;
						q.push(make_pair(nx,ny));
					}		
				} 
			}
		}
		cout<<dist[e_x][e_y]<<"\n";
	}
	
	return 0;
}
