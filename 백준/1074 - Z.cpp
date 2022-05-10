#include <iostream>
using namespace std;

int n,r,c;
int ans;
void dfs(int x,int y,int size){
	if(size==0) return;
	int sz = 1<<size;
	long long hlf = sz/2;
	if(x/hlf==0&&y/hlf==0){
		dfs(x%hlf,y%hlf,size-1);	
	}else if(x/hlf==1&&y/hlf==0){
		ans += hlf*hlf;		
		dfs(x%hlf,y%hlf,size-1);	
	}else if(x/hlf==0&&y/hlf==1){
		ans += 2*hlf*hlf;		
		dfs(x%hlf,y%hlf,size-1);	
		
	}else{
		ans += 3*hlf*hlf;		
		dfs(x%hlf,y%hlf,size-1);	
	}
}

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


	cin>>n>>c>>r;
	
	dfs(r,c,n);
	cout<<ans<<"\n";
	return 0;
}
