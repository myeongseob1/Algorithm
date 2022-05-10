#include <iostream>
#include <cmath>

int dx[4] = {0,1, -1,0};
int dy[4] = {1,0, 0,-1};
int n,q;
int map[65][65];
int fire_map[65][65];
int fire_map2[65][65];
int touch[65][65];
int answer[65][65];
using namespace std;
void init(){
	for(int i=0;i<65;i++){
		for(int j=0;j<65;j++){
			fire_map[i][j] = 0;
			touch[i][j] = 0;
			fire_map2[i][j] = 0;
		}
	}
}

void melting(int stage){
	for(int i=1;i<=pow(2,n);i++){
		for(int j=1;j<=pow(2,n);j++){
			for(int k=0;k<4;k++){
				int nx = i+dx[k];
				int ny = j+dy[k];
				if(nx>=1&&nx<=pow(2,n)&&ny>=1&&ny<=pow(2,n)){
					if(answer[nx][ny]!=0){
						touch[i][j]++;
					}
				}
			}
		}
	}
	for(int i=1;i<=pow(2,n);i++){
		for(int j=1;j<=pow(2,n);j++){
			if(touch[i][j]<3&&answer[i][j]>0){
				answer[i][j]--;
			}
		}
	}
	cout<<"\n";
	for(int i=1;i<=pow(2,n);i++){
		for(int j=1;j<=pow(2,n);j++){
			cout<<answer[i][j]<<" ";
			map[i][j] = answer[i][j];
		}
		cout<<"\n";
	}


}
int main(void){
	cin>>n>>q;
	for(int i=1;i<=pow(2,n);i++){
		for(int j=1;j<=pow(2,n);j++){
			cin>>map[i][j];
		}
	}

	for(int i=0;i<q;i++){
		int stage;
		cin>>stage;
		init();
		if(stage==n){
			melting(stage);
			init();
			continue;
		}
		for(int i=1;i<=pow(2,n);i++){
			for(int j=1;j<=pow(2,n);j++){
				answer[i][j] = 0;
			}
		}
		for(int i=1; i <= pow(2,stage); i++){
			for(int j=1;j<=pow(2,stage);j++){
				if(i>=1&&i<=pow(2,stage-1)&&j>=1&&j<=pow(2,stage-1)){
					fire_map[i][j] = 0;
				}
				else if(i>=1&&i<=pow(2,stage-1)&&j>=pow(2,stage-1)&&j<=pow(2,stage)){
					fire_map[i][j] = 1;
				}
				else if(i>=pow(2,stage-1)&&i<=pow(2,stage)&&j>=1&&j<=pow(2,stage-1)){
					fire_map[i][j] = 2;
					
				}
				else if(i>=pow(2,stage-1)&&i<=pow(2,stage)&&j>=pow(2,stage-1)&&j<=pow(2,stage)){
					fire_map[i][j] = 3;	
				}

			}
		}
		for(int i=1;i<=pow(2,n);i++){
			for(int j=1;j<=pow(2,n);j++){
				int p = i%(int)pow(2,stage);
				int q = j%(int)pow(2,stage);
				if(p==0){
					p = pow(2,stage);
				}
				if(q==0){
					q = pow(2,stage);
				}
				fire_map2[i][j] = fire_map[p][q];
			}
		}
		for(int i=1;i<=pow(2,n);i++){
			for(int j=1;j<=pow(2,n);j++){
				int x = i;
				int y = j;
				int nx = x + dx[fire_map2[x][y]]*stage;
				int ny = y + dy[fire_map2[x][y]]*stage;
				if(nx>=1&&nx<=pow(2,n)&&ny>=1&&ny<=pow(2,n)){
					answer[nx][ny] = map[x][y];
				} 
			}
		}
		melting(stage);
		
	}	
	int t =0;
	for(int i=1;i<=pow(2,n);i++){
		for(int j=1;j<=pow(2,n);j++){
			t += map[i][j];
		}
	}
	cout<<t<<"\n";
	return 0;
}
