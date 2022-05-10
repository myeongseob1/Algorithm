#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
vector<int> ve;
int answer;
int main(void){
	cin>>n;
	while(1){
		if(n==0){
			break;
		}
		ve.push_back(n%10);
		n = n/10;
	}
	sort(ve.begin(),ve.end());
	for(int i=0;i<ve.size();i++){
		answer += ve[i] * pow(10,i);
	}
	cout<<answer<<"\n";
	return 0;
}
