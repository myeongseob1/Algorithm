#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct memb{
	int age;
	int idex;
	string name;
};


int n;
vector<memb> ve;


bool compare(memb a,memb b){
	if(a.age==b.age){
		a.idex<b.idex;
	}
	return a.age<b.age;
}
 
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		string b;
		cin>>a;
		cin>>b;
		memb tmp;
		tmp.age = a;
		tmp.name = b;
		tmp.idex = i;
		ve.push_back(tmp);
	}
	sort(ve.begin(),ve.end(),compare);
	for(int i=0;i<n;i++){
		cout<<ve[i].age<<" "<<ve[i].name<<"\n";
	}
	return 0;
}
