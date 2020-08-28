#include <iostream>
#include <algorithm>

using namespace std;
int n,m,k;
int a[52][52];
int p[7][3];
int per[7];
int dx[4] = {1,0,-1, 0};
int dy[4] = {0,1, 0,-1}; 
int answer = 10000;
int main(void){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<k;i++){
		cin>>p[i][0]>>p[i][1]>>p[i][2];
		per[i] = i;
	}
	
	do{
		int tmp[52][52];
		copy(&a[0][0],&a[51][51],&tmp[0][0]);
		for(int i=0;i<k;i++){
			int r = p[per[i]][0], c = p[per[i]][1], s = p[per[i]][2];
			while(1){
				int x = r-s;
				int y = c-s;
				int dir = 0;
				int fir = a[x][y];
				while(1){
				int nx = x+dx[dir];
				int ny = y+dy[dir];
				if(nx>=r-s&&nx<=r+s&&ny>=c-s&&ny<=c+s){
					a[x][y] = a[nx][ny];
					x = nx;
					y = ny;
					if(x==r-s&&y==c-s){
						a[x][y+1] = fir; 
						break;
					}
					continue;
				}
				dir = dir+1;
			}
			s--;
			if(s==0) break;						
			}
			
		}
		int min = 10000;
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=1;j<=m;j++){
				sum += a[i][j];
			}
			if(min>sum){
				min = sum;
			}
		}
		if(answer>min){
			answer = min;
		}
		copy(&tmp[0][0],&tmp[51][51],&a[0][0]);
	}while(next_permutation(per,per+k));
	cout<<answer<<"\n";
	
	return 0;
}
