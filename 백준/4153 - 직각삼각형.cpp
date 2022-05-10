#include <iostream>

using namespace std;

int main(void){
	while(1){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==0&&b==0&&c==0){
			break;
		}
		if(a*a+b*b==c*c||a*a==b*b+c*c||b*b==a*a+c*c){
			cout<<"right"<<"\n";
		}else{
			cout<<"wrong"<<"\n";
		}
	}
	
	return 0;
}
