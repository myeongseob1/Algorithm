#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

using namespace std;

deque<int> wheel[1001];
int answer;

void rolling(int num,int dir){
	if(dir==1){
		int tmp = wheel[num].back();
		wheel[num].pop_back();
		wheel[num].push_front(tmp);
	}
	else if(dir==-1){
		int tmp = wheel[num].front();
		wheel[num].pop_front();
		wheel[num].push_back(tmp);
	}
}


int main(void){
	int p;
	cin>>p;
	for(int ii=0;ii<p;ii++){
		string inp;
		cin>>inp;
		for(int jj=0;jj<inp.size();jj++){
			wheel[ii].push_back((int)(inp[jj]-'0'));
		}
	}	
	int n;
	cin>>n;
	for(int ii=0;ii<n;ii++){
		int a,b;
		cin>>a>>b;
		a--;
		vector<pair<int,int> > roll;
		roll.push_back(make_pair(a,b));
		int t = b;
		for(int i=a;i<p-1;i++){
			if(wheel[i][2]!=wheel[i+1][6]){
				t *= -1;
				roll.push_back(make_pair(i+1,t));
			}
			else{
				break;
			}
		}
		t = b;
		for(int i=a;i>=1;i--){
			if(wheel[i][6]!=wheel[i-1][2]){
				t *= -1;
				roll.push_back(make_pair(i-1,t));
			}
			else{
				break;
			}			
		}
		for(int i=0;i<roll.size();i++){
			rolling(roll[i].first,roll[i].second);
		}
	}
	for(int i=0;i<p;i++){
		if(wheel[i][0]==1){
			answer ++;
		}
	}
	cout<<answer<<"\n";	
	return 0;
}
