#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,answer;
int a[51][9];
vector<int> t;
int main(void){
	cin>>n;
	//n회 1~9번타자까지 입력받기 
	for(int i=0;i<n;i++){
		for(int j=0;j<9;j++){
			cin>>a[i][j];
		}	
	}
	//1번선수가 4번타자인거만 빼고 벡터에삽입
	//1~8 이후에 3번인덱스에 0을 삽입예정(0 = 1번선수) 
	for(int i=1;i<9;i++){
		t.push_back(i);
	}
	do{
		vector<int> tmp;
		tmp.assign(t.begin(),t.end());
		tmp.insert(tmp.begin()+3,0);// 1번선수(0)를 3번인덱스에 삽입  
		int score = 0;
		int j=0;
		for(int i=0;i<n;i++){
			int base[3] = {0,0,0};
			int out =0;
			while(1){
				if(a[i][tmp[j]]==0){//0인경우 out 
					out++;
				}
				if(out==3){//3out하면 다음회로 넘어가기위해 break 
					if(j==8){
						j=0;
					}
					else{
						j++;
					}					
					break;
				}
				if(a[i][tmp[j]]==1){//1루타 칠경우 
					if(base[2]==1){//3루에 사람있으면 점수 추가 
						score++;
						base[2] = 0;
					}
					if(base[1]==1){//2루에 사람있으면 3루로 가고 1루에 사람없앰 
						base[2] = 1;
						base[1] = 0;
					}
					if(base[0]==1){//1루에 사람있으면 2루로 보내기 
						base[1] = 1;
						base[0] = 0;
					}
					base[0] = 1;
				}
				if(a[i][tmp[j]]==2){
					if(base[2]==1&&base[1]==1){
						score +=2;
						base[1] = 0;
						base[2] = 0;
					}
					else if(base[2]==1){
						score++;
						base[1] = 0;
						base[2] = 0;
					}
					else if(base[1]==1){
						score++;
						base[1] = 0;
						base[2] = 0;
					}
					if(base[0]==1){
						base[0] = 0;
						base[2] = 1;
					}
					base[1] = 1;
				}
				if(a[i][tmp[j]]==3){
					if(base[2]==1&&base[1]==1&&base[0]==1){
						score += 3;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
					}
					else if((base[0]==1&&base[1]==1)||(base[0]==1&&base[2]==1)||(base[1]==1&&base[2]==1)){
						score += 2;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
					}
					else if(base[0]==1||base[1]==1||base[2]==1){
						score++;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
					}
					else if(base[0]==0&&base[1]==0&&base[2]==0){
						base[2] = 1;
					}
					base[2] = 1;		
				}
				if(a[i][tmp[j]]==4){
					score++;
					for(int k=0;k<3;k++){
						if(base[k]==1){
							score++;
						}
						base[k] = 0;
					}
				}
				if(j==8){
					j=0;
				}
				else{
					j++;
				}					

			}
			}
			if(score>answer){
				answer = score;
			}		
	}while(next_permutation(t.begin(),t.end()));//선수 1명만 빼고 순열돌리기 
	cout<<answer<<"\n";
	return 0;
}
