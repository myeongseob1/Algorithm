#include <iostream>
#include <vector>
using namespace std;

int a[21][21];
int axis[1001];
int dice[6];
int n,m,x,y,k;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
vector<int> ans;

int main(void){
	cin>>n>>m>>x>>y>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<k;i++){
		cin>>axis[i];
		axis[i] %= 4; 
	}
	for(int i=0;i<k;i++){
		int nx = x+dx[axis[i]];
		int ny = y+dy[axis[i]];
		if(nx>=0&&nx<n&&ny>=0&&ny<m){
			if(axis[i]==0){
				int tmp = dice[5];
				dice[5] = dice[4];
				dice[4] = dice[0];
				dice[0] = dice[1];
				dice[1] = tmp;
				if(a[nx][ny]==0){
					a[nx][ny] = dice[5];
				}
				else{
					dice[5] = a[nx][ny];
					a[nx][ny] = 0;								
				}
			}
			if(axis[i]==1){
				int tmp = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = tmp;
				if(a[nx][ny]==0){
					a[nx][ny] = dice[5];
				}
				else{
					dice[5] = a[nx][ny];
					a[nx][ny] = 0;								
				}				
			}
			if(axis[i]==2){
				int tmp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = tmp;
				if(a[nx][ny]==0){
					a[nx][ny] = dice[5];
				}
				else{
					dice[5] = a[nx][ny];
					a[nx][ny] = 0;
				}		
			}
			if(axis[i]==3){
				int tmp = dice[1];
				dice[1] = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = tmp;
				if(a[nx][ny]==0){
					a[nx][ny] = dice[5];
				}
				else{
					dice[5] = a[nx][ny];
					a[nx][ny] = 0;
				}
			}		
			ans.push_back(dice[0]);
			x = nx; y = ny;
		}
	}	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<"\n";
	}
	
	return 0;
}
