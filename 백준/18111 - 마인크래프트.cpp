#include <iostream>

using namespace std;
int n,m,b;
int map[501][501];
int max_map = 0;
int min_map = 987654321;
int answer1 = 987654321;
int answer2;
int main(void){
	cin>>n>>m>>b;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			max_map = max(max_map,map[i][j]);
			min_map = min(min_map,map[i][j]);
		}
	}
	for(int ii=min_map;ii<=max_map;ii++){
		int time1 =0;
		int inventory = b;
		bool gang = true;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]>=ii){
					inventory += map[i][j] - ii;
					time1 += 2*(map[i][j] - ii); 
				}else if(map[i][j]<ii){
					inventory -= ii - map[i][j];
					time1 += ii-map[i][j];
				}
			}
		}
		if(answer1 >= time1 &&inventory>=0 ){
			answer1 = time1;
			if(ii >= answer2){
				answer2 = ii;
			}
		}		
	}
	cout<<answer1<<" "<<answer2<<"\n";
	return 0;
} 
