#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
string a;
vector<int> num;
vector<char> op;
int result ;
int calculator(char op1,int num1,int num2){
	switch(op1){
		case '+':
			return num1+num2;
		case '-':
			return num1-num2;
	}
}
int main(void){
	cin>>a;
	int prev_index = 0;
	bool minus_ad = false;
	bool ggang = false;
	for(int i=0;i<a.size();i++){
		if(a[i]=='-'||a[i]=='+'){
			ggang = true;
		}
	}
	if(ggang==true){
		for(int i=0;i<a.size();i++){
			vector<char> tmp;
			int tmp_num = 0;
			if(a[i]=='-'||a[i]=='+'){
				if(a[i]=='-'){
					minus_ad = true;
				}
				if(minus_ad==false){
					op.push_back(a[i]);
				}
				else{
					op.push_back('-');
				}
				for(int j=prev_index;j<i;j++){
					tmp.push_back(a[j]);
				}
				for(int j=0;j<tmp.size();j++){
					tmp_num += ((int)tmp[j]-48)*pow(10,tmp.size()-j-1);
				}
				num.push_back(tmp_num);
				prev_index = i+1;
			}
		}
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]=='-'||a[i]=='+'){
				vector<char> tmp;
				int tmp_num = 0;
				for(int j=i+1;j<a.size();j++){
					tmp.push_back(a[j]);				
				}
				for(int j=0;j<tmp.size();j++){
					tmp_num += ((int)tmp[j]-48)*pow(10,tmp.size()-j-1);
				}
				num.push_back(tmp_num);
				break;
			}
		}
		result = num[0];
		for(int i=0;i<op.size();i++){
			result = calculator(op[i],result,num[i+1]);
		}		
	}
	else{
		result = stoi(a);
	}
	cout<<result<<"\n";
	return 0;
}
