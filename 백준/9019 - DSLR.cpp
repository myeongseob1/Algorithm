#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

bool visit[10001];
string yun[10001];
int n;

void init(){
	for(int i=0;i<10001;i++){
		visit[i] = false;
		yun[i] = "";
	}
}


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		init();
		queue<pair<int,string> > q;
		q.push(make_pair(a,""));
		visit[a] = true;
		while(!q.empty()){
			int x = q.front().first;
			string hstr = q.front().second;
			q.pop();
			if(x==b){
				cout<<yun[b]<<"\n";
				break;
			} 
			int nx = (2*x)%10000;
			if(visit[nx]==false){
				visit[nx] = true;
				yun[nx] = yun[x] + "D";
				q.push(make_pair(nx,hstr+"D"));
			}
	
			nx = x-1;
			if(nx==-1) nx = 9999;
			if(visit[nx]==false){
				visit[nx] = true;
				yun[nx] = yun[x] + "S";
				q.push(make_pair(nx,hstr+"S"));
			}
			
			nx = (x%1000) * 10  + x/1000;
			if(visit[nx]==false&&nx>=0&&nx<=10000){
				visit[nx] = true;
				yun[nx] = yun[x] + "L";
				q.push(make_pair(nx,hstr+"L"));
			}
			
			nx = (x%10)*1000 + x/10;
			if(visit[nx]==false&&nx>=0&&nx<=10000){
				visit[nx] = true;
				yun[nx] = yun[x] + "R";
				q.push(make_pair(nx,hstr+"L"));
			}
			
			
		}
	}
	
	return 0;
}
