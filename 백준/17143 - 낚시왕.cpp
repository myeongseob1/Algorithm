#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

struct shark{
	int dir,speed,si;
};
int dx[4] = { 0,-1,1,0};
int dy[4] = {-1, 0,0,1};
vector<shark> map[101][101];

int answer;
int r,c,m;
bool compare(shark a,shark b){
	return a.si>b.si;
}
int back_turn(int dir){
	return (3-dir)%4;
}

int main(void){
	cin>>r>>c>>m;
	for(int i=0;i<m;i++){
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		shark tmp;
		tmp.speed = c;
		tmp.dir = d;
		if(tmp.dir==4){
			tmp.dir = 0;
		}
		tmp.si = e;
		map[a-1][b-1].push_back(tmp);
	}
	for(int ii=0;ii<c;ii++){
		vector<shark> tmp_map[101][101];

		for(int j=0;j<r;j++){
			if(map[j][ii].size()>0){
				answer += map[j][ii][map[j][ii].size()-1].si;
				map[j][ii].pop_back();
				break;
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(map[i][j].empty()==false){
					for(int k=0;k<map[i][j].size();k++){
						shark to = map[i][j][k];
						int dir = to.dir;
						int sp = to.speed;
						int nx = i + dx[dir]*sp;
						int ny = j + dy[dir]*sp;

						while(1){
							if(nx<0){
								nx *= -1;
								dir = back_turn(dir);
							}
							if(nx>r-1){
								nx = 2*(r-1) - nx;
								dir = back_turn(dir);
							}
							if(ny<0){

								ny *= -1;
								dir = back_turn(dir);
							}
							if(ny>c-1){
//								cout<<r<<" "<<c<<" "<<nx<<" "<<ny<<"\n";							

								ny = 2*(c-1)-ny;
								dir = back_turn(dir);
							}
							if(nx>=0&&nx<r&&ny>=0&&ny<c){

								break;
							}
						
						}
						to.dir = dir;
						tmp_map[nx][ny].push_back(to);
					}
				}
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				map[i][j] = tmp_map[i][j];
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(map[i][j].size()>1){
					sort(map[i][j].begin(),map[i][j].end(),compare);
					int t = map[i][j].size();
					for(int k=0;k<t-1;k++){
						map[i][j].pop_back();
					}
				}
				
			}
		}

		
	}
	cout<<answer<<"\n";
	return 0;
}
