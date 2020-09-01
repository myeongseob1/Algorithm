#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n,l,r;
int a[51][51];
int d[51][51];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int answer;
bool check = false;

void init(){
	for(int i=0;i<51;i++){
		for(int j=0;j<51;j++){
			d[i][j] = 0;
		}
	}
	check = false;
}
int abs_minus(int a,int b){
	if(a>b) return a-b;
	else return b-a;
}
void bfs(int t,int s){
	vector<pair<int,int> > v;
	queue<pair<int,int> > q;
	q.push(make_pair(t,s));
	d[t][s] = 1;
	v.push_back(make_pair(t,s));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<n){
				if(abs_minus(a[x][y],a[nx][ny])>=l&&abs_minus(a[x][y],a[nx][ny])<=r&&d[nx][ny]==0){
					d[nx][ny] = d[x][y]+1;
					q.push(make_pair(nx,ny));
					v.push_back(make_pair(nx,ny));
				}
				
			}
		}
		
	}
	if(v.size()>1){
		int sum = 0;
		for(int i=0;i<v.size();i++){
			sum += a[v[i].first][v[i].second];
		}
		for(int i=0;i<v.size();i++){
			a[v[i].first][v[i].second] = sum/v.size();
		}
		check = true;
	}
}

int main(void){
	cin>>n>>l>>r;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	while(1){
		init();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(d[i][j]==0) bfs(i,j);
			}
		}
		answer++;
		if(check==false){
			break;
		}
	}
	cout<<answer-1<<"\n";
	return 0;
} 
