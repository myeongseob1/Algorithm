#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;
int n,p,q;//p는 최소 q는 최대 
int a[51][51];

int minus_abs(int x,int y){
	if(x>y){
		return x-y;
	}
	else return y-x;	
}

int main(void){
	int answer=0;
	cin>>n>>p>>q;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	while(1){
		int tmp=0;
		vector<pair<int,int> > p;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(minus_abs(a[i][j],a[i+1][j])>=p&&minus_abs(a[i][j],a[i+1][j])<q&&i+1<n){
					p.push_back(make_pair(i,j));
				}
				if(minus_abs(a[i][j],a[i][j+1])>=p&&minus_abs(a[i][j],a[i][j+1])<q&&j+1<n){
					p.push_back(make_pair(i,j));
				}
				if(minus_abs(a[i][j],a[i-1][j])>=p&&minus_abs(a[i][j],a[i-1][j])<q&&i-1>=0){
					p.push_back(make_pair(i,j));
				}
				if(minus_abs(a[i][j-1],a[i][j-1])>=p&&minus_abs(a[i][j-1],a[i][j-1])<q&&j-1>=0){
					p.push_back(make_pair(i,j));
				}
			}
		}
		if(p.size()==0){
			break;
		}
		for(int i=0;i<p.size();i++){
			tmp += a[p[i].first][p[i].second];
			tmp /= p.size();
		}
		for(int i=0;i<p.size();i++){
			a[p[i].first][p[i].second] = tmp;
		}
		answer++;
	} 
	return 0;
}
