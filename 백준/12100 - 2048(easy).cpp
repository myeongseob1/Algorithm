#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[21][21];
int n;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};//상하좌우 순서 

int permu[5];
int max_ans;
int copy_map[21][21];



void push(int direction){
	vector<pair<int,int> > p;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]!=0){
				p.push_back(make_pair(i,j));
			}
		}
	}
	if(direction ==1 || direction ==3){
		reverse(p.begin(),p.end());
	}
	for(int i=0;i<p.size();i++){
		int x = p[i].first;
		int y = p[i].second;
		while(1){
			int nx = x+dx[direction];
			int ny = y+dy[direction];
			if(nx<0||nx>n-1||ny<0||ny>n-1){
				break;
			}
			if(a[nx][ny]==0){
				a[nx][ny] = a[x][y];
				a[x][y] = 0;
			}
			x = nx;
			y = ny;
		}		 
	}	
}
void move(int direction){
	push(direction);	
	switch(direction){
		case 0:
			for(int i=0;i<n-1;i++){
				for(int j=0;j<n;j++){
					if(a[i][j]==a[i+1][j]){
						a[i][j]*=2;
						a[i+1][j] = 0;
					}
				}
			}
			break;
		case 1:
			for(int i=n-1;i>0;i--){
				for(int j=0;j<n;j++){
					if(a[i][j]==a[i-1][j]){
						a[i][j]*=2;
						a[i-1][j] = 0;
					}
				}
			}
			break;
		case 2:
			for(int i=0;i<n;i++){
				for(int j=0;j<n-1;j++){
					if(a[i][j]==a[i][j+1]){
						a[i][j]*=2;
						a[i][j+1] = 0;
					}
				}
			}
		break;
		
		case 3:
			for(int i=0;i<n;i++){
				for(int j=n-1;j>0;j--){
					if(a[i][j]==a[i][j-1]){
						a[i][j]*=2;
						a[i][j-1] = 0;
					}
				}
			}
		break;
	}
	push(direction);
}

void up(int iter,int p){
	if(iter == p){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				copy_map[i][j] = a[i][j];
			}
		}
		for(int i=0;i<iter;i++){
			move(permu[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]>max_ans){
					max_ans = a[i][j];
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				a[i][j] = copy_map[i][j];
			}
		}
		return;
	}
	for(int i=0;i<p-1;i++){
		permu[iter] = i;
		up(iter+1,p);
	}
}



int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	up(0,5);
	cout<<max_ans<<"\n";
	return 0;
}
