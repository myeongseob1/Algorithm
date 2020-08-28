#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;
int a[5][8];

int n;
deque<int> de[5];
vector<pair<int,int> > p;

void spinner(int index,int direction){
	if(direction==1){
		int last = de[index].back();
		de[index].pop_back();
		de[index].push_front(last);
	}
	if(direction == -1){
		int first = de[index].front();
		de[index].pop_front();
		de[index].push_back(first);
	}	
}

int main(void){
	for(int i=1;i<=4;i++){
		for(int j=0;j<8;j++){
			scanf("%1d",&a[i][j]);
			de[i].push_back(a[i][j]);	
		}
	}
	cin>>n;
	for(int i=0;i<n;i++){
		int b,c;
		cin>>b>>c;
		p.push_back(make_pair(b,c));
		int idx = p[0].first;
		int dir = p[0].second;
		while(1){//오른쪽 회전 
			if(idx > 3){
				break;
			}
			if(de[idx][2]==de[idx+1][6]){
				break;
			}
			else{
				int n_idx = idx+1;
				int n_dir = dir*-1;
				p.push_back(make_pair(n_idx,n_dir));
				idx = n_idx;
				dir = n_dir;
			}
		}
		idx = p[0].first;
		dir = p[0].second;
		while(1){
			if(idx<2){
				break;
			}
			if(de[idx][6]==de[idx-1][2]){
				break;
			}
			else{
				int n_idx = idx-1;
				int n_dir = dir*-1;
				p.push_back(make_pair(idx-1,dir*-1));
				idx = n_idx;
				dir = n_dir;
			}
		}
		for(int i=0;i<p.size();i++){
			spinner(p[i].first,p[i].second);
		}
		
		p.clear();		
	}
	int answer =0;
	for(int i=1;i<=4;i++){
		if(de[i][0]==1){
			answer += pow(2,i-1);
		}
	}
	cout<<answer<<"\n";
	return 0;
}
