#include <iostream>
#include <algorithm>
#include <vector> 
#include <queue>
using namespace std;

int a[101][101];

vector<pair<int,int> > jirung;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n;
int apple_n,convert;
int main(void){
	cin>>n;
	cin>>apple_n;
	for(int i=0;i<apple_n;i++){
		int b,c;
		cin>>b>>c;
		a[b][c]= 1;
	}
	
	cin>>convert;
	queue<pair<int,int> > k;
	for(int i=0;i<convert;i++){
		int t1;
		char t2;
		cin>>t1>>t2;
		if(t2 == 'D'){
			k.push(make_pair(t1,1));
		}
		if(t2=='L'){
			k.push(make_pair(t1,3));
		}
	}
	int time = 0;
	int direction = 0;
	jirung.push_back(make_pair(1,1));
	a[1][1] = 2;
	while(1){
		if(!k.empty()){
			if(k.front().first==time){
				direction = (direction + k.front().second)%4;
				k.pop();
			}
		}
		time++;
		int n_x = jirung[jirung.size()-1].first + dx[direction];
		int n_y = jirung[jirung.size()-1].second + dy[direction];

		if(n_x>n||n_x<1||n_y<1||n_y>n){
			break;
		}

		if(a[n_x][n_y]==2&&jirung.size()>2){
			break;
		}
		if(a[n_x][n_y]==0){
			a[jirung[0].first][jirung[0].second] = 0;
			jirung.erase(jirung.begin());
		}
		jirung.push_back(make_pair(n_x,n_y));
		a[n_x][n_y] = 2;				
	} 
	cout<<time<<"\n";	
}
