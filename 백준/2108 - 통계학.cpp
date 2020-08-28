#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int> ve;
int a[8002];//0~4000:-4000 ~ 0 & 1~4000 4001~8001
int main(void){
	int n;
	int max=-10000;
	vector<int> freq;
	int freq_max = 0;
	int sum =0;
	cin>>n; 
	double average;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		ve.push_back(t);
		a[t+4000]++;
	}
	sort(ve.begin(),ve.end());
	for(int i=0;i<ve.size();i++){
		sum += ve[i];
	}
	for(int i=0;i<8001;i++){
		if(a[i]!=0&&freq_max<a[i]){
			freq_max = a[i];
		}
	}
	for(int i=0;i<8001;i++){
		if(a[i]==freq_max){
			freq.push_back(i-4000);
		}
	}
	sort(freq.begin(),freq.end());
	average = floor((double)sum/n+0.5);
	if(freq.size()==1){
		cout<<(int)average<<"\n"<<ve[n/2]<<"\n"<<freq[0]<<"\n"<<ve[n-1]-ve[0]<<"\n";	
	}
	else{
		cout<<(int)average<<"\n"<<ve[n/2]<<"\n"<<freq[1]<<"\n"<<ve[n-1]-ve[0]<<"\n";	
	}
	return 0;
}
