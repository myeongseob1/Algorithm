#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string list;
	stack<int> st;
	int n;
	cin>>n;
	int cnt = 1;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(t>=cnt){
//			while(t+1!=cnt){
			for(int j=cnt;j<=t;j++){
				st.push(j);
				cnt++;
				list += "+\n";								
			}
//			}
			st.pop();
			list += "-\n";
		}
		else{
			if(st.top() != t){
				list = "NO\n";
				break;
			}else{
				st.pop();
				list += "-\n";
			}
		}
	}
	cout<<list;
	return 0;
}
