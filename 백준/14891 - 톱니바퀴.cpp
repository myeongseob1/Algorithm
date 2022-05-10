#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
using namespace std;

deque<int> wheel[4];
int n;
int answer;
void wheel_a(int wheel_num,int dir){
	if(dir == 1)
	{
		int tmp = wheel[wheel_num][wheel[wheel_num].size()-1];
		wheel[wheel_num].pop_back();
		wheel[wheel_num].push_front(tmp);
	}
	else if(dir == -1)
	{
		int tmp = wheel[wheel_num][0];
		wheel[wheel_num].pop_front();
		wheel[wheel_num].push_back(tmp);
	}
}
int main(void){	
	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++){
			int a;
			scanf("%1d",&a);
			wheel[i].push_back(a);
		}
	}
	cin>>n;
	for(int i=0; i<n; i++){
		int a,b;
		cin>>a>>b;
		vector<pair<int,int> > turn_list;
		int iter2 = -1 * b;

		for(int i=a-1;i>=1;i--){
			if(wheel[i-1][2]!=wheel[i][6]){
				turn_list.push_back(make_pair(i-1,iter2));
				iter2 *= -1;
			}else{
				break;
			}
		}
		int iter = -1 * b;
		for(int i=a-1;i<3;i++){
			if(wheel[i][2]!=wheel[i+1][6]){
				turn_list.push_back(make_pair(i+1,iter));
				iter *= -1;
			}else{
				break;
			}
		}
		wheel_a(a-1,b);
		for(int i=0;i<turn_list.size();i++){
			wheel_a(turn_list[i].first,turn_list[i].second);
			
		}
	}
	for(int i=0;i<4;i++){
		if(wheel[i][0]==1){
			answer += pow(2,i);
		}
	}
	cout<<answer<<"\n";
	return 0;
}
