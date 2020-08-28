#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> oper;
int num[11],iter,result,maxx=-1000000000,minx=1000000000;
void go(int i, int sum,int plus,int minus,int mul, int div){
	if(i>=iter){
		if(maxx<sum){
			maxx = sum;
		}
		if(minx>sum){
			minx = sum;
		}
		return;
	}
	if(plus<=0&&minus<=0&&mul<=0&&div<=0){
		return;
	}
	if(plus>0){
		go(i+1,sum+num[i],plus-1,minus,mul,div);	
	}
	if(minus>0){
		go(i+1,sum-num[i],plus,minus-1,mul,div);	
	}
	if(mul>0){
		go(i+1,sum*num[i],plus,minus,mul-1,div);		
	}
	if(div>0){
		go(i+1,sum/num[i],plus,minus,mul,div-1);		
	}

}

int main(void){
	int cal[4];
	cin>>iter;
	for(int i=0;i<iter;i++){
		cin>>num[i];
	}
	for(int i=0;i<4;i++){
		cin>>cal[i];
	}	
	go(1,num[0],cal[0],cal[1],cal[2],cal[3]);
	cout<<maxx<<"\n"<<minx<<"\n";
	return 0;
}
