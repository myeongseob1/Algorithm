#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[21][21];
int n;
int dx[4] = { 0,1,0,-1};
int dy[4] = {-1,0,1, 0};//0<-¿Þ 1¾Æ·¡ 2->¿À 3À§ 
int origin_map[21][21];

void push(int dir){
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]!=0) v.push_back(make_pair(i,j));
		}
	}
	if(dir==2||dir==1){
		reverse(v.begin(),v.end());
	}
	for(int i=0;i<v.size();i++){
		int x = v[i].first;
		int y = v[i].second;
		while(1){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(nx<0||nx>=n||ny<0||ny>=n) break;
			if(map[nx][ny]==0){
				map[nx][ny] = map[x][y];
				map[x][y] = 0;
				x = nx;
				y = ny;
				
			}
			else{
				break;
			}	
		}		
		
	}	
}

void merge(int dir){
	if(dir==0){
		for(int i=0;i<n;i++){
			for(int j=0;j<n-1;j++){
				int x = i;
				int y = j;
				if(map[x][y]==map[x][y+1]){
					map[x][y] *= 2;
					map[x][y+1] = 0;
				}
			}
		}
	}
	else if(dir==1){
		for(int i=n-1;i>=1;i--){
			for(int j=0;j<n;j++){
				int x = i;
				int y = j;

				if(map[x][y]==map[x-1][y]){
					map[x][y] *= 2;
					map[x-1][y] = 0;
				}
			}
		}
		
	}
	else if(dir==2){
		for(int i=0;i<n;i++){
			for(int j=n-1;j>=1;j--){
				int x = i;
				int y = j;

				if(map[x][y]==map[x][y-1]){
					map[x][y] *= 2;
					map[x][y-1] = 0;
				}
			}
		}		
	}
	else if(dir==3){
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n;j++){
				int x = i;
				int y = j;
				if(map[x][y]==map[x+1][y]){
					map[x][y] *= 2;
					map[x+1][y] = 0;
				}
			}
		}
		
	}
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			origin_map[i][j] = map[i][j];
		}
	}
	int answer = 0;
	for(int a=0;a<4;a++){
		for(int b=0;b<4;b++){
			for(int c=0;c<4;c++){
				for(int d=0;d<4;d++){
					for(int e=0;e<4;e++){
						push(a);
						merge(a);
						push(a);
						push(b);
						merge(b);
						push(b);
						push(c);
						merge(c);
						push(c);
						push(d);
						merge(d);
						push(d);
						push(e);
						merge(e);
						push(e);
						for(int i=0;i<n;i++){
							for(int j=0;j<n;j++){
								answer = max(answer,map[i][j]);
							}								
						}
						for(int i=0;i<21;i++){
							for(int j=0;j<21;j++){		
								map[i][j] = origin_map[i][j];
							}
						}
					}
				}
			}
		}
	}
	cout<<answer<<"\n";

	return 0;
}
