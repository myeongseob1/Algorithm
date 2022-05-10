#include <iostream>
#include <stack>

using namespace std;
int n;
stack<int> st;
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		if(num==0){
			st.pop();
		}else{
			st.push(num);
		}
	}
	int answer = 0;
	int sz = st.size();
	for(int i=0;i<sz;i++){
		answer +=st.top();
		st.pop();
	}
	cout<<answer<<"\n";
	return 0;
}
