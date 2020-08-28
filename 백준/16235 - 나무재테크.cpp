#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ios>
using namespace std;

struct tree{
	int x;
	int y;
	int age;
};

int n,m,k;
int a[11][11];
int b[11][11];
deque<tree> tr;

int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
int dy[8] = {-1, 0, 1,-1,1,-1,0,1};

bool compare(tree a,tree b){
	return a.age<b.age;
}

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			b[i][j]= 5; 
		}
	}
	for(int i=0;i<m;i++){
		int p,q,r;
		cin>>p>>q>>r;
		tr.push_back({p,q,r});
	}
	sort(tr.begin(),tr.end(),compare);
	for(int p=0;p<k;p++){
		vector<tree> del;
		int f = tr.size();
		for(int i=0;i<f;i++){
			if(tr[i].age<=b[tr[i].x][tr[i].y]){
				b[tr[i].x][tr[i].y] -= tr[i].age;
				tr[i].age++;
			}
			else{
				del.push_back({tr[i].x,tr[i].y,tr[i].age});
				tr.erase(tr.begin()+i);
				i--;
				f--;
			}
			
		}
		if(del.size()>0){
			for(int i=0;i<del.size();i++){
				b[del[i].x][del[i].y] += del[i].age/2;
			}		
		}

		for(int i=0;i<tr.size();i++){
			if(tr[i].age%5==0){
				for(int k=0;k<8;k++){
					int nx = tr[i].x+dx[k];
					int ny = tr[i].y+dy[k];
					if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
						tr.push_front({nx,ny,1});
						i++;
					}
				}		
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[i][j] += a[i][j];
			}
		}

	}
	cout<<tr.size()<<"\n";
	return 0;
}
