#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> op;
vector<int> num;
int n;

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		num.push_back(a);
	}
	for(int i=0;i<4;i++){
		int t;
		cin>>t;
		for(int j=0;j<t;j++){
			op.push_back(i);
		}
	}
	int max_answer = -2147000000;
	int min_answer = 2147000000;
	do{
		int rslt = num[0];
		for(int i=1;i<num.size();i++){
			if(op[i-1]==0){
				rslt += num[i];
			}
			else if(op[i-1]==1){
				rslt -= num[i];
			}
			else if(op[i-1]==2){
				rslt *= num[i];
			}
			else if(op[i-1]==3){
				rslt /= num[i];
			}
		}
		max_answer = max(max_answer,rslt);
		min_answer = min(min_answer,rslt);
	}while(next_permutation(op.begin(),op.end()));
	cout<<max_answer<<"\n"<<min_answer<<"\n";
	return 0;
}
