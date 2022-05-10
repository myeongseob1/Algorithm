#include <iostream>
#include <vector>
using namespace std;

int ve[100001];
int n,m;
int main(void){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		ve[i] = ve[i-1] + t;
	}
	for(int i=0;i<m;i++){
		int a,b,answer = 0;
		cin>>a>>b;
		answer = ve[b]-ve[a-1];
		cout<<answer<<"\n";
	}
	return 0;
}
