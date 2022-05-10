#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[12];
vector<int> op;

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<4;i++){
		int sh;
		cin>>sh;
		for(int j=0;j<sh;j++){
			op.push_back(i);
		}
		
	}
	
	int res_max = -2100000000;
	int res_min = 2100000000;
	
	do{
		int res = a[0];
		for(int i=1;i<n;i++){
			if(op[i-1]==0){
				res += a[i];
			}
			else if(op[i-1]==1){
				res -= a[i];
			}
			else if(op[i-1]==2){
				res *= a[i];
				
			}else if(op[i-1]==3){
				res /= a[i];
			}
		}
		res_max = max(res_max,res);
		res_min = min(res,res_min);
	}while(next_permutation(op.begin(),op.end()));
	
	cout<<res_max<<"\n"<<res_min<<"\n";
	
	return 0;
}
