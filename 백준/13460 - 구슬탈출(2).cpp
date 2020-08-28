#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n,m;
int a[11][11];
int depth;
int answer=200000;
struct ball{
	int depth;
	int rx,ry,bx,by;
};

int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
int r_x,r_y,b_x,b_y,h_x,h_y;
int visit[11][11][11][11];
bool r_arrive = false, b_arrive = false;
int main(void){
	char tmp[11][11];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%s",&tmp[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			switch(tmp[i][j]){
				case '.':
					a[i][j] = 0;
					break;
				
				case '#':
					a[i][j] = 1;	
					break;
				
				case 'R':
					a[i][j] = 0;
					r_x = i;
					r_y = j;
					break;
					
				case 'O':
					h_x = i;
					h_y = j;
					a[i][j] = 2;
					break;
				
				case 'B':
					a[i][j]= 0;
					b_x = i;
					b_y = j;
					break;
			}
			
		}
	}
	queue<ball> q;
	q.push({0,r_x,r_y,b_x,b_y});
	visit[r_x][r_y][b_x][b_y] = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	while(!q.empty()){
		int sr_x = q.front().rx;
		int sr_y = q.front().ry;
		int sb_x = q.front().bx;
		int sb_y = q.front().by;
		int ur_x = q.front().rx;
		int ur_y = q.front().ry;
		int ub_x = q.front().bx;
		int ub_y = q.front().by;
		int n_depth = q.front().depth+1;
//		if(q.front().depth>10){
//			break;
//		}

		q.pop();
		for(int k=0;k<4;k++){
			int nr_x,nr_y,nb_x,nb_y;
			while(1){
				nr_x = ur_x + dx[k];
				nr_y = ur_y + dy[k];

				if(a[nr_x][nr_y] == 1){
					ur_x = nr_x-dx[k];
					ur_y = nr_y-dy[k];
					break;
				}
				if(a[nr_x][nr_y] == 2){
					ur_x = nr_x;
					ur_y = nr_y;
					r_arrive = true;
					break;
				}
					ur_x = nr_x;
					ur_y = nr_y;	

			}
			while(1){
				nb_x = ub_x + dx[k];
				nb_y = ub_y + dy[k];
				if(a[nb_x][nb_y]==1){
					ub_x = nb_x-dx[k];
					ub_y = nb_y-dy[k];
					break;				
				}
				if(a[nb_x][nb_y]==2){
					ub_x = nb_x;
					ub_x = nb_y;
					b_arrive = true;
					break; 
				}
				ub_x = nb_x;
				ub_y = nb_y;
			}
			cout<<ur_x<<" "<<ur_y<<" "<<ub_x<<" "<<ub_y<<" "<<n_depth<<"\n";
			cout<<nr_x<<" "<<nr_y<<" "<<nb_x<<" "<<nb_y<<" "<<n_depth<<"\n";
			cout<<"\n";
			if(ub_x==ur_x&&ub_y==ur_y){
				if(abs(ub_x-sb_x)+abs(ub_y-sb_y)>abs(ur_x-sr_x)+abs(ur_y-sr_y)){
					ub_x -= dx[k];
					ub_y -= dy[k];
				}
				else{
					ur_x -= dx[k];
					ur_y -= dy[k];
				}	
			}

			if(ur_x==h_x&&ur_y==h_y&&answer>n_depth){
				answer = n_depth;
			}
			if(ur_x>0&&ur_x<n&&ur_y>0&&ur_y<m&&ub_x>0&&ub_x<n&&ub_y>0&&ub_y<m){
				if(visit[ur_x][ur_y][ub_x][ub_y]==0){
					visit[ur_x][ur_y][ub_x][ub_y]= 1;
					q.push({n_depth,ur_x,ur_y,ub_x,ub_y});		
				}
			}
		}		
	}
	cout<<answer<<"\n";
	return 0;
}
