#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;
int a[101][101];
vector<pair<int,int> > axis;
vector<pair<int,int> > dire;
int n;
int answer=0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

void check(){
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(a[i][j]==1&&a[i][j+1]==1&&a[i+1][j]==1&&a[i+1][j+1]==1){
				answer++;	
			}
		}
	}
}

int main(void){
	int y,x,d,g;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y>>d>>g;
		axis.push_back(make_pair(y,x));
		a[x][y] = 1;
		dire.push_back(make_pair(d,g));
	}
	for(int i=0;i<dire.size();i++){
		int l = (int)pow(2,dire[i].second);
		vector<int> tmp(l);
		tmp[0]=dire[i].first;
		if(dire[i].second!=0){
			for(int j=1;j<=dire[i].second;j++){
				int start = (int)pow(2,j-1);
				int end = (int)pow(2,j)-1;
				for(int k=start;k<=end;k++){
					tmp[k]= (tmp[end-k]+1)%4; 
				}			
			}		
		}
		int ny = axis[i].first;
		int nx = axis[i].second;
		for(int j=0;j<tmp.size();j++){
			nx += dx[tmp[j]];
			ny += dy[tmp[j]];
			a[nx][ny] = 1;
		}
		
	}
	check();
	cout<<answer<<"\n";
	return 0;
}
