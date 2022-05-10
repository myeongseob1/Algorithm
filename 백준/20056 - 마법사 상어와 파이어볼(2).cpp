#include <iostream>
#include <deque>
using namespace std;

struct fire_ball{
	int mess,speed,dir;
};

int dx[8] = {-1,-1,0,1,1, 1,0,-1};
int dy[8] = { 0, 1,1,1,0,-1,-1,-1};
int n,m,k;
deque<fire_ball> map[51][51];
int answer;
int main(void){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		fire_ball tmp;
		tmp.mess = c;
		tmp.speed = d;
		tmp.dir = e;
		map[a-1][b-1].push_back(tmp);
	}
	for(int ii=0;ii<k;ii++){
		deque<fire_ball> tmp_map[51][51];
	
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j].size()>0){
					for(int kk=0;kk<map[i][j].size();kk++){
						fire_ball now = map[i][j][map[i][j].size()-1];
						int nx = i + dx[now.dir]*now.speed;
						int ny = j + dy[now.dir]*now.speed;
						while(1){
							if(nx<0){
								nx += n;
							}
							if(nx>=n){
								nx -= n;
							}
							if(ny<0){
								ny += n;
							}
							if(ny>=n){
								ny -= n;
							}	
							if(nx>=0&&nx<n&&ny>=0&&ny<n){
								break;
							}
						}
						tmp_map[nx][ny].push_back(now);
						map[i][j].pop_back();
						kk--;
					}
				}
			}
		}
		bool s =false;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(tmp_map[i][j].size()>1){
					int sum = 0;
					int sz = tmp_map[i][j].size();
					int num_odd = 0;
					int speed = 0;
					for(int kk=0;kk<tmp_map[i][j].size();kk++){
						sum += tmp_map[i][j][kk].mess;
						speed += tmp_map[i][j][kk].speed;
						if(tmp_map[i][j][kk].dir%2==1){
							num_odd++;
						}
					}	
					tmp_map[i][j].clear();
					if(sum/5>0){
						for(int kk=0;kk<4;kk++){
							fire_ball fr;
							fr.mess = sum/5;
							fr.speed = speed/sz;
							if(num_odd==sz||num_odd==0){
								fr.dir = kk * 2;
							}else{
								fr.dir = 2*kk + 1;
							}
							tmp_map[i][j].push_back(fr);	
						}
					}
					
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				map[i][j] = tmp_map[i][j];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j].size()>0){
				for(int k=0;k<map[i][j].size();k++){
					answer += map[i][j][k].mess;
				}
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
	
}
