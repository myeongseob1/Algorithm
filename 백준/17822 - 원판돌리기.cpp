#include <iostream>
#include <deque>
#include <vector> 
using namespace std;

int n,m,t;
deque<int> cir[51];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(void){
	cin>>n>>m>>t;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int a;
			cin>>a;
			cir[i].push_back(a);
		}
	}
	for(int ii=0;ii<t;ii++){
		int x,d,k;
		cin>>x>>d>>k;
		if(d==0){
			for(int i=0;i<n;i++){
				if((i+1)%x==0){
					for(int j=0;j<k;j++){
						int tmp = cir[i][cir[i].size()-1];
						cir[i].pop_back();
						cir[i].push_front(tmp);			
					}
				}
			}
		}else if(d==1){
			for(int i=0;i<n;i++){
				if((i+1)%x==0){
					for(int j=0;j<k;j++){
						int tmp = cir[i][0];
						cir[i].pop_front();
						cir[i].push_back(tmp);			
					}
				}
			}
			
		}
		vector<pair<int,int> > v;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int x = i;
				int y = j;
				for(int k=0;k<4;k++){
					int nx = x + dx[k];
					int ny = y + dy[k];
					if(nx>=0&&nx<n&&ny>=0&&ny<m){
						if(cir[nx][ny]==cir[x][y]){
							if(cir[nx][ny]!=0&&cir[x][y]!=0){
								v.push_back(make_pair(nx,ny));
								v.push_back(make_pair(x,y));						
							}
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			if(cir[i][0]==cir[i][m-1]){
				if(cir[i][0]!=0&&cir[i][m-1]!=0){
					v.push_back(make_pair(i,0));
					v.push_back(make_pair(i,m-1));			
				}
			}
		}
		if(v.size()==0){
			double avg = 0;
			double num = 0;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(cir[i][j]!=0){
						num++;
						avg+=cir[i][j];
					}
				}
			}
			avg = avg/num;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(cir[i][j]!=0){
						if(double(cir[i][j])>avg){
							cir[i][j]--;
						}
						else if(double(cir[i][j])<avg){
							cir[i][j]++;
						}
						
					}
				}
			}

		}else{
			for(int i=0;i<v.size();i++){
				cir[v[i].first][v[i].second] = 0;
			}
		}
	}
	int answer = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			answer += cir[i][j];
		}
	}
	cout<<answer<<"\n";
	return 0;
}
