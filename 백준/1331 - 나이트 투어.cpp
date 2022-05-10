#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visit[6][6];
int dx[8] = {2,2,1,1,-1,-1,-2,-2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};
vector<pair<int,int> > ve;
string answer = "Valid";
pair<int,int> retind(string a){
	if(a=="A1"){
		return make_pair(0,5);
	}
	else if(a=="A2"){
		return make_pair(0,4);		
	}
	else if(a=="A3"){
		return make_pair(0,3);
	}
	else if(a=="A4"){
		return make_pair(0,2);
	}
	else if(a=="A5"){
		return make_pair(0,1);
	}
	else if(a=="A6"){
		return make_pair(0,0);
	}
	else if(a=="B1"){
		return make_pair(1,5);
	}
	else if(a=="B2"){
		return make_pair(1,4);		
	}
	else if(a=="B3"){
		return make_pair(1,3);
	}
	else if(a=="B4"){
		return make_pair(1,2);
	}
	else if(a=="B5"){
		return make_pair(1,1);
	}
	else if(a=="B6"){
		return make_pair(1,0);
	}
	else if(a=="C1"){
		return make_pair(2,5);
	}
	else if(a=="C2"){
		return make_pair(2,4);		
	}
	else if(a=="C3"){
		return make_pair(2,3);
	}
	else if(a=="C4"){
		return make_pair(2,2);
	}
	else if(a=="C5"){
		return make_pair(2,1);
	}
	else if(a=="C6"){
		return make_pair(2,0);
	}
	else if(a=="D1"){
		return make_pair(3,5);
	}
	else if(a=="D2"){
		return make_pair(3,4);		
	}
	else if(a=="D3"){
		return make_pair(3,3);
	}
	else if(a=="D4"){
		return make_pair(3,2);
	}
	else if(a=="D5"){
		return make_pair(3,1);
	}
	else if(a=="D6"){
		return make_pair(3,0);
	}
	else if(a=="E1"){
		return make_pair(4,5);
	}
	else if(a=="E2"){
		return make_pair(4,4);		
	}
	else if(a=="E3"){
		return make_pair(4,3);
	}
	else if(a=="E4"){
		return make_pair(4,2);
	}
	else if(a=="E5"){
		return make_pair(4,1);
	}
	else if(a=="E6"){
		return make_pair(4,0);
	}
	else if(a=="F1"){
		return make_pair(5,5);
	}
	else if(a=="F2"){
		return make_pair(5,4);		
	}
	else if(a=="F3"){
		return make_pair(5,3);
	}
	else if(a=="F4"){
		return make_pair(5,2);
	}
	else if(a=="F5"){
		return make_pair(5,1);
	}
	else if(a=="F6"){
		return make_pair(5,0);
	}

}
int main(void){
	for(int i=0;i<36;i++){
		string t;
		cin>>t;
		ve.push_back(make_pair(retind(t).first,retind(t).second));		
	}
	visit[ve[0].first][ve[0].second] = true;
	for(int i=1;i<ve.size();i++){
		int x = ve[i-1].first;
		int y = ve[i-1].second;
		bool flag = false;
		for(int k=0;k<8;k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(nx<0){
				nx = 6 + nx; 
			}
			if(nx>=6){
				nx = 6 - nx;
			}
			if(ny<0){
				ny = 6 + ny; 
			}
			if(ny>=6){
				ny = 6 - ny;
			}

			if(visit[nx][ny]==false){
				if(nx==ve[i].first&&ny==ve[i].second){
					flag = true;
					visit[nx][ny] = true;
					break;
				}
			}
		}

		if(flag==false){
			answer = "Invalid";
			break;
		}
	}
	
	int lx = ve[ve.size()-1].first;
	int ly = ve[ve.size()-1].second;
	bool fl = false;
	for(int k=0;k<8;k++){
		int sx = lx+ dx[k];
		int sy = ly + dy[k];
		if(sx<0){
			sx = 6 + sx; 
		}
		if(sx>=6){
			sx = 6 - sx;
		}
		if(sy<0){
			sy = 6 + sy; 
		}
		if(sy>=6){
			sy = 6 - sy;
		}
		if(sx==ve[0].first&&sy==ve[0].second){
			fl = true;	
			break;
		}
	}
	if(fl==false){
		answer = "Invalid";
	}
	
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(visit[i][j]==false){
				answer = "Invalid";
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}
