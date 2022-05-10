#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct member{
	int age;
	string name;
	int idx;
};

vector<member> ve;
int n;

bool compare(member a,member b){
	if(a.age==b.age){
		return a.idx < b.idx;
	}
	return a.age < b.age;
}

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		string b;
		cin>>a>>b;
		member tm;
		tm.age = a;
		tm.name = b;
		tm.idx = i;
		ve.push_back(tm);
	}
	sort(ve.begin(),ve.end(),compare);
	for(int i=0;i<ve.size();i++){
		cout<<ve[i].age<<" "<<ve[i].name<<"\n";
	}
	return 0;
}
