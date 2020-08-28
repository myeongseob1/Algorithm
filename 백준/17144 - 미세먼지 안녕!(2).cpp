#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int a[51][51];
int r,c,t;
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int answer;
void diffuse(){
	queue<pair<int, int> > q;
	int tmp[51][51];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			tmp[i][j] = 0;
			if(a[i][j]>4){
				q.push(make_pair(i,j));
			}
		}
	}
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop(); 
		int give = a[x][y]/5;
		int dir = 0;
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0&&nx<r&&ny>=0&&ny<c){
				if(a[nx][ny]!=-1){
					tmp[nx][ny] += give;		
					dir++;
				}
			}
		}
		a[x][y] -= give * dir;
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			a[i][j] += tmp[i][j]; 
		}
	}

}
void circulate(int t){ // t는 공기청정기가 있는 행중 위를 의미 
	int x = t;
	int y = 0;
	int k = 0;
	int tmp[51][51];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			tmp[i][j] = a[i][j]; 
		}
	}
	while(1){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(!(nx>=0&&nx<r&&ny>=0&&ny<c)){
			k++;
			continue;
		}
		if(nx == t&&ny==0) break;
		a[nx][ny] = tmp[x][y]; 	
		x = nx;
		y = ny;
	}
	k= 4;
	x=t+1;
	y=0;
	while(1){
		int nx = x+dx[k%4];
		int ny = y+dy[k%4];
		if(!(nx>=0&&nx<r&&ny>=0&&ny<c)){
			k--;
			continue;
		}
		if(nx == t+1&&ny==0) break;
		a[nx][ny] = tmp[x][y]; 	
		x = nx;
		y = ny;
	}
	a[t][1] = 0;
	a[t+1][1] = 0;
}

void solve(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			answer += a[i][j];
		}
	}
	answer += 2;
}

int main(void){
	cin>>r>>c>>t;
	int air;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<r;i++){
		if(a[i][0]==-1){
			air = i;
			break;
		}
	}
	for(int i=0;i<t;i++){
		diffuse();
		circulate(air);
	}
	solve();
	
	cout<<answer<<"\n";
	return 0;
}
