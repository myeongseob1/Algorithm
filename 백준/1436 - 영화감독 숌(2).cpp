#include <iostream>

using namespace std;
int answer,n;
bool bool_shom(int n){
	bool flag = false;
	int cnt = 0;
	while(n!=0){
		if(n%10==6&&flag==false){
			cnt = 1;
			flag = true;
		}
		else if(n%10==6&&flag==true){
			cnt++;
			flag = true;
		}
		if(n%10!=6){
			flag = false;
		}
		if(cnt>=3){
			return true;
		}
		n /= 10;
	}
	return false;
}
int main(void){
	cin>>n;
	int answer;
	int rslt = 0;
	bool_shom(6666);
	for(int i=666;i<=10000666;i++){
		if(bool_shom(i)){
			rslt++;
		}
		if(rslt==n){
			answer = i;
			break;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
