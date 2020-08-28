#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int a[1001][1001];
int d[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int v_k[301];
int main(void){
	int iter;
	cin>>iter;
	for(int aaa=0;aaa<iter;aaa++){
		int n,m,k,answer = 0;
		queue<pair<int,int> > q;
		int time = 1;
		cin>>n>>m>>k;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
				d[i][j] = 0;
				if(a[i][j]==1) q.push(make_pair(i,j));
				if(a[i][j]!=0) v_k[a[i][j]]++;
			}
		}
		int p = 1;
		while(!q.empty()){
			if(time == v_k[p]){
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						if(a[i][j]==p+1){
							q.push(make_pair(i,j));	
						}
					}
				}
				p++;
			}
			if(p==k){
				break;
			}
			int x = q.front().first;
			int y = q.front().second;
			time++;
			q.pop();
			for(int k=0;k<4;k++){
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(nx>=0&&ny>=0&&nx<10000&&ny<10000){
					if(a[nx][ny]==0&&d[nx][ny]==0){
						d[nx][ny] = 1;
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
		for(int i=0;i<10000;i++){
			for(int j=0;j<10000;j++){
				if(d[i][j]==1) answer++;
			}
		}
		cout<<answer<<"\n";
	}
	return 0;
}
