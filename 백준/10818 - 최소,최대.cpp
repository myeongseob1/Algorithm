#include <iostream>;

using namespace std;

int n;

int mn = 1000001;
int mx = -1000001;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		mn = min(t,mn);
		mx = max(t,mx);
	}
	cout<<mn<<" "<<mx<<"\n";
	return 0;
}
