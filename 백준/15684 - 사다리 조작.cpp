#include <iostream>
#include <vector>

using namespace std;
int n,m,h;
int a[31][11];
int result[12];
int answer= 10000000;
vector<pair<int,int> > p;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int count;
bool game(int start){
	int index = start;
	for(int j=1;j<=h;j++){
		if(a[j][index]==1 && index !=n){
			index++;
			continue;
		}
		if(a[j][index-1]==1&&index != 1){
			index--;
			continue;
		}
	}
	if(start!=index){
		return false;
	}
	return true;
}



void dfs(int cnt,int x,int y){
	if(cnt > 3){
		return;
	}
	int cant = 0;
	for(int i=1;i<=n;i++){
		if(game(i)==false){
			break;
		}
		else{
			cant++;
		}
	}
	if(cant==n){
		if(answer>cnt){
			answer = cnt;
			if(answer==0||answer==1) return;
		}
	} 

	for(int i=x;i<=h;i++,y=1){
		for(int j=y;j<n;j++){
			if(a[i][j]==1){
				j++;
			}else{
				a[i][j] = 1;
				dfs(cnt+1,i,j+2);
				a[i][j] = 0;
			}
		}
	}
	
}



int main(void){
	cin>>n>>m>>h;
	for(int i=0;i<m;i++){
		int p,q;
		cin>>p>>q;
		a[p][q] = 1;
	}
	if(m==0){
		answer = 0;
	}else{
		dfs(0,1,1);	
	}
	if(answer>3){
		answer = -1;
	}
	cout<<answer<<"\n";
	return 0;
} 
