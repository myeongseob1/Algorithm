#include <iostream>

using namespace std;

string wb[8] = 
{
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW"
};
string bw[8] = 
{
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB"
};
string inp[50];
int n,m;
int ans = 987654321;
int main(void){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>inp[i];
	}
	for(int i=0;i<=n-8;i++){
		for(int j=0;j<=m-8;j++){
			int ans1 = 0;
			int ans2 = 0;
			for(int ii=i;ii<i+8;ii++){
				for(int jj=j;jj<j+8;jj++){
					if(wb[ii-i][jj-j]!=inp[ii][jj]){
						ans1++;
					}
					if(bw[ii-i][jj-j]!=inp[ii][jj]){
						ans2++;
					}

				}
			}
			ans = min(ans,ans1);
			ans = min(ans,ans2);
		}
	} 
	cout<<ans<<"\n";
	return 0;
}
