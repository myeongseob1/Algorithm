#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

struct car{
	int x,y,oil;
};
int answer;
struct people{
	int go_x;
	int go_y;
	int ar_x;
	int ar_y;
	int dist;
};

int n,m,oo;
int a[22][22];
int d[22][22];
int d2[22][22];
car taxi;
vector<people> list;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void init(){
	for(int i=0;i<22;i++){
		for(int j=0;j<22;j++){
			d[i][j] = 0;
			d2[i][j] = 0;
		}
	}
}
bool compare(people ax,people bx){
	if(ax.dist==bx.dist){
		if(ax.go_x==bx.go_x){
			return ax.go_y>bx.go_y;
		}
		return ax.go_x>bx.go_x;
	}
	return ax.dist>bx.dist;
}
int main(void){
	cin>>n>>m>>oo;
	taxi.oil = oo;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cin>>taxi.x>>taxi.y;
	for(int i=0;i<m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		list.push_back({a,b,c,d});
	}
	while(1){
		init();
		queue<pair<int,int> > q;
		q.push(make_pair(taxi.x,taxi.y));
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int k=0;k<4;k++){
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
					if(d[nx][ny]==0&&a[nx][ny]==0&&!(nx==taxi.x&&ny==taxi.y)){
						d[nx][ny] = d[x][y] + 1;
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
		for(int i=0;i<list.size();i++){
			list[i].dist = d[list[i].go_x][list[i].go_y];
		}
		bool imp = false;
		for(int i=0;i<list.size();i++){
			list[i].dist = d[list[i].go_x][list[i].go_y];
			if(list[i].dist==0&&(taxi.x!=list[i].go_x&&taxi.y!=list[i].go_y)){
				imp = true;
			}
		}
		if(imp == true){
			answer = -1;
			break;
		}		
		sort(list.begin(),list.end(),compare);
		taxi.x = list[list.size()-1].go_x;
		taxi.y = list[list.size()-1].go_y;
		taxi.oil -= list[list.size()-1].dist;
		if(taxi.oil<=0){
			answer = -1;
			break;
		}
		queue<pair<int,int> > q2;
		q2.push(make_pair(taxi.x,taxi.y));
		while(!q2.empty()){
			int x = q2.front().first;
			int y = q2.front().second;
			q2.pop();
			for(int k=0;k<4;k++){
				int nx = x+dx[k];
				int ny = y+dy[k];
				if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
					if(d2[nx][ny]==0&&a[nx][ny]==0&&!(nx==taxi.x&&ny==taxi.y)){
						d2[nx][ny] = d2[x][y] + 1;
						q2.push(make_pair(nx,ny));					
					}
				}
			}
		}
		bool imp2 = false;
		if(d2[list[list.size()-1].ar_x][list[list.size()-1].ar_y]==0&&taxi.x != list[list.size()-1].ar_x&&taxi.y != list[list.size()-1].ar_y){
			imp2 = true;
		}
		if(imp2 == true){
			answer = -1;
			break;
		}		
		taxi.x = list[list.size()-1].ar_x;
		taxi.y = list[list.size()-1].ar_y;
		taxi.oil -= d2[list[list.size()-1].ar_x][list[list.size()-1].ar_y]; 
		if(taxi.oil<0){
			answer = -1;
			break;
		}
		taxi.oil += 2 * d2[list[list.size()-1].ar_x][list[list.size()-1].ar_y]; 
		list.pop_back();
		if(list.empty()==true){
			answer = taxi.oil;
			break;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
