#include <iostream>

using namespace std;

int main(void){
	string str;
    getline(cin,str);
    int answer = 1;
	for(int i=1;i<str.size()-1;i++){
		if(str[i]==' '){
			answer++;
		}
	}
	if(str.size()==1&&str[0]==' '){
		answer = 0;
	}
	cout<<answer<<"\n";
	return 0;
} 
