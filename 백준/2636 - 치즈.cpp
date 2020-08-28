#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n,m;
int a[101][101],d[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void init(){
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			d[i][j] = 0;
		}
	}
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	int time =0;
	int cpy[101][101];
	while(1){
		init();
		copy(&a[0][0],&a[100][100],&cpy[0][0]);

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]==1){
					for(int k=0;k<4;k++){
						int nx = i+dx[k];
						int ny = j+dy[k];
						if(nx>=0&&nx<n&&ny>=0&&ny<m){
							if(a[nx][ny]==0){
								d[i][j] = 2;
							}
						}
					}
				}
			}
		}
		cout<<"\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<d[i][j]<<" ";
				if(d[i][j]==2){
					a[i][j] = 0;
				}
			}
			cout<<"\n";
		}
		cout<<"\n";
		int cnt = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]==1){
					cnt++;
				}
			}
		}
		time++;
		if(cnt==0){
			break;
		}
	}
	int t=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<cpy[i][j]<<" ";
			if(cpy[i][j]==1){
				t++;
			}
		}
		cout<<"\n";
	}
	
	cout<<time<<"\n";
	cout<<t;
	
	return 0;
}
