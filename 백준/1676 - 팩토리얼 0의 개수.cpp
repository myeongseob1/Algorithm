#include <iostream>

using namespace std;
int n;
int main(void){
	cin>>n;
	int cnt = 0;
	while(n>=5){
		cnt += n/5;
		n /= 5;
	}
	cout<<cnt<<"\n";
	return 0;
}
