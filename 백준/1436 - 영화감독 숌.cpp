#include <iostream>

using namespace std;
int n;
int main(void){
	cin>>n;
	int answer;
	int tmp = 0;
	for(int i=666;i<=9999666;i++){
		int t = i;
		int cnt = 0;
		while(1){
			if(t%10==6){
				cnt++;	
				if(cnt>=3){
					tmp++;
					answer = i;
					break;
				}
			}else{
				cnt = 0;
			}
			t /= 10;
			if(t==0){
				break;
			}
		}
		if(tmp==n){
			break;
		}
	}
	cout<<answer<<"\n";
	return 0;
}
