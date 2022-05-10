#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct axis{
	int real,ans,idx;
};

int n;
vector<axis> zip;

bool compare(axis a,axis b){
	return a.real<b.real;
}

bool compare2(axis a,axis b){
	return a.idx<b.idx;
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		axis tmp;
		tmp.real = a;
		tmp.ans = 0;
		tmp.idx = i;
		zip.push_back(tmp);
	}
	sort(zip.begin(),zip.end(),compare);
	for(int i=1;i<zip.size();i++){
		if(zip[i-1].real==zip[i].real){
			zip[i].ans = zip[i-1].ans;
		}
		if(zip[i-1].real<zip[i].real){
			zip[i].ans = zip[i-1].ans + 1;
		}
	}
	sort(zip.begin(),zip.end(),compare2);
	for(int i=0;i<zip.size();i++){
		cout<<zip[i].ans<<" ";
	}
	return 0;
}
