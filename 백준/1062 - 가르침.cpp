#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string inp[51];
int n,k;
string lst = "";
int answer;
bool alpha[30];
void init(){
	for(int i=0;i<30;i++){
		alpha[i] = false;
	}
}
int main(void){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>inp[i];
		lst += inp[i]; 
	}
	sort(lst.begin(),lst.end());
	lst.erase(unique(lst.begin(),lst.end()),lst.end());
	vector<int> ve;
	for(int i=0;i<lst.size();i++){
		if(i<k){
			ve.push_back(0);
		}
		else{
			ve.push_back(1);
		}
	}
	do{
		init();
		for(int i=0;i<lst.size();i++){
			if(ve[i]==0){
				alpha[lst[i]-'a'] = true;
			}
		}
		int rslt = 0;
		for(int i=0;i<n;i++){
			bool pss = true;
			for(int j=0;j<inp[i].size();j++){
				if(alpha[inp[i][j]-'a']==false){
					pss = false;
					break;
				}
			}
			if(pss) rslt++;
		}
		answer = max(answer,rslt);
	}while(next_permutation(ve.begin(),ve.end()));
	cout<<answer<<"\n";
	return 0;
}
