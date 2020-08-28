#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int time;
bool last = true;
int t,m;
int a[51][51];
int d[51][51];
vector<pair<int,int> > real_virus;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool use[11];
int num_wall=0;
int chosen_virus[11];
int mat=2147483647;
void init(){
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			d[i][j] = 0;
			if(a[i][j]==1){
				d[i][j] = -1;
			}
			if(a[i][j]==2){
				d[i][j] = -2;
			}
		}
	}
	last = true;
}

void choice_virus(int iter,int selected,int n,int m){
	if(selected==n){
		init();
		int answer =0;
		queue<pair<int,int> > q;
		for(int i=0;i<selected;i++){
			q.push(real_virus[chosen_virus[i]-1]);
			d[real_virus[chosen_virus[i]-1].first][real_virus[chosen_virus[i]-1].second]= 1;
		}	
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int k=0;k<4;k++){
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(nx>=0&&nx<t&&ny>=0&&ny<t){
					if(d[nx][ny]==0&&a[nx][ny]!=1){
						d[nx][ny] = d[x][y] +1;
						q.push(make_pair(nx,ny));
						time = d[nx][ny];
					}
					if(d[nx][ny]==-2&&a[nx][ny]!=1){
						d[nx][ny] = d[x][y]+1;
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
		
		for(int i=0;i<t;i++){
			for(int j=0;j<t;j++){
				if(answer<d[i][j]&&a[i][j]==0){
					answer = d[i][j];
				}
				if(d[i][j]==time&&a[i][j]!=2) last = false;		
			}
		}
		for(int i=0;i<t;i++){
			for(int j=0;j<t;j++){
				if(d[i][j]==0){
					answer = -1;
				}		
			}
		}
		if(mat>answer&&answer != -1){
			if(last == true){
				mat = answer-1;
			}
			else{
				mat = answer;
			}
		}
		return;
	}
	if(iter>=m) return;
	chosen_virus[selected] = iter+1;
	choice_virus(iter+1,selected+1,n,m);
	choice_virus(iter+1,selected,n,m);
}

int main(void){
	cin>>t>>m;
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			cin>>a[i][j];
			if(a[i][j]==2){
				real_virus.push_back(make_pair(i,j));
			}
			if(a[i][j]==1){
				num_wall++;
			} 
		}
	}
	
	int p = real_virus.size();
	choice_virus(0,0,m,p);
	if(num_wall== t*t||num_wall+p==t*t){
		cout<<0<<"\n";
	}
	else if(mat!=2147483647){
		cout<<mat-1<<"\n";		
	}
	else cout<<-1<<"\n";
	return 0;
}
