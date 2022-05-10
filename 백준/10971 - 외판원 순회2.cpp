#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dist[11][11];
vector<int> ve;
int answer = 987654321;
int main(void){
	cin>>n;	
	for(int i=0;i<n;i++){
		ve.push_back(i);
		for(int j=0;j<n;j++){
			cin>>dist[i][j];
		}
	}
	
	do{
		int rslt = 0;
		bool poss = true;
		for(int i=0;i<ve.size();i++){
			cout<<ve[i]<<" ";
		}
		cout<<"\n";

		for(int i=1;i<ve.size();i++){
			if(dist[ve[i-1]][ve[i]]==0){
				poss = false;
				break;
			}
			else{
				rslt += dist[ve[i-1]][ve[i]]; 
			}
		}
		if(!poss||dist[ve.back()][ve.front()]==0) continue;
		rslt += dist[ve.back()][ve.front()];
		answer = min(rslt,answer);
		
	}while(next_permutation(ve.begin(),ve.end()));
	cout<<answer<<"\n";
	return 0;
}
