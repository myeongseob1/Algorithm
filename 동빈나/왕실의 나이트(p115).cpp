#include <iostream>

using namespace std;

int dx[8] = {1,2, 1,-1,-1,-2, 2,-2};
int dy[8] = {2,1,-2, 2,-2,-1,-1,1};
int m,n,ans;
int main(void){
	cin>>n>>m;
	for(int k=0;k<8;k++){
		int nx = n+dx[k];
		int ny = m+dy[k];
		if(nx>=0&&nx<8&&ny>=0&&ny<8){
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
