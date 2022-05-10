#include <iostream>
#include <vector>
using namespace std;
int m,n,x,y;
pair<int,int> pr;
int answer;

int gcd(int a,int b){
	while(b!=0){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a,int b){
	return a*b/gcd(a,b);
}

int main(void){

	ios_base::sync_with_stdio(0);
    cin.tie(0); 
	cout.tie(0);//실행속도 향상

	int iter;
	cin>>iter;
	for(int i=0;i<iter;i++){
		cin>>m>>n>>x>>y;
		int maxYear = lcm(m,n);
		while(1){
			if(x > maxYear||(x-1)%n==y-1){
				break;
			}
			x += m;
			
		}
		if(x > maxYear){
			cout<<-1<<"\n";
		}else{
			cout<<x<<"\n";
		}
	}
	return 0;
}
