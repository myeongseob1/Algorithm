#include <iostream>
#include <cmath>
using namespace std;
long long n;
long long r = 1;
string inp;
long long ans;
int main(void){
	cin>>n;
	cin>>inp;
	for(int i=0;i<inp.size();i++){
		ans = (ans+(inp[i]-'a' + 1)*r)%1234567891;
		r = (r*31) % 1234567891;
	}
	cout<<ans<<"\n";
	return 0;
}
