#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int map[102][102];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n;//map의 크기를 저장하는 변수 

deque<pair<int,int> > q;
deque<pair<int,char> > v;

int right_rot(int dir){
	return (dir+1)%4;
}
int left_rot(int dir){
	if(dir==0){
		return 3;
	}
	return dir-1;
}

bool end_game(int x, int y){
	if(x<0||y<0||x>=n||y>=n){
		return false;
	}
	for(int i=0;i<q.size();i++){
		if(x==q[i].first&&y==q[i].second){
			return false;
		}
	}
	return true;
}

int main(void){
	int num; 
	cin>>n;
	cin>>num;
	for(int i=0;i<num;i++){
		int a,b;
		cin>>a>>b;
		map[a-1][b-1] = 1;
		
	}
	cin>>num;
	for(int i=0;i<num;i++){
		int a;
		char b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	q.push_back(make_pair(0,0));
	int x = 0;
	int y = 0;
	int dir = 0;
	int time = 0;
	while(1){
		if(v.front().first==time){
			if(v.front().second=='D'){
				dir = right_rot(dir);
			}
			else if(v.front().second=='L'){
				dir = left_rot(dir);
			}
			v.pop_front();
		}
		int nx = x+dx[dir];
		int ny = y+dy[dir];
		if(!end_game(nx,ny)){
			time++;
			break;
		}
		if(map[nx][ny]==0){
			q.push_front(make_pair(nx,ny));
			q.pop_back();
		}
		else if(map[nx][ny]==1){
			q.push_front(make_pair(nx,ny));	
			map[nx][ny] = 0;
		}
		x = nx;
		y = ny;
		time++;
	}
	cout<<time<<"\n";
	return 0;
}
