#include <iostream>
#include <vector>

using namespace std;
int n,l;
int answer;
int a[101][101];
int d[101][101];
void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			d[i][j] = 0;
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
	init();
	for(int j=0;j<n;j++){
		bool possible = true;
		for(int i=0;i<n-1;i++){
			if(a[i][j]-a[i+1][j]>1||a[i][j]-a[i+1][j]<-1){
				possible = false;
				break;
			}
			if(a[i][j]-a[i+1][j]==1){//내리막길이 보이면
			 	if(i+l>=n){
			 		possible = false;
				 	break;
				} 
				for(int k=1;k<=l;k++){
					if(a[i][j]-a[i+k][j]!=1){
						possible = false;
						break;
					}
			 		d[i+k][j]++;
				}
			}
			if(a[i][j]-a[i+1][j]==-1){//오르막길이 보이면 
				if(i-l+1<0){
					possible = false;
					break;
				}
				for(int k=0;k<l;k++){
					if(a[i+1][j]-a[i-k][j]!=1){
						possible = false;
						break;
					}
					d[i-k][j]++;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(d[i][j]>1){
				possible = false;
				break;
			}
		}

		if(possible==true){
			answer++;
		}

	}
	cout<<answer<<"\n";
	return 0;
}
