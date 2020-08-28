#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int iter,result;
	int max=-1000000000,min=1000000000,sym[4];
	cin>>iter;
	vector<int> num(iter),symbol;
	for(int i=0;i<iter;i++){
		cin>>num[i];
	}

	for(int i=0;i<4;i++){
		cin>>sym[i];
	}
	for(int i=0;i<4;i++){
		if(sym[i]!=0){
			for(int j=0;j<sym[i];j++){
				symbol.push_back(i);		
			}
		}
	}
	do{
		result = num[0];
		for(int i=0;i<symbol.size();i++){
			if(symbol[i]==0){
				result += num[i+1];
			}
			else if(symbol[i]==1){
				result -= num[i+1];
			}
			else if(symbol[i]==2){
				result *= num[i+1];
			}
			else if(symbol[i]==3){
				result /= num[i+1];
			}	
		}
		if(max<result){
			max = result;
		}
		if(min>result){
			min = result;
		}
	}while(next_permutation(symbol.begin(),symbol.end()));
	cout<<max<<"\n"<<min<<"\n"; 
	return 0;
}
