#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int n,m,kk;
int a[12][12];
int d[12][12];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
deque<int> tree[12][12];
int main(void){
	cin>>n>>m>>kk;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
			a[i][j] = 5;
		}
	}
	for(int i=0;i<m;i++){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		tree[aa][bb].push_back(cc);
	}
	for(int aaa=0;aaa<kk;aaa++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(tree[i][j].size()!=0){
					int save;
					bool die = false;
					for(int k=0;k<tree[i][j].size();k++){
						if(a[i][j]-tree[i][j][k]>=0){
							a[i][j] -= tree[i][j][k];
							tree[i][j][k]++;
						}
						else{
							die = true;
							save = k;
							break;
						}
					}
					if(die==true){
						for(int k=save;k<tree[i][j].size();k++){
							a[i][j] += tree[i][j][k]/2;
						}
						int p = tree[i][j].size() - save;
						for(int k=0;k<p;k++){
							tree[i][j].pop_back();
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(tree[i][j].size()!=0){
					for(int k=0;k<tree[i][j].size();k++){
						if(tree[i][j][k]%5==0){
							for(int t=0;t<8;t++){
								int nx = i+dx[t];
								int ny = j+dy[t];
								if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
									tree[nx][ny].push_front(1);
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j] += d[i][j];
			}
		}
			
	}
	int answer = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			answer+=tree[i][j].size();
		}
	}
	cout<<answer<<"\n";
	return 0;
}
