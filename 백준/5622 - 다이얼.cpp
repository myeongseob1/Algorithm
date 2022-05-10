#include <iostream>

using namespace std;

string a;

int main(void){
	cin>>a;
	int answer =  0;
	for(int i=0;i<a.size();i++){
		if(a[i]<='O'){
			answer += (((int)a[i]-'A')/3)+3;
		}
		else if(a[i]>='P'&&a[i]<='S'){
			answer += 8;
		}
		else if(a[i]>='T'&&a[i]<='V'){
			answer += 9;
		}
		else if(a[i]>='W'&&a[i]<='Z'){
			answer += 10;
		}
	}	
	cout<<answer<<"\n";
	return 0;
}
