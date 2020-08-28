#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int a[20][20];
int n;
vector<int> team1;
vector<int> team2;

int main(void){
	cin>>n;
	vector<int> tmp(n);
	int ans = 100000,tmp1=0,tmp2=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
		tmp[i] = 1;
	}
	for(int i=0;i<n/2;i++){
		tmp[i] = 0;
	}
	do{
		for(int i=0;i<n;i++){
			if(tmp[i]==0){
				team1.push_back(i);
			}
			if(tmp[i]==1){
				team2.push_back(i);
			}
		}
		for(int i=0;i<n/2;i++){
			for(int j=i;j<n/2;j++){
				tmp1 += a[team1[i]][team1[j]];
				tmp1 += a[team1[j]][team1[i]];
				tmp2 += a[team2[i]][team2[j]];
				tmp2 += a[team2[j]][team2[i]];
			}
		}
		if(tmp1-tmp2>=0&&ans>tmp1-tmp2){
			ans = tmp1 - tmp2;			
		}
		else if(tmp1-tmp2<0&&ans>tmp2-tmp1){
			ans = tmp2 - tmp1;
		}
		team1.clear();
		team2.clear();
		tmp1 = 0;
		tmp2 = 0;
	}while(next_permutation(tmp.begin(),tmp.end()));
	
	cout<<ans<<"\n";
	return 0;
}
