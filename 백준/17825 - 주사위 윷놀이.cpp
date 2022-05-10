#include <iostream>

using namespace std;

pair<int,int> horse[4];
int pan[5][22]
= {
	{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38},
	{10,13,16,19},
	{20,22,24},
	{30,28,27,26},
	{25,30,35,40,0}
  };
int zari[5][22];
int seq[11];
int dice[10];
int answer;
void dfs(int num){
	if(num==10){
		int score = 0;
		for(int i=0;i<4;i++){
			horse[i].first = 0;
			horse[i].second = 0;
		}
		for(int i=0;i<5;i++){
			for(int j=0;j<22;j++){
				zari[i][j] = 0;
			}
		}
		bool zung = false;
		for(int i=0;i<num;i++){
			zari[horse[seq[i]].first][horse[seq[i]].second] = 0;
			horse[seq[i]].second += dice[i];
			if(horse[seq[i]].first==0&&horse[seq[i]].second>20){
				horse[seq[i]].first = 4;
				horse[seq[i]].second = 4;
			}
			if(horse[seq[i]].first==1&&horse[seq[i]].second>=4){
				horse[seq[i]].first = 4;
				horse[seq[i]].second -= 4;
			}
			if(horse[seq[i]].first==2&&horse[seq[i]].second>=3){
				horse[seq[i]].first = 4;
				horse[seq[i]].second -= 3;
			}
			if(horse[seq[i]].first==3&&horse[seq[i]].second>=4){
				horse[seq[i]].first = 4;
				horse[seq[i]].second -= 4;
			}
			if(horse[seq[i]].first==4&&horse[seq[i]].second>4){
				horse[seq[i]].first=4;
				horse[seq[i]].second=4;
			}
			if(horse[seq[i]].first==0&&horse[seq[i]].second==5){
				horse[seq[i]].first=1;
				horse[seq[i]].second=0;
			}
			if(horse[seq[i]].first==0&&horse[seq[i]].second==10){
				horse[seq[i]].first=2;
				horse[seq[i]].second=0;
			}
			if(horse[seq[i]].first==0&&horse[seq[i]].second==15){
				horse[seq[i]].first=3;
				horse[seq[i]].second=0;
			}
			if(horse[seq[i]].first==0&&horse[seq[i]].second==20){
				horse[seq[i]].first = 4;
				horse[seq[i]].second = 3;
			}

			zari[horse[seq[i]].first][horse[seq[i]].second]++;
			for(int j=0;j<5;j++){
				for(int k=0;k<21;k++){
					if((!(j==4&&k==4))&&(!(j==0&&k==0))){
						if(zari[j][k]>1){
							zung = true;
						}
					}
				}
			}
			if(zung==true) break;
			score += pan[horse[seq[i]].first][horse[seq[i]].second];
			
		}
		if(zung==false){
			answer = max(answer,score);
		}
		return;
	}
	for(int i=0;i<4;i++){
		seq[num] = i;
		dfs(num+1);
		seq[num] = 0;
	}
} 
int main(void){
	for(int i=0;i<10;i++){
		cin>>dice[i];
	}
	dfs(0);
	cout<<answer<<"\n";	
	return 0;
}
