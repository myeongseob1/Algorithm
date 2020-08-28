#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n,m,d;
int a[18][18];
vector<pair<int,int> > ve;

struct enemy{
	int x;
	int y;
	int dist;
};
int kill,answer = 0;
int r[18][18];

void init(){
	for(int i=0;i<=17;i++){
		for(int j=0;j<=17;j++){
			r[i][j] = 0;
		}
	}
}

bool compare(enemy a,enemy b){
	if(a.dist>b.dist){
		return false;
	}
	else if(a.dist==b.dist){
		if(a.y>=b.y){
			return false;
		}
		else true;
	}
	else{
		return true;
	}
}

void dfs(int iter,int t){
	if(t==3){
		int b[18][18];
		copy(&a[0][0],&a[17][17],&b[0][0]);		
		while(1){
			int juk =0;
			for(int x=0;x<n;x++){
				for(int y=0;y<m;y++){
					if(a[x][y]==1){
						juk++;
					}
				}
			}
		if(juk==0){
			break;
		}

		int aa[18][18];
		copy(&a[0][0],&a[17][17],&aa[0][0]);
		for(int i=0;i<ve.size();i++){
			queue<pair<int,int> > q;
			init();
			q.push(ve[i]);
			while(!q.empty()){
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for(int k=0;k<4;k++){
					int nx = x+dx[k];
					int ny = y+dy[k];
					if(nx>=0&&nx<n&&ny>=0&&ny<m){
						if(r[nx][ny] == 0){
							q.push(make_pair(nx,ny));
							r[nx][ny] = r[x][y] + 1;
						}
					}
				}
			}
		vector<enemy> tmp;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(r[i][j]<=d&&(aa[i][j]==1||aa[i][j]==2)){
					enemy en;
					en.x = i;
					en.y = j;
					en.dist = r[i][j];
					tmp.push_back(en);
				}

			}
		}
		if(tmp.size()==0) continue;
			if(tmp.size()>1){
				sort(tmp.begin(),tmp.end(),compare);
			}
			if(aa[tmp[0].x][tmp[0].y]==2){
				continue;
			}
			if(aa[tmp[0].x][tmp[0].y]==1){
				kill++;
				aa[tmp[0].x][tmp[0].y] = 2;	
			}

		}
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(x==0){
					a[x][y] = 0;
					continue;
				}
				else{
					if(aa[x-1][y]==2){
						a[x][y] = 0;
					}
					else a[x][y] = aa[x-1][y];
				}
			}
		}
		if(kill>=answer){
			answer = kill;
		}
		
	}
	kill = 0;
	copy(&b[0][0],&b[16][16],&a[0][0]);		
		return;
	}
	if(iter>=m){
		return;
	}
	ve.push_back(make_pair(n,iter));
	dfs(iter+1,t+1);
	ve.pop_back();
	dfs(iter+1,t);	
}

int main(void){
	cin>>n>>m>>d;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}

	dfs(0,0);
	cout<<answer<<"\n";
	return 0;
}
