#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int iter,num[11],cal[4],result,max=-1000000000,min=1000000000;
	vector<int> oper,tmp;
	cin>>iter;
	for(int i=0;i<iter;i++){
		cin>>num[i];
	}
	for(int i=0;i<iter-1;i++){
		tmp.push_back(0);
	}
	for(int i=0;i<4;i++){
		cin>>cal[i];
		if(cal[i]!=0){
			for(int j=0;j<cal[i];j++){
				oper.push_back(i);
			}
		}
	}
	for(int i=iter-1;i<oper.size();i++){
		tmp.push_back(1);
	}
	do{
		result = num[0];
		int p=0;
		for(int i=0;i<oper.size();i++){
			if(tmp[i]==0){
				p++;
				if(oper[i]==0){
					result += num[p];	
				}
				else if(oper[i]==1){
					result -= num[p];
				}
				else if(oper[i]==2){
					result *= num[p];
				}
				else if(oper[i]==3){
					result /= num[p];
				}
			}
		}
		if(max<result){
			max = result;
		}
		if(min>result){
			min =result;
		}
	}while(next_permutation(oper.begin(),oper.end()));
	cout<<max<<"\n"<<min<<"\n";
	return 0;
}
