#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int iter;
	cin>>iter;
	vector<int> a(iter);
	for(int i=0;i<iter;i++){
		a[i] = i+1;
	}
	
	do{
		for(int i=0;i<iter;i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}while(next_permutation(a.begin(),a.end()));
	
	
	
	return 0;
}
