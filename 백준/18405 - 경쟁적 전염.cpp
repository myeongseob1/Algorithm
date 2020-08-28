#include <iostreaWm>
#include <queue>
#include <algorithm>
using namespace std;

int a[201][201];
int d[201][201];
int n,k;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

struct virus{
	int num;
	int x;
	int y;
};

bool compare(const virus a, const virus b){
	return a.num<b.num;
}


int main(void){
	int x,y,time;
	vector<virus> vr;
	queue<virus> q;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0){
				vr.push_back({a[i][j],i,j});
			}
		}
	}
	
	cin>>time>>x>>y;
	sort(vr.begin(),vr.end(),compare);
	for(int i=0;i<vr.size();i++){
		q.push(vr[i]);
	}	
	int w = 0;
	while(!q.empty()){
		if(w==vr.size()*time) break;
		int f = q.front().x;
		int g = q.front().y;
		w++;
		q.pop();
		for(int t=0;t<4;t++){
			int nx = f+dx[t];
			int ny = g+dy[t];
			if(nx>=0&&nx<n&&ny>=0&&ny<n){
				if(d[nx][ny]==0&&a[nx][ny]==0){
					d[nx][ny] = 1;
					a[nx][ny] = a[f][g];
					q.push({a[nx][ny],nx,ny});
				}
			}
		}
	}
	
	cout<<a[x-1][y-1]<<"\n";
	return 0;
}
