#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	
	int N,M,max=0;
	int tetris[500][500];
	cin>>N>>M;

	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>tetris[i][j];
		}
	}

	for(int i=0;i<N-3;i++){
		for(int j=0;j<M;j++){
			if(max<tetris[i][j]+tetris[i+1][j]+tetris[i+2][j]+tetris[i+3][j]){
				max = tetris[i][j]+tetris[i+1][j]+tetris[i+2][j]+tetris[i+3][j];
			}
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M-3;j++){
			if(max<tetris[i][j]+tetris[i][j+1]+tetris[i][j+2]+tetris[i][j+3]){
				max = tetris[i][j]+tetris[i][j+1]+tetris[i][j+2]+tetris[i][j+3];
			}
		}
	}
	
	for(int i=0;i<N-1;i++){
		for(int j=0;j<M-2;j++){
			if(max<tetris[i][j]+tetris[i][j+1]+tetris[i][j+2]+tetris[i+1][j+2]){
				max = tetris[i][j]+tetris[i][j+1]+tetris[i][j+2]+tetris[i+1][j+2];
			}
			if(max<tetris[i][j+2]+tetris[i+1][j+2]+tetris[i+1][j+1]+tetris[i+1][j]){
				max = tetris[i][j+2]+tetris[i+1][j+2]+tetris[i+1][j+1]+tetris[i+1][j];
			}
			if(max<tetris[i][j]+tetris[i+1][j]+tetris[i+1][j+1]+tetris[i+1][j+2]){
				max = tetris[i][j]+tetris[i+1][j]+tetris[i+1][j+1]+tetris[i+1][j+2];
			}
			if(max<tetris[i][j]+tetris[i+1][j]+tetris[i][j+1]+tetris[i][j+2]){
				max = tetris[i][j]+tetris[i+1][j]+tetris[i][j+1]+tetris[i][j+2];
			}
			if(max<tetris[i][j]+tetris[i][j+1]+tetris[i+1][j+1]+tetris[i+1][j+2]){
				max = tetris[i][j]+tetris[i][j+1]+tetris[i+1][j+1]+tetris[i+1][j+2];
			}
			if(max<tetris[i+1][j]+tetris[i+1][j+1]+tetris[i][j+1]+tetris[i][j+2]){
				max = tetris[i+1][j]+tetris[i+1][j+1]+tetris[i][j+1]+tetris[i][j+2];
			}
			if(max<tetris[i][j]+tetris[i][j+1]+tetris[i+1][j+1]+tetris[i][j+2]){
				max = tetris[i][j]+tetris[i][j+1]+tetris[i+1][j+1]+tetris[i][j+2];
			}
			if(max<tetris[i][j+1]+tetris[i+1][j]+tetris[i+1][j+1]+tetris[i+1][j+2]){
				max = tetris[i][j+1]+tetris[i+1][j]+tetris[i+1][j+1]+tetris[i+1][j+2];
			}			
		}
	}
	for(int i=0;i<N-2;i++){
		for(int j=0;j<M-1;j++){
			if(max<tetris[i][j]+tetris[i][j+1]+tetris[i+1][j]+tetris[i+2][j]){
				max = tetris[i][j]+tetris[i][j+1]+tetris[i+1][j]+tetris[i+2][j];
			}
			if(max<tetris[i][j]+tetris[i+1][j]+tetris[i+2][j]+tetris[i+2][j+1]){
				max = tetris[i][j]+tetris[i+1][j]+tetris[i+2][j]+tetris[i+2][j+1];
			}
			if(max<tetris[i][j]+tetris[i][j+1]+tetris[i+1][j+1]+tetris[i+2][j+1]){
				max = tetris[i][j]+tetris[i][j+1]+tetris[i+1][j+1]+tetris[i+2][j+1];
			}
			if(max<tetris[i][j+1]+tetris[i+1][j+1]+tetris[i+2][j+1]+tetris[i+2][j]){
				max = tetris[i][j+1]+tetris[i+1][j+1]+tetris[i+2][j+1]+tetris[i+2][j];
			}
			if(max<tetris[i][j]+tetris[i+1][j]+tetris[i+1][j+1]+tetris[i+2][j+1]){
				max = tetris[i][j]+tetris[i+1][j]+tetris[i+1][j+1]+tetris[i+2][j+1];
			}
			if(max<tetris[i][j+1]+tetris[i+1][j+1]+tetris[i+1][j]+tetris[i+2][j]){
				max = tetris[i][j+1]+tetris[i+1][j+1]+tetris[i+1][j]+tetris[i+2][j];
			}
			if(max<tetris[i][j]+tetris[i+1][j]+tetris[i+2][j]+tetris[i+1][j+1]){
				max = tetris[i][j]+tetris[i+1][j]+tetris[i+2][j]+tetris[i+1][j+1];
			}
			if(max<tetris[i+1][j]+tetris[i][j+1]+tetris[i+1][j+1]+tetris[i+2][j+1]){
				max = tetris[i+1][j]+tetris[i][j+1]+tetris[i+1][j+1]+tetris[i+2][j+1];
			} 	
		}
	}
	for(int i=0;i<N-1;i++){
		for(int j=0;j<M-1;j++){
			if(max<tetris[i][j]+tetris[i][j+1]+tetris[i+1][j]+tetris[i+1][j+1]){
				max = tetris[i][j]+tetris[i][j+1]+tetris[i+1][j]+tetris[i+1][j+1];
			}
		}
	}
	cout<<max<<endl;
	return 0;
}
