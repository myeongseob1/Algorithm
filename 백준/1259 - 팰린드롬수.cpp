#include <iostream>
#include <vector>

using namespace std;

int main(void){
	while(1){
		string num;
		cin>>num;
		if(num=="0"){
			break;
		}

		string answer = "yes";
		for(int i=0;i<num.size();i++){
			if(num[i]!=num[num.size()-1-i]){
				answer = "no";
			}
		}
		cout<<answer<<"\n";
	}
	return 0;
}
