#include <iostream>
#include <algorithm>

using namespace std;
int go(int count, int sum,int goal){
	if(sum>goal){
		return 0;
	}
	if(sum == goal){
		return 1;
	}
	int now =0;
	for(int i=1;i<=3;i++){
		now += go(count+1,sum+i,goal);
	}
	return now;
} 


int main(void){
	int iter,a[100];
	cin>>iter;
	for(int i=0;i<iter;i++){
		cin>>a[i];
	}
	for(int i=0;i<iter;i++){
		cout<<go(0,0,a[i])<<"\n";
	}
	
	return 0;
}
