#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,answer;
int a[51][9];
vector<int> t;
int main(void){
	cin>>n;
	//nȸ 1~9��Ÿ�ڱ��� �Է¹ޱ� 
	for(int i=0;i<n;i++){
		for(int j=0;j<9;j++){
			cin>>a[i][j];
		}	
	}
	//1�������� 4��Ÿ���ΰŸ� ���� ���Ϳ�����
	//1~8 ���Ŀ� 3���ε����� 0�� ���Կ���(0 = 1������) 
	for(int i=1;i<9;i++){
		t.push_back(i);
	}
	do{
		vector<int> tmp;
		tmp.assign(t.begin(),t.end());
		tmp.insert(tmp.begin()+3,0);// 1������(0)�� 3���ε����� ����  
		int score = 0;
		int j=0;
		for(int i=0;i<n;i++){
			int base[3] = {0,0,0};
			int out =0;
			while(1){
				if(a[i][tmp[j]]==0){//0�ΰ�� out 
					out++;
				}
				if(out==3){//3out�ϸ� ����ȸ�� �Ѿ������ break 
					if(j==8){
						j=0;
					}
					else{
						j++;
					}					
					break;
				}
				if(a[i][tmp[j]]==1){//1��Ÿ ĥ��� 
					if(base[2]==1){//3�翡 ��������� ���� �߰� 
						score++;
						base[2] = 0;
					}
					if(base[1]==1){//2�翡 ��������� 3��� ���� 1�翡 ������� 
						base[2] = 1;
						base[1] = 0;
					}
					if(base[0]==1){//1�翡 ��������� 2��� ������ 
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
	}while(next_permutation(t.begin(),t.end()));//���� 1�� ���� ���������� 
	cout<<answer<<"\n";
	return 0;
}
