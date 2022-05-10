#include <iostream>

using namespace std;
int m,n;
int main(void){
	cin>>m>>n;
	for(int i=m;i<=n;i++){
		int cd = 0;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				cd++;
			}
		}
		if(cd==0&&i!=1) cout<<i<<"\n";
	}
	return 0;
}
