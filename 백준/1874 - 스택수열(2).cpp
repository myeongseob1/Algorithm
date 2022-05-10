#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
stack<int> st;
vector<int> list;
int cnt = 1;
string answer = "";
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(t>=cnt){
			for(int ii= cnt;ii<=t;ii++){
				st.push(ii);
				cnt++;
				answer += "+\n";
			}
			st.pop();
			answer += "-\n";
			
		}
		else{
			if(st.top() != t){
				answer += "No\n";
				break;
			}
			else{
				st.pop();
				answer += "-\n";
			}
		}
	}
	
	cout<<answer;	
	return 0;
}
