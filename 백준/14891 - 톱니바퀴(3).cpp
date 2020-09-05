#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
using namespace std;

deque<int> wheel[5];
int k; 
int answer;
void spin(int num,int dir){
	switch(dir){
		case 1:{
			int tmp = wheel[num][wheel[num].size()-1];
			wheel[num].pop_back();
			wheel[num].push_front(tmp);
			break;
		}
			
		
		case -1:{
			int tmp2 = wheel[num][0];
			wheel[num].pop_front();
			wheel[num].push_back(tmp2);
			break;
		}
	
	}
}

void simulation(int num,int dir){
	vector<pair<int,int> > turn_list;
	turn_list.push_back(make_pair(num,dir));
	int x = dir;
	int y = dir;
	for(int i=num;i>=2;i--){
		x = x * (-1);
		if(wheel[i][6]!=wheel[i-1][2]){
			turn_list.push_back(make_pair(i-1,x));
		}
		else break;
	}

	for(int i=num;i<=3;i++){
		y = y*(-1);
		if(wheel[i][2]!=wheel[i+1][6]){
			turn_list.push_back(make_pair(i+1,y));			
		}
		else break;
	}
	for(int i=0;i<turn_list.size();i++){
		spin(turn_list[i].first,turn_list[i].second);
	}
}
int main(void){
	for(int i=1;i<=4;i++){
		for(int j=0;j<8;j++){
			int tmp;
			scanf("%1d",&tmp);
			wheel[i].push_back(tmp);
		}
	}
	cin>>k;
	for(int i=0;i<k;i++){
		int num,dir;
		cin>>num>>dir;
		simulation(num,dir);
	}
	for(int i=1;i<=4;i++){
		if(wheel[i][0]==1){
			answer += pow(2,i-1);
		}
	}
	cout<<answer<<"\n";
	return 0;
}
