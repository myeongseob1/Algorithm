#include <iostream>
#include <stack> 
using namespace std;


int main(void){
	while (1) {
		string Text;
		getline(cin, Text);
		if (Text.size() == 1 && Text[0] == '.') break;
		stack<char> st;
		bool set_g = false;
		for(int i=0;i<Text.size();i++){
			if(Text[i]=='('){
				st.push('(');		
			}else if(Text[i]==')'){
				if(!st.empty()&&st.top()=='('){
					st.pop();				
				}else{
					set_g = true;
					break;
				}
			}else if(Text[i]=='['){
				st.push('[');
			}else if(Text[i]==']'){
				if(!st.empty()&&st.top()=='['){
					st.pop();					
				}else{
					set_g = true;
					break;
				}
			}
		}
		if(st.empty()&&!set_g){
			cout<<"yes"<<"\n";
		}else{
			cout<<"no"<<"\n";
		}
	}
	
	return 0;
}
