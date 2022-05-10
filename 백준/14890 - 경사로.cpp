#include <iostream>
#include <cmath>

using namespace std;

int n,l;
int map[101][101];
int stair[101][101];
int main(void){
	cin>>n>>l;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	int answer = 0;
	for(int i=0;i<n;i++){
		bool as = true;
		for(int j=0;j<n-1;j++){
			if(abs(map[i][j+1]-map[i][j])>1){
				as = false;
				break;
			}
			if(map[i][j+1]-map[i][j]==1){
				if(j+1-l<0){
					as = false;
					break;	
				} 
				bool fa = true;
				for(int t=j+1-l;t<j+1;t++){
					if(map[i][t]!=map[i][j]){
						fa = false;
						break;
					}
					if(stair[i][t]==1){
						fa = false;
						break;
					}
				}
				if(fa==false){
					as = false;
					break;
				}
				for(int t=j+1-l;t<j+1;t++){
					stair[i][t] = 1;
				}	
			}
			if(map[i][j]-map[i][j+1]==1){
				if(j+l+1>n){
					as = false;
					break;	
				}
				bool fa = true;
				for(int t=j+1;t<j+1+l;t++){
					if(map[i][t]!=map[i][j]-1){
						fa = false;
						break;
					}
					if(stair[i][t]==1){
						fa = false;
						break;
					}
				}
				if(fa==false){
					as = false;
					break;	
				}
				for(int t=j+1;t<j+1+l;t++){
					stair[i][t] = 1;
				}	
				
			}
		}
		if(as==true) answer++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			stair[i][j] = 0;
		}
	}
	for(int j=0;j<n;j++){
		bool as = true;
		for(int i=0;i<n-1;i++){
			if(abs(map[i+1][j]-map[i][j])>1){
				as = false;
				break;
			}
			if(map[i+1][j]-map[i][j]==1){
				if(i+1-l<0){
					as = false;
					break;	
				} 
				bool fa = true;
				for(int t=i+1-l;t<i+1;t++){
					if(map[t][j]!=map[i][j]){
						fa = false;
						break;
					}
					if(stair[t][j]==1){
						fa = false;
						break;
					}
				}
				if(fa==false){
					as = false;
					break;
				}
				for(int t=i+1-l;t<i+1;t++){
					stair[t][j] = 1;
				}	
			}
			if(map[i][j]-map[i+1][j]==1){
				if(i+l+1>n){
					as = false;
					break;	
				}
				bool fa = true;
				for(int t=i+1;t<i+1+l;t++){
					if(map[t][j]!=map[i][j]-1){
						fa = false;
						break;
					}
					if(stair[t][j]==1){
						fa = false;
						break;
					}
				}
				if(fa==false){
					as = false;
					break;	
				}
				for(int t=i+1;t<i+1+l;t++){
					stair[t][j] = 1;
				}	
				
			}
		}
		if(as==true) answer++;
	}

	cout<<answer<<"\n";
	return 0;
}
