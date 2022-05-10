#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int whet[101];
int r,c,k;
int map[101][101];
void init(){
	for(int i=0;i<101;i++){
		whet[i] = 0;
	}
}
int main(void){
	cin>>r>>c>>k;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin>>map[i][j];
		}
	}	
	int h_r = 3;
	int h_c = 3;
	int tmp_h_c = h_c;
	int tmp_h_r = h_r;
	int time = 0;
	while(1){
		if(map[r][c]==k){
			break;
		}

		if(h_r>=h_c){
			h_c = 0;
			for(int i=1;i<=h_r;i++){
				vector<pair<int,int> > v;
				init();
				for(int j=1;j<=100;j++){
					if(map[i][j]>0){
						whet[map[i][j]]++;					
					}
					map[i][j] =0;
				}
				for(int j=1;j<=100;j++){
					if(whet[j]>0){
						v.push_back(make_pair(whet[j],j));
					}
				}
				sort(v.begin(),v.end());
				for(int j=1;j<=2*v.size()-1;j = j+2){
					map[i][j] = v[j/2].second;
					map[i][j+1] = v[j/2].first;
				}
				int t = v.size();
				h_c = max(h_c,2*t);
				tmp_h_c = h_c;
			}
		}
		else{
			h_r = 0;
			for(int i=1;i<=h_c;i++){
				vector<pair<int,int> > v;
				init();
				for(int j=1;j<=100;j++){
					if(map[j][i]>0){
						whet[map[j][i]]++;					
					}
					map[j][i] =0;
				}
				for(int j=1;j<=100;j++){
					if(whet[j]>0){
						v.push_back(make_pair(whet[j],j));
					}
				}
				sort(v.begin(),v.end());
				for(int j=1;j<=2*v.size()-1;j = j+2){
					map[j][i] = v[j/2].second;
					map[j+1][i] = v[j/2].first;
				}
				int t = v.size();
				h_r = max(h_r,2*t);
				tmp_h_r = h_r;
			}
			
		}
		time++;
		if(time>100){
			time = -1;
			break;
		}
	}
	cout<<time<<"\n";
	return 0;
}
