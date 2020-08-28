#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[22][22];
int d[22][22];
int sum[6];
int answer = 2147000000;
int x,y,d1,d2;
int main(void){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int x=1;x<=n-2;x++){
		for(int y=2;y<=n-1;y++){
			if((x==1&&y==1)){
				continue;
			}

			for(int d1=1;d1<=n-x-1&&d1<=y-1;d1++){
				for(int d2=1;d2<=n-x-1&&d2<=n-y;d2++){
					if((x+d1+d2>n)||(y-d1<1)||(y+d2>n)){
						continue;
					}

					for(int i=1;i<x+d1;i++){
						for(int j=1;j<=y;j++){
							if(d[i][j]!= 5) d[i][j] = 1;
						}

					}
					for(int i=1;i<=x+d2;i++){
						for(int j=y+1;j<=n;j++){
							if(d[i][j]!= 5) d[i][j] = 2;
						}
					}
					for(int i=x+d1;i<=n;i++){
						for(int j=1;j<y-d1+d2;j++){
							if(d[i][j]!= 5) d[i][j] = 3;
						}
					}
					for(int i=x+d2+1;i<=n;i++){
						for(int j=y-d1+d2;j<=n;j++){
							if(d[i][j]!= 5) d[i][j] = 4;
						}
					}
										for(int i=0;i<=d1;i++){
						d[x+i][y-i] = 5;
						d[x+d2+i][y+d2-i] = 5;
					}
					for(int i=0;i<=d2;i++){
						d[x+i][y+i] = 5;
						d[x+d1+i][y-d1+i] = 5;
					}
	
					for(int i=x+1;i<=x+d1+d2-1;i++){
						int count = 0;
						for(int j=1;j<=n;j++){
							if(d[i][j] == 5){
								count++;
							}
							if(count==1){
								d[i][j] = 5;
							}
							if(count==2){
								break;
							}
						}
					}

					for(int i=1;i<=n;i++){
						for(int j=1;j<=n;j++){
							sum[d[i][j]] += a[i][j];
						}
					}
					sort(sum+1,sum+6);
					int a = sum[5] - sum[1];
					if(answer>a){
						answer = a;
					}
					for(int i=0;i<=5;i++){
						sum[i]=0;
					}
				}
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}
