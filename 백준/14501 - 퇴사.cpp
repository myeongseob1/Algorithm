#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int price[15][2];
int ans;
void go(int iter, int nujeok){
	if(iter>n-1){
		if(ans<nujeok){
			ans = nujeok;
		}
		return;
	}
	
	if(iter+price[iter][0]>n){
		go(iter+1,nujeok);			
	}
	else{
		go(iter+1,nujeok);
		go(iter+price[iter][0],nujeok+price[iter][1]);	
	}
}


int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>price[i][0]>>price[i][1];
	}
	for(int i=0;i<n;i++){
		go(i,0);		
	}

	cout<<ans<<"\n";
	return 0;
}
