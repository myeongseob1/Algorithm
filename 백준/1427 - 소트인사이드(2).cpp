#include <iostream>
#include <algorithm>

using namespace std;
string a;
int main(void){
	cin>>a;
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	cout<<a<<"\n";
	return 0;
}
