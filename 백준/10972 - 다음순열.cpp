#include <iostream>
#include <algorithm>

using namespace std;

//bool next_permutation(int *a, int n){
//	int i = n-1;
//	while(i>0 && a[i-1]>=a[i]) i-=1;
//	if(i<=0) return false;
//	int j = n-1;
//	while(a[j]<=a[i-1]) j-=1;
//	swap(a[i-1],a[j]);
//	j = n-1;
//	while(i<j){
//		swap(a[i],a[j]);
//		i+=1;j-=1;
//	}
//	return true;
//}


int main(void){
	int iter;
	bool b; 
	cin>>iter;
	int *a;
	a = new int[iter];
	for(int i=0;i<iter;i++){
		cin>>a[i];
	}
	b = next_permutation(a,a+iter); 
	if(b==true){
		for(int i=0;i<iter;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<-1<<endl;
	}
	
	return 0;
}
