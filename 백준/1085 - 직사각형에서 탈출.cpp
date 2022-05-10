#include <iostream>
#include <cmath>
using namespace std;
int x,y,w,h;
int main(void){
	cin>>x>>y>>w>>h;
	int answer = 987654431;
	answer = min(abs(x-w),abs(y-h));
	answer = min(answer,x);
	answer = min(answer,y);
	cout<<answer<<"\n";
	return 0;
}
