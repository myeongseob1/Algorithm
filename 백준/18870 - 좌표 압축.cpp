#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point{
	int num,ans,idx;
};


vector<point> ve;
int n;

bool compare1(point a,point b){
	return a.num < b.num;
}

bool compare2(point a,point b){
	return a.idx < b.idx;
}

int main(void){
	
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);	
	
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		point tmp;
		tmp.num = t;
		tmp.idx = i;
		tmp.ans = 0;
		ve.push_back(tmp);
	}	
	sort(ve.begin(),ve.end(),compare1);
	int t = 0;
	for(int i=1;i<ve.size();i++){
		if(ve[i-1].num < ve[i].num){
			t++;
		}
		ve[i].ans = t;
	}	
	sort(ve.begin(),ve.end(),compare2);
	for(int i=0;i<ve.size();i++){
		cout<<ve[i].ans<<" ";
	}
	cout<<"\n";
	return 0;
}
