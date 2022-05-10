#include <iostream>
#include <deque>

using namespace std;
int n,k;
deque<int> a;
deque<bool> robot;

void rotate(){
	bool tmp = robot[robot.size()-1];
	robot.pop_back();
	robot.push_front(tmp);
	int tmp2 = a[a.size()-1];
	a.pop_back();
	a.push_front(tmp2);
}

void move(){
	for(int i=robot.size()-1;i>=1;i--){
		if(robot[i]==false&&robot[i-1]==true){
			if(a[i] > 0){
				robot[i] = true;
				robot[i-1] = false;
				a[i]--;	
			}
		}
	}
}

void enter(){
	if(robot[0]==false){
		if(a[0]>0){
			a[0]--;
			robot[0] = true;
		}
	}
}
int main(void){
	cin>>n>>k;
	for(int i=0;i<2*n;i++){
		int t;
		cin>>t;
		a.push_back(t);
		robot.push_back(false);
	}
	int grade =1;
	while(1){
		rotate();
		if(robot[n-1]==true){
			robot[n-1] = false;
		}
		move();
		if(robot[n-1]==true){
			robot[n-1] = false;
		}
		enter();
		grade++;
		
		int cnt=0;
		for(int i=0;i<2*n;i++){
			if(a[i]==0){
				cnt++;
			}
		}
		if(cnt>=k){
			break;
		}
	}
	cout<<grade-1<<"\n";
	return 0;
} 
