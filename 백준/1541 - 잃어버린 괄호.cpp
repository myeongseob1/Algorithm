#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

string a;
vector<char> op;
vector<int> num;


int main(void){
	cin>>a;
	int idx = 0;
	bool minu = false;
	for(int i=0;i<a.size();i++){
		if(a[i]=='+'&&minu==false){
			op.push_back('+');
			int tmp = 0;
			for(int j=idx;j<=i-1;j++){
				tmp += (a[j]-'0')*pow(10,i-1-j);
			}		
			num.push_back(tmp);
			idx = i+1;
		}
		else if(a[i]=='-'||(a[i]=='+'&&minu==true)){
			minu = true;
			op.push_back('-');
			int tmp = 0;
			for(int j=idx;j<=i-1;j++){
				tmp += (a[j]-'0')*pow(10,i-1-j);
			}
			num.push_back(tmp);
			idx = i+1;
		}
		if(i==a.size()-1){
			int tmp = 0;
			for(int j=idx;j<=i;j++){
				tmp += (a[j]-'0')*pow(10,i-j);
			}
			num.push_back(tmp);
		}
	}
	int answer = num[0];
	for(int i=1;i<num.size();i++){
		if(op[i-1]=='-'){
			answer -= num[i]; 
		}
		if(op[i-1]=='+'){
			answer += num[i]; 
		}		
	}
	cout<<answer<<"\n";
	return 0;
}
