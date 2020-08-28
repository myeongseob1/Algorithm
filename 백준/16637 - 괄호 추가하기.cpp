#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> op2;
vector<int> op1;
int answer=-2147000000;
int calculate(int a1,int a2, int b){
	switch(b){
		case 11:
			return a1+a2;
		case 12:
			return a1-a2;
		case 13:
			return a1*a2;
		case 14:
			return a1/a2;			
	}
}


void dfs(int iter,int val){
	if(iter == n/2){
		if(answer<val){
			answer = val;		
		}
		return;
	}
	int num = calculate(val,op1[iter+1],op2[iter]);
	dfs(iter+1,num);
	if(iter+1<n/2){
		int num2 = calculate(op1[iter+1],op1[iter+2],op2[iter+1]);
		dfs(iter+2,calculate(val,num2,op2[iter]));
	}
}

int main(void){
	char tmp;
	int tmp2;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		if(i%2==0){
			op1.push_back((int)tmp-48);
		}
		else{
			switch(tmp){
				case '+':
					op2.push_back(11);
					break;
				case '-':
					op2.push_back(12);
					break;
				case '*':
					op2.push_back(13);
					break;
				case '/':
					op2.push_back(14);
					break;
			}		
		}
	}
	dfs(0,op1[0]);
	cout<<answer<<" ";
	
	return 0;
}
