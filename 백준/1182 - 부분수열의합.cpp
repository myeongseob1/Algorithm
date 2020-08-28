#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int sum,iter,hwet;
int num[20];
void go(int nujeok,int index){
	if(index>iter){
		return;
	}
	if(nujeok+num[index] == sum){
		if(index==iter) return;
		hwet++;
	}

	go(nujeok+num[index],index+1);
	go(nujeok,index+1);
		
}
int main(void){
	cin>>iter>>sum;
	for(int i=0;i<iter;i++){
		cin>>num[i];
	}
	go(0,0);
	cout<<hwet<<'\n'; 
	return 0;
}
