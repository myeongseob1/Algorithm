#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct memb{
	int age,old;
	string name;
};

vector<memb> ve;
int n;

bool compare(memb a,memb b){
	if(a.age==b.age){
		return a.old<b.old;
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
		tmp.old = i;
		ve.push_back(tmp);
	}
	sort(ve.begin(),ve.end(),compare);
	for(int i=0;i<n;i++){
		cout<<ve[i].age<<" "<<ve[i].name<<"\n";
	}
	return 0;
}
