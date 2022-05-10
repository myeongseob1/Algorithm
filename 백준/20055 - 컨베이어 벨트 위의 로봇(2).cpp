#include <iostream>
#include <deque>

using namespace std;
int n,k;
deque<bool> robot;
deque<int> hp;

bool end_game(){
	int num=0;
	for(int i=0;i<hp.size();i++){
		if(hp[i]==0){
			num++;
		}
	}
	if(num>=k){
		return false;
	}
	return true;
}

int main(void){
	cin>>n>>k;
	for(int i=0;i<2*n;i++){
		int tmp;
		cin>>tmp;
		hp.push_back(tmp);
		robot.push_back(false);
	}
	int stage = 1;
	while(1){
		bool ro = robot[robot.size()-1];
		robot.pop_back();
		robot.push_front(ro);
		int h = hp[hp.size()-1];
		hp.pop_back();
		hp.push_front(h);
		if(robot[n-1]==true){
			robot[n-1] = false;
		}
		for(int i=robot.size()-2;i>=0;i--){
			if(robot[i]==true&&robot[i+1]==false){
				if(hp[i+1]>0){
					hp[i+1]--;
					robot[i+1] = true;
					robot[i] = false;
					
				}
			}
		}
		if(robot[n-1]==true){
			robot[n-1] = false;
		}
		if(robot[0]==false&&hp[0]>0){
			robot[0] = true;
			hp[0]--;
		}
		if(end_game()==false){
			break;
		}
		stage++;
	}
	cout<<stage<<"\n";
	return 0;
}
