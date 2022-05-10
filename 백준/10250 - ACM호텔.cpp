#include <iostream>

using namespace std;
int n;
int map[100][100];
void init(){
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			map[i][j] = 0;
		}
	}
}
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		int t = 1;
		bool ls = false;
		int fl,ho;
		init();
		for(int i=0;i<b;i++){
			for(int j=0;j<a;j++){
				if(t==c){
					fl = j;
					ho = i;
					ls = true;
					break;
				}
				t++;
			}
			if(ls==true) break;
		}
		cout<<100*(fl+1)+ho+1<<"\n";
	}
	return 0;
} 
