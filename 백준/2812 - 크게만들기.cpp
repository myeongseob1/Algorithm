#include <iostream>

using namespace std;
int n,k; 
int main(void){
	string number;
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);	

	cin>>n>>k;
	cin>>number;
	string answer = "";
    for(int i=0,index=-1;i<number.size()-k;i++){
        char max = 0;
        for(int j=index+1;j<=k+i;j++){
            if(max<number[j]){
                index = j;
                max = number[j];
            }
        }
        answer+= max;
    }
	cout<<answer<<"\n";
	return 0;
}
