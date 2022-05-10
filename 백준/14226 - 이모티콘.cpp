#include <iostream>
#include <queue>

using namespace std;
int n;
bool visit[2002][2002];
int answer;
int main(void){
	cin>>n;
	queue<pair<pair<int,int>,int> > q;
	q.push(make_pair(make_pair(1,0),0));
	visit[1][0] = true;
	while(!q.empty()){
		int emo = q.front().first.first;
		int clip = q.front().first.second;
		int time = q.front().second;
		q.pop();
		if(emo==n){
			answer = time;
			break;
		}
		if(emo >0 && emo < 2000){
			if(!visit[emo][emo]){
				visit[emo][emo] = true;
				q.push(make_pair(make_pair(emo,emo),time+1));
			}
			if(!visit[emo-1][clip]){
				visit[emo-1][clip] = true;
				q.push(make_pair(make_pair(emo-1,clip),time+1));				
			}	
		}
		if(emo+clip < 2000&&clip>0){
			if(!visit[emo+clip][clip]){
				visit[emo+clip][clip] = true;
				q.push(make_pair(make_pair(emo+clip,clip),time+1));				
			}				
		}
	}
	cout<<answer<<"\n";
	return 0;
}
