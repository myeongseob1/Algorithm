#include <iostream>
#include <algorithm>
 
using namespace std;

int main(void)
{
	int E,S,M;
	
	cin>>E>>S>>M;
	for(int i=1;i<7981;i++){
		if(E==15){
			E=0;
		}
		if(S==28){
			S=0;
		}
		if(M==19){
			M=0;
		}
		if(i%15==E && i%28 ==S && i%19 ==M ){
			cout<<i<<endl;
			return 0;
		} 
		 
	}
	return 0;
}
