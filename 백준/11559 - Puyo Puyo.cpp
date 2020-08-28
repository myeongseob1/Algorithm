#include <iostream>
#include <queue>

using namespace std;

char a[12][6];
int map[12][6];
int d[12][6];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int depth;
void init(){
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
			d[i][j] = 0;
		}
	}
}

void break_wall(){
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
			if(d[i][j]!=0){
				map[i][j] = 0;
			}
		}
	}

	for(int i=10;i>=0;i--){
		for(int j=0;j<6;j++){
			if(map[i][j]!=0){
				int t = i;				
				for(int k=i+1;k<12;k++){
					if(map[k][j]==0){
						swap(map[t][j],map[k][j]);
						t++;
					}
				}
			
			}
		}
	}

}
void dfs(int x,int y){
	for(int k=0;k<4;k++){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(nx>=0&&nx<12&&ny>=0&&ny<6){
			if(d[nx][ny]==0&&map[nx][ny]==map[x][y]&&map[nx][ny]!=0){
				depth++;
				d[nx][ny] = d[x][y]+1;
				dfs(nx,ny);
			}
		}
	}
}

int main(void){
	for(int i=0;i<12;i++){
		scanf("%s",&a[i]);
		for(int j=0;j<6;j++){
			switch(a[i][j]){
				case 'R':
					map[i][j] = 1;
					break;
				case 'G':
					map[i][j] = 2;
					break;
				case 'B':
					map[i][j] = 3;
					break;
				case 'P':
					map[i][j] = 4;
					break;
				case 'Y':
					map[i][j] = 5;
					break;
			}
		}
	}
	int answer = 0;
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
			if(d[i][j]==0&&map[i][j]!=0){
				dfs(i,j);
				if(depth>=4){
					break_wall();
					answer++;
				}
				depth = 0;
			}	
		}
	}

	cout<<answer<<"\n";
	return 0;
}
