#include <iostream>

using namespace std;
int connection[102][102];
int n,m;
int answer =987654321;
int people;

int main(void){
	for(int i=1;i<=101;i++){
		for(int j=1;j<=101;j++){
			if(i==j) connection[i][j] = 0;
			if(i!=j) connection[i][j] = 987654321;
		}
	}

	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		connection[a][b] = 1;
		connection[b][a] = 1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				connection[i][j] = min(connection[i][j],connection[i][k]+connection[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		int sum = 0;
		for(int j=1;j<=n;j++){
			sum += connection[i][j];
		}
		if(answer>sum){
			answer = sum;
			people = i;
		}else if(answer==sum){
			people = min(people,i);
		}
	}
	cout<<people<<"\n";
	return 0;
} 
