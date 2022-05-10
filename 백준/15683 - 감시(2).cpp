#include <iostream>
#include <vector>
using namespace std;
int n,m;
int map[9][9];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
vector<pair<int,int> > v;
int answer = 987654321;
void camera(int i,int j,int dir){
	int x = i;
	int y = j;
	while(1){
		int nx = x+dx[dir];
		int ny = y+dy[dir];
		
		if(nx<0||nx>n-1||ny<0||ny>m-1||map[nx][ny]==6){
			break;
		}
		if(map[nx][ny]==0){
			map[nx][ny] = 9;			
		}
		x = nx;
		y = ny; 
	}
}


void dfs(int num){
	if(num==v.size()){
		int result = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]==0) result++;
			}
		}
		answer = min(answer,result);
		return;
	}
	if(num>v.size()) return;
	int tmp_map[9][9];
	int ca = map[v[num].first][v[num].second];
	cout<<ca<<"\n";
	if(ca==1){
		for(int k=0;k<4;k++){
			copy(&map[0][0],&map[9][0],&tmp_map[0][0]);	
			camera(v[num].first,v[num].second,k);
			dfs(num+1);
			copy(&tmp_map[0][0],&tmp_map[9][0],&map[0][0]);	
		}
	}
	if(ca==2){
		for(int k=0;k<4;k++){
			copy(&map[0][0],&map[9][0],&tmp_map[0][0]);	
			camera(v[num].first,v[num].second,k);
			camera(v[num].first,v[num].second,(k+2)%4);
			dfs(num+1);
			copy(&tmp_map[0][0],&tmp_map[9][0],&map[0][0]);	
		}
			
	}
	if(ca==3){
		for(int k=0;k<4;k++){
			copy(&map[0][0],&map[9][0],&tmp_map[0][0]);	
			camera(v[num].first,v[num].second,k);
			camera(v[num].first,v[num].second,(k+1)%4);
			dfs(num+1);
			copy(&tmp_map[0][0],&tmp_map[9][0],&map[0][0]);	
		}			
	}
	if(ca==4){
		for(int k=0;k<4;k++){
			copy(&map[0][0],&map[9][0],&tmp_map[0][0]);	
			camera(v[num].first,v[num].second,k);
			camera(v[num].first,v[num].second,(k+1)%4);
			camera(v[num].first,v[num].second,(k+2)%4);
			dfs(num+1);
			copy(&tmp_map[0][0],&tmp_map[9][0],&map[0][0]);	
		}						
	}
	if(ca==5){
		copy(&map[0][0],&map[9][0],&tmp_map[0][0]);	
		camera(v[num].first,v[num].second,0);
		camera(v[num].first,v[num].second,1);
		camera(v[num].first,v[num].second,2);
		camera(v[num].first,v[num].second,3);
		dfs(num+1);
		copy(&tmp_map[0][0],&tmp_map[9][0],&map[0][0]);				
	}
	
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			if(map[i][j]>0&&map[i][j]<6){
				v.push_back(make_pair(i,j));
			}
		}
	}
	dfs(0);
	cout<<answer<<"\n";
	return 0;
}
