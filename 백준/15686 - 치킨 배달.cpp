#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int a[51][51];
vector<pair<int,int> > home,chicken,copy_ch;
int answer;
vector<pair<int,int> > ve;
int minus_abs(int a,int b){
	if(a-b>0) return a-b;
	else return b-a;	
}


void chick_distance(){
	for(int i=0;i<home.size();i++){
		int p,min = 5000;
		for(int j=0;j<ve.size();j++){
			p = minus_abs(home[i].first,ve[j].first) + minus_abs(home[i].second,ve[j].second);	
			if(min>p) min = p;
		}
		answer += min;
	}
}


int main(void){
	cin>>n>>m;
	int max = 100000;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			if(a[i][j]==1){
				home.push_back(make_pair(i,j));
			}	
			if(a[i][j]==2){
				chicken.push_back(make_pair(i,j));
			}
		}
	}
	if(m==chicken.size()){
		ve.assign(chicken.begin(),chicken.end());
		chick_distance();
		max = answer;		
	}
	else if(m<chicken.size()){
		vector<int> tmp(chicken.size());
		for(int i=m;i<chicken.size();i++){
			tmp[i] = 1;
		}

		do{
			copy_ch.assign(chicken.begin(),chicken.end());
			for(int i=0;i<tmp.size();i++){
				if(tmp[i]==0){
					ve.push_back(copy_ch[i]);
				}
			}
			chick_distance();				
			copy_ch.clear();
			ve.clear();
			if(max>answer){
				max = answer;
			}
			answer = 0;
		}while(next_permutation(tmp.begin(),tmp.end()));
	}
	cout<<max<<"\n";
	return 0;	
}
