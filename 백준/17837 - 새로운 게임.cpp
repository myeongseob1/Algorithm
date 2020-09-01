#include <iostream>
#include <deque>
#include <vector> 
using namespace std;

struct horse{
	int num,dir; 
};
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};//아래(0) 오(1) 왼(2) 위(3) 
int answer;
int a[13][13];//0:흰색판 1:빨간색판 2:파란색판 
int n,kk;
deque<int> field[13][13];
vector<int> list_dir;
int back_turn(int dir){
	if(dir==1||dir==3){
		return (dir+1)%4;
	}
	else if(dir==0){
		return 3;
	}
	else if(dir==2){
		return 1;
	}
}
int main(void){
	cin>>n>>kk;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}	
	}
	for(int i=0;i<kk;i++){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		field[aa][bb].push_back(i+1);
		list_dir.push_back(cc%4);
	}
	int t=0;
	while(1){
		bool end = false;
		for(int num=1;num<=kk;num++){
			bool use = false;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int k=0;k<field[i][j].size();k++){
						if(num==field[i][j][k]){
							use = true;
							int nx = i+dx[list_dir[num-1]];
							int ny = j+dy[list_dir[num-1]];
							if(a[nx][ny]==2||(nx<1||nx>n||ny<1||ny>n)){
								nx = i+dx[back_turn(list_dir[num-1])];
								ny = j+dy[back_turn(list_dir[num-1])];
								list_dir[num-1] = back_turn(list_dir[num-1]);
								if(a[nx][ny]==2||(nx<1||nx>n||ny<1||ny>n)){
									use = true;
									break;
								}
								int tmp = field[i][j][k];
								field[i][j].erase(field[i][j].begin()+k);
								field[nx][ny].push_back(tmp);
								k--;
								break;	
							}
							if(a[nx][ny]==0){
								for(int ii=k;ii<field[i][j].size();ii++){
									int save = field[i][j][ii];
									field[i][j].erase(field[i][j].begin()+ii);
									field[nx][ny].push_back(save);
									ii--;
								}
								break;	
	
							}
							if(a[nx][ny]==1){
								int iter = field[i][j].size()-k;
								for(int ii=0;ii<iter;ii++){
									int save = field[i][j][field[i][j].size()-1];
									field[i][j].pop_back();
									field[nx][ny].push_back(save);	
								}
								break;

						}

					}
					
				}
				if(use==true) break;
			}
			if(use==true) break;
		}
			for(int ii=1;ii<=n;ii++){
				for(int jj=1;jj<=n;jj++){
					if(field[ii][jj].size()>=kk){
						end = true;
					}
				}
			}
			
						for(int ii=1;ii<=n;ii++){
				for(int jj=1;jj<=n;jj++){
					cout<<field[ii][jj].size()<<" ";
				}
				cout<<"\n";
			}
			cout<<"\n";


		}
		
		t++;
		if(end == true){
			answer = t;
			break;
		}
		if(t==7){
			
			answer = -1;
			break;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
