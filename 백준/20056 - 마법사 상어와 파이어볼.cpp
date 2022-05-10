#include <iostream>
#include <deque>
using namespace std;

struct fire{
	int dir,speed,f_m;
	bool move;
};


deque<fire> map[51][51];
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
int n,m,kk;

int main(void){
	cin>>n>>m>>kk;
	for(int i=0;i<m;i++){
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		fire tmp;
		tmp.dir = e;
		tmp.f_m = c;
		tmp.speed = d;
		tmp.move = false;
		map[a-1][b-1].push_back(tmp);
	}
	for(int ii=0; ii<kk; ii++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<map[i][j].size();k++){
					if(map[i][j][k].move==false){
						int sp = map[i][j][k].speed;
						int dir = map[i][j][k].dir;
						int nx = i + dx[dir] * sp;
						int ny = j + dy[dir] * sp;
						if(nx<0){
							while(1){
								nx += n;
								if(nx>=0&&nx<n){
									break;
								}
							}
						}
						if(ny<0){
							while(1){
								ny += n;
								if(ny>=0&&ny<n){
									break;
								}											
							}
						}
						if(nx>n-1){
							while(1){
								nx -= n;
								if(nx>=0&&nx<n){
									break;
								}
							}
						}
						if(ny>n-1){
							while(1){
								ny -= n;
								if(ny>=0&&ny<n){
									break;
								}											
							}
						}

						fire tmp = map[i][j][k];
						tmp.move = true;
						map[i][j].pop_front();
						map[nx][ny].push_back(tmp);
						k--;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<map[i][j].size();k++){
					map[i][j][k].move = false;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j].size()>1){
					int mess = 0;
					int first_size = map[i][j].size();
					int num_odd = 0;
					int sp = 0;
					for(int k=0;k<map[i][j].size();k++){
						mess += map[i][j][k].f_m;
						sp += map[i][j][k].speed;
						if(map[i][j][k].dir%2==1) num_odd++;
					}
					map[i][j].clear();
					for(int k=0;k<4;k++){
						fire tmp;
						tmp.f_m = mess/5;
						if(tmp.f_m<=0){
							break;
						}
						tmp.speed = sp/first_size;
						if(num_odd==first_size || num_odd==0){
							tmp.dir = 2 * k;
						}
						else{
							tmp.dir = 2 * k +1;
						}
						tmp.move = false;
						map[i][j].push_back(tmp);
					}
				}
			}
		}
		
	}
	int answer = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<map[i][j].size();k++){
				answer += map[i][j][k].f_m;
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}
