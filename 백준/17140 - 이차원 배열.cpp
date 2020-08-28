#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r,c,k;
int a[101][101];
int tmp[101][101];
int now_r,now_c;

void init(){
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			tmp[i][j] = 0;
		}
	}
}

void r_op(){
	int b[101];
	init();
	for(int i=1;i<=now_r;i++){
		vector<pair<int,int> > p;
		for(int j=0;j<101;j++){
			b[j]=0;
		}
		for(int j=1;j<=now_c;j++){
			b[a[i][j]]++;	
		}
		for(int j=1;j<101;j++){
			if(b[j] !=0){
				p.push_back(make_pair(b[j],j));
			}
		}
		if(now_c<2*p.size()){
			now_c = 2*p.size();
		}
		sort(p.begin(),p.end());
		for(int j=1;j<2*p.size()+1;j=j+2){
			tmp[i][j] = p[j/2].second;
			tmp[i][j+1] = p[j/2].first;
		}
	}
	copy(&tmp[0][0],&tmp[100][100],&a[0][0]);
}

void c_op(){
	int b[101];
	init();
	for(int i=1;i<=now_c;i++){
		vector<pair<int,int> > p;
		for(int j=0;j<101;j++){
			b[j]=0;
		}
		for(int j=1;j<=now_c;j++){
			b[a[j][i]]++;	
		}
		for(int j=1;j<101;j++){
			if(b[j] !=0){
				p.push_back(make_pair(b[j],j));
			}
		}
		if(now_r<2*p.size()){
			now_r = 2*p.size();
		}
		sort(p.begin(),p.end());
		for(int j=1;j<2*p.size()+1;j=j+2){
			tmp[j][i] = p[j/2].second;
			tmp[j+1][i] = p[j/2].first;
		}
	}
	copy(&tmp[0][0],&tmp[100][100],&a[0][0]);
}


int main(void){
	int num=0;
	cin>>r>>c>>k;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	now_r = 3;
	now_c = 3;
	
	while(1){
		if(a[r][c]==k||num>100){
			break;
		}

		if(now_r>=now_c){
			r_op();
			num++;
		}
		else{
			c_op();
			num++;
		}
	}
	if(num==101){
		num = -1;
	}

	cout<<num<<"\n";
	return 0;
}
