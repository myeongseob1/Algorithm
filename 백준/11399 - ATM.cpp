#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,a[1001];
int order[1001];
int answer;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			answer +=a[j];
		}
	}
	cout<<answer<<"\n";
	return 0;
}
