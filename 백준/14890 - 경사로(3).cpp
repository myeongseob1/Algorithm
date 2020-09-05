#include <iostream>
#include <vector>

using namespace std;
int n,l;
int answer;
int a[101][101];
int d[101][101];
void init_tran(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			d[i][j] = 0;
		}
	}
	int tmp[101][101];
	copy(&a[0][0],&a[100][100],&tmp[0][0]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j] = tmp[j][i];
		}
	}
}
void solution(){
	for(int i=0;i<n;i++){
		bool possible = true; 
		for(int j=0;j<n-1;j++){
			if(a[i][j]-a[i][j+1]>1||a[i][j]-a[i][j+1]<-1){
				possible = false;
				break;
			}
			if(a[i][j]-a[i][j+1]==1){//내리막길이 보이면
			 	if(j+l>=n){
			 		possible = false;
				 	break;
				} 
				for(int k=1;k<=l;k++){
					if(a[i][j]-a[i][j+k]!=1){
						possible = false;
						break;
					}
			 		d[i][j+k]++;
				}
			}
			if(a[i][j]-a[i][j+1]==-1){//오르막길이 보이면 
				if(j-l+1<0){
					possible = false;
					break;
				}
				for(int k=0;k<l;k++){
					if(a[i][j+1]-a[i][j-k]!=1){
						possible = false;
						break;
					}
					d[i][j-k]++;
				}
			}
		}
		for(int j=0;j<n;j++){
			if(d[i][j]>1){
				possible = false;
				break;
			}
		}
		if(possible==true){
			answer++;
		}
	}	
}
int main(void){
	cin>>n>>l;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	solution();
	init_tran();
	solution();
	cout<<answer<<"\n";
	return 0;
}
