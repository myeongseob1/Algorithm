#include <iostream>
#include <vector>

using namespace std;

struct camera{
	int x,y,kind;
};
int answer; 
int a[9][9];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int n,m;
vector<camera> ca;
void watch(int x,int y,int dir){	
	int nx = x+dx[dir];
	int ny = y+dy[dir];
	if(nx>=0&&nx<n&&ny>=0&&ny<m){
		if(a[nx][ny]!=6){
			a[nx][ny] = 9;
			watch(nx,ny,dir);
		}
		return;
	}
	return;
}
int check(){
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==0){
				ans++;				
			}
		}
	}
	return ans;
}
void dfs(int iter){
	if(ca.size()==0){
		answer = min(answer,check());		
		return;
	}
	if(iter>ca.size()-1){
		answer = min(answer,check());		
		return;
	}

	int tmp[9][9];
	if(ca[iter].kind==1){
		for(int i=0;i<4;i++){
			copy(&a[0][0],&a[8][8],&tmp[0][0]);
			watch(ca[iter].x,ca[iter].y,i);
			dfs(iter+1);
			copy(&tmp[0][0],&tmp[8][8],&a[0][0]);	
		}	
	}
	else if(ca[iter].kind==2){
		for(int i=0;i<2;i++){
			copy(&a[0][0],&a[8][8],&tmp[0][0]);
			watch(ca[iter].x,ca[iter].y,i);
			watch(ca[iter].x,ca[iter].y,i+2);
			dfs(iter+1);
			copy(&tmp[0][0],&tmp[8][8],&a[0][0]);	
		}				
	}
	else if(ca[iter].kind==3){
		for(int i=0;i<4;i++){
			copy(&a[0][0],&a[8][8],&tmp[0][0]);
			watch(ca[iter].x,ca[iter].y,i);
			watch(ca[iter].x,ca[iter].y,(i+1)%4);
			dfs(iter+1);
			copy(&tmp[0][0],&tmp[8][8],&a[0][0]);	
		}				
	}
	else if(ca[iter].kind==4){
		for(int i=0;i<4;i++){
			copy(&a[0][0],&a[8][8],&tmp[0][0]);
			watch(ca[iter].x,ca[iter].y,i);
			watch(ca[iter].x,ca[iter].y,(i+1)%4);
			watch(ca[iter].x,ca[iter].y,(i+2)%4);
			dfs(iter+1);
			copy(&tmp[0][0],&tmp[8][8],&a[0][0]);	
		}				
	}
	else if(ca[iter].kind==5){
		copy(&a[0][0],&a[8][8],&tmp[0][0]);
		for(int i=0;i<4;i++){
			watch(ca[iter].x,ca[iter].y,i);
		}
		dfs(iter+1);
		copy(&tmp[0][0],&tmp[8][8],&a[0][0]);	
	}	
}
int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]==0) answer++;
			if(a[i][j]!=6&&a[i][j]!=0){
				ca.push_back({i,j,a[i][j]});
			}
		}
	}
	dfs(0);
	cout<<answer<<"\n";
	return 0;
}
