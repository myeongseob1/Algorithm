#include <iostream>
#include <vector>

using namespace std;
int h,w;
vector<int> ve;
int answer;
int main(void){
	cin>>h>>w;
	for(int i=0;i<w;i++){
		int t;
		cin>>t;
		ve.push_back(t);
	}
	for(int i=1;i<ve.size()-1;i++){
		int max_left = 0;
		int max_right = 0;
		for(int j=0;j<i;j++){
			max_left = max(ve[j],max_left);
		}
		for(int j=i+1;j<ve.size();j++){
			max_right = max(ve[j],max_right);
		}
		int min_rain = min(max_left,max_right);
		if(min_rain-ve[i]>0){
			answer += min_rain-ve[i];
		}
	}
	cout<<answer<<"\n";
	return 0;
}
