#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main(void){
	int iter,price[10][10],num[10],min = 1000000000,result=0,flag =0;
	cin>>iter;
	for(int i=0;i<iter;i++){
		num[i] = i;
		for(int j=0;j<iter;j++){
			cin>>price[i][j];
		}
	}
	
	do{
		for(int i=0;i<iter-1;i++){
			if(price[num[i]][num[i+1]]==0){
				flag = -1;
			}
			result += price[num[i]][num[i+1]];
		}
		if(price[num[iter-1]][num[0]]==0){
			flag = -1;
		}
		result += price[num[iter-1]][num[0]];
		if(flag == -1){
			flag =0;
			result = 0;
			continue;
		}
		if(result<min){
			min = result;
		}
		result = 0;
	}while(next_permutation(num+1,num+iter));
	cout<<min<<'\n';
	return 0;
}
