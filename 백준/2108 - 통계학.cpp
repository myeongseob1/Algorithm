#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
using namespace std;

int n;
vector<int> ve;
int num[8001];
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		ve.push_back(a);
	}
	if(ve.size()>=1) sort(ve.begin(),ve.end());
	double avg_math = 0;
	for(int i=0;i<ve.size();i++){
		avg_math += ve[i];
		num[ve[i]+4000]++;
	}
	int whet = 0;
	int mx = 0;
	for(int i=0;i<=8000;i++){
		mx = max(mx,num[i]);
	}
	for(int i=0;i<=8000;i++){
		if(mx==num[i]){
			whet++;
		}
	}
	int rslt;
	if(whet==1){
		for(int i=0;i<=8000;i++){
			if(mx==num[i]){
				rslt = i;
				break;
			}
		}
	}
	else if(whet>=2){
		bool flag = false;
		for(int i=0;i<=8000;i++){
			if(mx==num[i]&&flag==false){
				flag = true;
			}
			else if(mx==num[i]&&flag==true){
				rslt = i;
				break;
			}
		}		
	}
	avg_math = round(avg_math/ve.size());
	cout<<avg_math<<"\n"<<ve[ve.size()/2]<<"\n"<<rslt-4000<<"\n"<<ve[ve.size()-1]-ve[0]<<"\n";
	return 0;
}
