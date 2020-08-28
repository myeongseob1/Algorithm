#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;
int n,p,q;//p는 최소 q는 최대 
int a[51][51];
int d[51][51];
bool visit[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int minus_abs(int x,int y){
	if(x>y){
		return x-y;
	}
	else return y-x;	
}

void dfs(int x,int y,int c){
	visit[x][y] = true;
	for(int i=0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<n){
			if(visit[nx][ny]==false&&d[nx][ny]==0&&minus_abs(a[x][y],a[nx][ny])>=p&&minus_abs(a[x][y],a[nx][ny])<=q){
				visit[nx][ny] = true;
				d[nx][ny] = c;
				dfs(nx,ny,c);
			}
		}
	}
}
 

int main(void){
	int answer=0;
	int c = 0;
	vector<pair<int,int> > t;
	vector<int> option;
	cin>>n>>p>>q;
	for(int i=0;i<n;i++){		
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dfs(i,j,c++);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(d[i][j]!=0){
				t.push_back(make_pair(i,j));
				option.push_back(d[i][j]);		
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<d[i][j];
		}
		cout<<"\n";
	}
	
	for(int i=0;i<t.size();i++){
		cout<<t[i].first<<" "<<t[i].second<<" "<<option[i]<<"\n";
	}
	
	
	cout<<answer<<"\n";
	return 0;
}
