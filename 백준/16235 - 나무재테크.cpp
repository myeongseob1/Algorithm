#include <iostream>
#include <deque>

using namespace std;

int n,m,k;
int yang[11][11];
int hyang[11][11];
int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
int dy[8] = {-1, 0, 1,-1,1,-1,0,1};

deque<int> map[11][11];

int main(void){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>yang[i][j];
			hyang[i][j] = 5;
		}
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		map[a-1][b-1].push_back(c);
	}
	for(int ii=0;ii<k;ii++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int dele = -1;
				for(int k=map[i][j].size()-1;k>=0;k--){
					if(map[i][j][k]<=hyang[i][j]){
						hyang[i][j] -= map[i][j][k]; 
						map[i][j][k]++;
					}else{
						dele = k;
						break;
					}
				}
				if(dele >=0 ){
					for(int k=0;k<=dele;k++){
						hyang[i][j] += map[i][j][0]/2;
						map[i][j].pop_front();
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<map[i][j].size();k++){
					if(map[i][j][k]>0&&map[i][j][k]%5==0){
						for(int t=0;t<8;t++){
							int nx = i + dx[t];
							int ny = j + dy[t];
							if(nx>=0&&nx<n&&ny>=0&&ny<n){
								map[nx][ny].push_back(1);
							}
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				hyang[i][j] += yang[i][j];
			}
		}
	}
	int answer = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			answer += map[i][j].size();
		}
	}
	cout<<answer<<"\n";
	return 0;
}
