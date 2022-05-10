#include <iostream>
#include <vector>
using namespace std;

int test_case;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>test_case;
	for(int iii=0;iii<test_case;iii++){
		
		int n;
		vector<long long> ve;
		vector<long long> buy;
		long long answer = 0;
		
		cin>>n;
		for(int i=0;i<n;i++){
			long long tmp;
			cin>>tmp;
			ve.push_back(tmp);
		}
		int max_price = 0;
		for(int i=n-1;i>=0;i--){
			if(ve[i]>=max_price){
				max_price = ve[i];
			}
			else{
				answer += max_price-ve[i];	
			}
		}
		cout<<answer<<"\n";
	}
	
	return 0;
}
