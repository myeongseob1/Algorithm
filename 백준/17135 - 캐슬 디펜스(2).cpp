#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
struct enemy{
	int x;
	int y;
	int distance;
};

using namespace std;
int n,m,d,answer;
int a[18][18];
vector<pair<int,int> > warrior;

bool compare(enemy a,enemy b){
	if(a.distance>b.distance){
		return false;
	}
	else if(a.distance==b.distance){
		if(a.y>=b.y){
			return false;
		}
		else true;
	}
	else{
		return true;
	}
}

int man_distance(int a_x,int a_y,int b_x,int b_y){
	return abs(a_x-b_x)+abs(a_y-b_y);
}

void dfs(int iter,int t){
	if(t==3){
		int kill=0;
		int b[18][18];
		copy(&a[0][0],&a[17][17],&b[0][0]);
		while(1){
			int aa[18][18];
			copy(&a[0][0],&a[17][17],&aa[0][0]);
			for(int i=0;i<warrior.size();i++){
				vector<enemy> e;
				for(int x=0;x<n;x++){
					for(int y=0;y<m;y++){
						if(a[x][y]==1&&man_distance(x,y,warrior[i].first,warrior[i].second)<=d&&man_distance(x,y,warrior[i].first,warrior[i].second)>0){
							e.push_back({x,y,man_distance(x,y,warrior[i].first,warrior[i].second)});	
						}
					}
				}
				if(e.empty()){
					continue;
				}
				sort(e.begin(),e.end(),compare);
				aa[e[0].x][e[0].y] = 0;
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(aa[i][j]==0&&a[i][j]==1){
						kill++;
						a[i][j] = 0;	
					}
				}
			}
			
			for(int j=0;j<m;j++){
				a[0][j] = 0;
			}
			for(int i=0;i<n-1;i++){
				for(int j=0;j<m;j++){
					a[i+1][j] = aa[i][j];
				}
			}
			int juk=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(a[i][j]==1){
						juk++;	
					}
				}
			}
			if(juk==0){
				break;
			}			
		}
		if(answer<kill){
			answer = kill;
			kill=0;
		}
		copy(&b[0][0],&b[17][17],&a[0][0]);
		return;
	}
	if(iter>=m){
		return;
	}
	warrior.push_back(make_pair(n,iter));
	dfs(iter+1,t+1);
	warrior.pop_back();
	dfs(iter+1,t);
}
int main(void){
	cin>>n>>m>>d;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	
	dfs(0,0);
	cout<<answer<<"\n";
	return 0;
}
