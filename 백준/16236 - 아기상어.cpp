#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int n;
int a[21][21];
struct shark{
	int x;
	int y;
	int size;
	int fish;
};

struct eat{
	int x;
	int y;
	int distance;
};

shark sh;
int d[21][21];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int answer;
void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			d[i][j] = 0;
		}
	}
}

bool compare(eat a,eat b){
	if(a.distance>b.distance){
		return false;
	}
	else if(a.distance==b.distance){
		if(a.x>b.x){
			return false;
		}
		else if(a.x==b.x){
			if(a.y>b.y){
				return false;
			}
			else if(a.y<b.y){
				return true;
			}
			else{
				return true;
			}
		}
		else{
			return true;
		}
	} 
	else{
		return true;
	}
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			if(a[i][j]==9){
				sh.x = i;
				sh.y = j;
				a[i][j] = -1;
			}
		}
	}
	sh.size = 2;
	sh.fish = 0;
	
	while(1){
		vector<pair<int,int> > fish;
		vector<eat> this_fish;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]<sh.size&&a[i][j]!=0&&a[i][j]!=-1){
					fish.push_back(make_pair(i,j));
				}
			}
		}
		if(fish.empty()==true){
			break;
		}
		for(int i=0;i<fish.size();i++){
			init();
			queue<pair<int,int> > q;
			q.push(fish[i]);
			while(!q.empty()){
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for(int k=0;k<4;k++){
					int nx = x+dx[k];
					int ny = y+dy[k];
					if(nx>=0&&nx<n&&ny>=0&&ny<n){
						if(d[nx][ny]==0&&a[nx][ny]<=sh.size){
							d[nx][ny] = d[x][y] +1;
							q.push(make_pair(nx,ny));
						}
					}
				}
			}
			if(d[sh.x][sh.y]!=0){
				eat tmp;
				tmp.x = fish[i].first; tmp.y = fish[i].second; tmp.distance = d[sh.x][sh.y];
				this_fish.push_back(tmp);
			}
		}
		if(this_fish.empty()==true){
			break;
		}		
		sort(this_fish.begin(),this_fish.end(),compare);
		answer += this_fish[0].distance;
		sh.fish++;		
		a[this_fish[0].x][this_fish[0].y] = -1;
		a[sh.x][sh.y] = 0;
		sh.x = this_fish[0].x; sh.y = this_fish[0].y;
		if(sh.fish==sh.size){
			sh.size++;
			sh.fish = 0;
		}	
	}
		
	cout<<answer<<"\n";
	return 0;
}
