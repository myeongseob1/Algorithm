#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n;
int pop[11];
int per_tmp[11];
vector<int> link[11];
int visit[11];
int answer = 2100000000;
void init(){
	for(int i=0;i<11;i++){
		per_tmp[i] = 0;
		visit[i] = 0;
	}
}

bool bfs(int start, int t){
	queue<int> q;
	q.push(start);
	visit[start] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0;i<link[x].size();i++){
			if(visit[link[x][i]]==t){
				visit[link[x][i]] = 0;
				q.push(link[x][i]);
			}
		}	
	}
	for(int i=1;i<=n;i++){
		if(visit[i]==t){
			return false;
		}
	}
	return true;
}


int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>pop[i];
	}
	int m;
	int t;
	for(int i=1;i<=n;i++){
		cin>>m;
		for(int j=0;j<m;j++){
			cin>>t;
			link[i].push_back(t);
		}
	}
	for(int ii=1;ii<=n;ii++){
		init();
		for(int j=ii+1;j<=n;j++){
			per_tmp[j] = 1;
		}
		do{
			int cnt = 0; 
			bool possible1,possible2;
			for(int i=1;i<=n;i++){
				if(per_tmp[i]==0){
					visit[i] = 1;
				}
				else{
					visit[i] = 2;
				}
			}
			for(int i=1;i<=n;i++){
				if(per_tmp[i]==0){
					possible1 = bfs(i,1);
					break;
				}
			}
			for(int i=1;i<=n;i++){
				if(per_tmp[i]==1){
					possible2 = bfs(i,2);
					break;
				}
			}
			int aa=0,bb=0;			
			if(possible1==true&&possible2==true){
				for(int i=1;i<=n;i++){
					if(per_tmp[i]==0){
						aa += pop[i];
					}
					if(per_tmp[i]==1){
						bb += pop[i];
					}
				}
				int result = abs(aa-bb);
				if(result<answer){
					answer = result;
				}
			}
		}while(next_permutation(per_tmp+1,per_tmp+n+1));
	}
	if(answer == 2100000000){
		cout<<-1<<"\n";
	}else cout<<answer<<"\n";
	return 0;
}
