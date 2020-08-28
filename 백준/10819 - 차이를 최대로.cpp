#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int man_distance(vector<int> a){
	int distance = 0;
	for(int i=1;i<a.size();i++){
		distance += abs(a[i-1]-a[i]);	
	}
	
	return distance;
}


int main(void){
	int iter,max;
	int ans;
	cin>>iter;
	vector<int> num(iter);
	for(int i=0;i<iter;i++){
		cin>>num[i];
	}
	sort(num.begin(),num.end());
	max = 0;
	do{
		ans = man_distance(num); 
		if(ans>max){
			max = ans;
		}
	}while(next_permutation(num.begin(),num.end()));
	cout<<max<<'\n';
	return 0;
}
