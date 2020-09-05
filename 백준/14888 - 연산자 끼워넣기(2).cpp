#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;
int n;
int a[12];
int answer = -2147000000;
int answer2 = 2147000000;
vector<int> op;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<4;i++){
		int a;
		cin>>a;
		for(int j=0;j<a;j++){
			op.push_back(i);
		}
	}
	do{
		int result = a[0];
		for(int i=0;i<n-1;i++){
			switch(op[i]){
				case 0:
					result = result + a[i+1];
					break;
				case 1:
					result = result - a[i+1];
					break;
				case 2:
					result = result * a[i+1];
					break;
				case 3:
					result = result / a[i+1];
					break;
			}
		}
		answer = max(answer,result);
		answer2 = min(answer2,result);
	}while(next_permutation(op.begin(),op.end()));	
	cout<<answer<<"\n";
	cout<<answer2<<"\n";
	return 0;
}
