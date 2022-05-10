#include <iostream>

using namespace std;

int cnt_sort[10001];
int n;
int main(void){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		cnt_sort[a]++;
	}
	for(int i=1;i<10001;i++){
		for(int j=0;j<cnt_sort[i];j++){
			cout<<i<<"\n";
		}
	}
	return 0;
}
