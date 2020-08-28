#include<iostream>
 
using namespace std;

bool prime(int n){
	if(n<2){
		return false;
	}	
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
 
int main(void)
{
	int iter, num[100],result = 0;
	cin>>iter;
	for(int i =0;i<iter;i++){
		cin>>num[i];
	}
	for(int i =0;i<iter;i++){
		if(prime(num[i])==true){
			result++;
		}
	}	
	cout<<result;
	return 0;
}
