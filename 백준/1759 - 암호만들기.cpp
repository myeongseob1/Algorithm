#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int L,C,vowel;

	cin>>L>>C;
	vector<char> pass(C);
	vector<int> combination(C);
	for(int i=0;i<C;i++){
		cin>>pass[i];
		combination[i] = 1;
	}
	for(int i=0;i<L;i++){
		combination[i] = 0;
	}
	sort(pass.begin(),pass.end());
	vowel = 0;
	do{
		for(int i=0;i<C;i++){
			if(combination[i]==0&&(pass[i]=='a'||pass[i]=='e'||pass[i]=='i'||pass[i]=='o'||pass[i]=='u')){
				vowel++;
			}
		}
		for(int i=0; i<C; i++){
			if(combination[i]==0&&vowel>0&&L-vowel>1){
				cout<<pass[i];
			}
		}
		if(vowel>0&&L-vowel>1){
			cout<<"\n";
		} 
		vowel =0;		
	}while(next_permutation(combination.begin(),combination.end()));	
	return 0;
}
