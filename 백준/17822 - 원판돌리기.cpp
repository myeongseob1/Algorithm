#include <iostream>
#include <deque> 
using namespace std;
int n,m,t;
deque<int> circle[51];
int dd[51][51];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,0};
void init(){
	for(int i=0;i<51;i++){
		for(int j=0;j<51;j++){
			dd[i][j] = 0;
		}
	}
}
void wheel(int x,int d,int k){
//x: x의 배수인 원판을 회전
//d: 0:시계 1:반시계  
//k: k칸만큼		
	for(int i=1;i<=n;i++){
		if(i%x==0){
			if(d==0){
				for(int jj=0;jj<k;jj++){
					int tmp = circle[i][m-1];
					circle[i].pop_back();
					circle[i].push_front(tmp);
				}
			}
			if(d==1){
				for(int j=0;j<k;j++){
					int tmp2 = circle[i][0];
					circle[i].pop_front();
					circle[i].push_back(tmp2);
				}
			}
		}
	}
}
int main(void){
	cin>>n>>m>>t;
	dy[3] = m-1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			int aa;
			cin>>aa;
			circle[i].push_back(aa);
		}
	}
	for(int i=0;i<t;i++){
		int x,d,k;
		cin>>x>>d>>k;

		wheel(x,d,k);

		init();
		for(int i=1;i<=n;i++){
			for(int j=0;j<m;j++){
				for(int k=0;k<4;k++){
					int nx = i+dx[k];
					int ny = (j+dy[k])%m;
					if(nx>=1&&nx<=n&&ny>=0&&ny<m){
						if((circle[i][j]==circle[nx][ny])&&circle[i][j]!=0){
							dd[i][j] = 1;
							dd[nx][ny] = 1;
						}
					}
				}
			}
		}
		bool g = false;		
		for(int i=1;i<=n;i++){
			for(int j=0;j<m;j++){
				if(dd[i][j]==1){
					g = true;
					circle[i][j] = 0;
				}
			}
		}
		double avg = 0;

		if(g==false){
			int whet=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<m;j++){
					avg += circle[i][j];
					if(circle[i][j]!=0){
						whet++;
					} 
				}
			}
			avg = (double)avg/whet;
			for(int i=1;i<=n;i++){
				for(int j=0;j<m;j++){
					if(circle[i][j]>avg){
						circle[i][j]--;
						continue;
					} 
					if(circle[i][j]<avg&&circle[i][j]!=0){
						circle[i][j]++;
					}
				}
			}
		}


	}
	int answer = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			answer += circle[i][j];
		}
	}
	cout<<answer<<"\n";
	return 0;
}
