#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int a[22][22];
int answer = 2100000000;
int sum[6];
void decision(int x,int y, int d1, int d2, int r, int c){
	if(r<x+d1&&c<=y&&!(r>=x&&c>=y-(r-x))){
		sum[1] += a[r][c];
	}
	else if(r<=x+d2&&c>y&&!(r>x&&c<=y+(r-x))){
		sum[2] += a[r][c];	
	} 
	else if(r>=x+d1&&r<=n&&c>=1&&c<y-d1+d2&&!(r<x+d1+d2&&c>=(y-d1+d2-(x+d1+d2-r)))){
		sum[3] += a[r][c];
	}
	else if(r>x+d2&&r<=n&&c>=y-d1+d2&&!(r<=x+d1+d2&&c<=(y-d1+d2+(x+d1+d2-r)))&&c<=n){
		sum[4] += a[r][c];
	}
	else{
		sum[5] += a[r][c];
	}
}
void init(){
	for(int i=0;i<6;i++){
		sum[i] = 0;
	}
}


int main(void){
	cin>>n;
	int t;
	int x,y,d1,d2,r,c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];	
		}
	}
	for(int x=1;x<=n-2;x++){
		for(int y=1;y<=n-1;y++){

			for(int d1=1;d1<=n;d1++){
				for(int d2=1;d2<=n;d2++){
					if(x+d1+d2>n||y+d2>n||y-d1<1) continue;
					init();
					for(int i=1;i<=n;i++){
						for(int j=1;j<=n;j++){
							decision(x,y,d1,d2,i,j);
						}
					}
					sort(sum+1,sum+6);
					int aa = sum[5] - sum[1];
					if(answer>aa){
						answer = aa;
					}


				}
			}
		}
	}
	
	cout<<answer<<"\n";
	return 0;
}
