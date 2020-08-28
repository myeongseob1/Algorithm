#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int wheel[4][9];
int num;
int spin[102][2];
int answer=0;

void spinner(int num,int direction){
	int tmp[8]={0,0,0,0,0,0,0,0};
	for(int i=0;i<8;i++){
		tmp[i] = wheel[num][i];		
	}
	if(direction==1){
		for(int i=0;i<7;i++){
			wheel[num][i+1] = tmp[i]; 
		}
		wheel[num][0] = tmp[7];
	}
	else if(direction == -1){
		for(int i=0;i<7;i++){
			wheel[num][i] = tmp[i+1]; 
		}
		wheel[num][7] = tmp[0];
	}
}

int main(void){
	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++){
			scanf("%1d",&wheel[i][j]);
		}
	}
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>spin[i][0]>>spin[i][1];
	}
	for(int i=0;i<num;i++){
		switch(spin[i][0]){
			case 1:
				if(spin[i][1]==1){
					if(wheel[0][2]==wheel[1][6]){
						spinner(0,1);				
					}
					else{
						if(wheel[1][2]==wheel[2][6]){
							spinner(0,1);
							spinner(1,-1);
						}
						else{
							if(wheel[2][2]==wheel[3][6]){
								spinner(0,1);
								spinner(1,-1);
								spinner(2,1);
							}
							else{
								spinner(0,1);
								spinner(1,-1);
								spinner(2,1);
								spinner(3,-1);							
							}
						}
					}

				}
				else{
					if(wheel[0][2]==wheel[1][6]){
						spinner(0,-1);				
					}
					else{
						if(wheel[1][2]==wheel[2][6]){
							spinner(0,-1);
							spinner(1,1);
						}
						else{
							if(wheel[2][2]==wheel[3][6]){
								spinner(0,-1);
								spinner(1,1);
								spinner(2,-1);
							}
							else{
								spinner(0,-1);
								spinner(1,1);
								spinner(2,-1);
								spinner(3,1);							
							}
						}
					}
				}
				break;
				
			case 2:
				if(spin[i][1]==1){
					if(wheel[1][2]==wheel[2][6]&&wheel[1][6]==wheel[0][2]){
						spinner(1,1);
					}
					else if(wheel[1][2]==wheel[2][6]&&wheel[1][6]!=wheel[0][2]){
						spinner(0,-1);
						spinner(1,1);
					}
					else if(wheel[1][6]==wheel[0][2]&&wheel[1][2]!=wheel[2][6]){
						if(wheel[2][2]==wheel[3][6]){
							spinner(1,1);
							spinner(2,-1);
						}
						else{
							spinner(1,1);
							spinner(2,-1);
							spinner(3,1);
						}
					}
					else{
						if(wheel[2][2]==wheel[3][6]){
							spinner(0,-1);
							spinner(1,1);
							spinner(2,-1);
							
						}
						else{
							spinner(0,-1);
							spinner(1,1);
							spinner(2,-1);							
							spinner(3,1);							
						}
					} 
				}
				else{
					if(wheel[1][2]==wheel[2][6]&&wheel[1][6]==wheel[0][2]){
						spinner(1,-1);
					}
					else if(wheel[1][2]==wheel[2][6]&&wheel[1][6]!=wheel[0][2]){
						spinner(0,1);
						spinner(1,-1);
					}
					else if(wheel[1][6]==wheel[0][2]&&wheel[1][2]!=wheel[2][6]){
						if(wheel[2][2]==wheel[3][6]){
							spinner(1,-1);
							spinner(2,1);
						}
						else{
							spinner(1,-1);
							spinner(2,1);
							spinner(3,-1);
						}
					}
					else{
						if(wheel[2][2]==wheel[3][6]){
							spinner(0,1);
							spinner(1,-1);
							spinner(2,1);
							
						}
						else{
							spinner(0,1);
							spinner(1,-1);
							spinner(2,1);							
							spinner(3,-1);							
						}

					}					
				}
				break;
				
			case 3:
				if(spin[i][1]==1){
					if(wheel[2][6]==wheel[1][2]&&wheel[2][2]==wheel[3][6]){
						spinner(2,1);
					}
					else if(wheel[2][6]==wheel[1][2]&&wheel[2][2]!=wheel[3][6]){
						spinner(2,1);
						spinner(3,-1);
					}
					else if(wheel[2][2]==wheel[3][6]&&wheel[2][6]!=wheel[1][2]){
						if(wheel[1][6]==wheel[0][2]){
							spinner(2,1);
							spinner(1,-1);
						}
						else{
							spinner(2,1);
							spinner(1,-1);
							spinner(0,1);
						}
					}
					else{
						if(wheel[1][6]==wheel[0][2]){
							spinner(2,1);
							spinner(1,-1);
							spinner(3,-1);
							
						}
						else{
							spinner(0,1);
							spinner(1,-1);
							spinner(2,1);
							spinner(3,-1);
							
						}
					}
				}
				else{
					if(wheel[2][6]==wheel[1][2]&&wheel[2][2]==wheel[3][6]){
						spinner(2,-1);
					}
					else if(wheel[2][6]==wheel[1][2]&&wheel[2][2]!=wheel[3][6]){
						spinner(2,-1);
						spinner(3,1);
					}
					else if(wheel[2][2]==wheel[3][6]&&wheel[2][6]!=wheel[1][2]){
						if(wheel[1][6]==wheel[0][2]){
							spinner(2,-1);
							spinner(1,1);
						}
						else{
							spinner(2,-1);
							spinner(1,1);
							spinner(0,-1);
						}
					}
					else{
						if(wheel[1][6]==wheel[0][2]){
							spinner(2,-1);
							spinner(1,1);
							spinner(3,-1);
							
						}
						else{
							spinner(0,-1);
							spinner(1,1);
							spinner(2,-1);
							spinner(3,1);
							
						}
					}					
				}
				break;
				
			case 4:
				if(spin[i][1]==1){
					if(wheel[3][6]==wheel[2][2]){
						spinner(3,1);
					}
					else{
						if(wheel[2][6]==wheel[1][2]){
							spinner(2,-1);
							spinner(3,1);
						}
						else{
							if(wheel[1][6]==wheel[0][2]){
								spinner(1,1);
								spinner(2,-1);
								spinner(3,1);
							}
							else{
								
								spinner(0,-1);
								spinner(1,1);
								spinner(2,-1);
								spinner(3,1);
							}
						}
					}
				}
				else{
					if(wheel[3][6]==wheel[2][2]){
						spinner(3,-1);
					}
					else{
						if(wheel[2][6]==wheel[1][2]){
							spinner(2,1);
							spinner(3,-1);
						}
						else{
							if(wheel[1][6]==wheel[0][2]){
								spinner(1,-1);
								spinner(2,1);
								spinner(3,-1);
							}
							else{
								spinner(0,1);
								spinner(1,-1);
								spinner(2,1);
								spinner(3,-1);
							}
						}
					}
					
				}
				break;
		}
	}
	if(wheel[0][0]==1){
		answer += 1;
	}
	if(wheel[1][0]==1){
		answer +=2;
	}
	if(wheel[2][0]==1){
		answer +=4;
	}
	if(wheel[3][0]==1){
		answer += 8;
	}
	cout<<answer<<"\n";
	return 0;
}
