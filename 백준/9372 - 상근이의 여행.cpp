#include <iostream>

using namespace std;

int test_case;
int n,m;
int main(void){
	cin>>test_case;
	for(int ii=0;ii<test_case;ii++){
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
		}
		cout<<n-1<<"\n";
	}
	return 0;
}
