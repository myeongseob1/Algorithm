#include <iostream>
#include <algorithm>
 
using namespace std;

int main(void)
{
	int height[10],result[8],sum = 0,idx=0;
	for(int i=0;i<9;i++){
		cin>>height[i];
		sum += height[i];
	}
	sort(height,height+9);
	for(int i=0;i<9;i++){
		for(int j=i+1;j<9;j++){
			if(sum-height[i]-height[j]==100){
				for(int k=0;k<9;k++){
					if(i == k ||j==k) continue;
					result[idx++] = height[k];
				}
			}
		}
	}
	for(int i=0;i<7;i++){
		cout<<result[i]<<endl;
	}
	return 0;
}
