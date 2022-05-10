#include <iostream>

using namespace std;

int n,m,r;
int map[301][301];
int cpy_map[301][301];
int nm;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void init(){
	for(int i=0;i<301;i++){
		for(int j=0;j<301;j++){
			cpy_map[i][j] = 0;
		}
	}
}

void cpymap(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			map[i][j] = cpy_map[i][j];
		}
	}
}

void wheel(){
	for(int i=0;i<nm/2;i++){
		int x = i;
		int y = i;
		int dir = 0;
		while(1){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			cpy_map[nx][ny] = map[x][y];
			x = nx;
			y = ny;
			if((x+i==n-1&&y-i==0)||(x-i==0&&y+i==m-1)||(x+i==n-1&&y+i==m-1)||(x-i==0&&y-i==0)){
				dir = (dir+1)%4;	
				if(dir==0){
					break;
				}
			}  
		}
	}
	cpymap();		

}

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main(void){
	cin>>n>>m>>r;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	nm = min(n,m);
	int t = 2*n+2*m-4;
	for(int i=1;i<nm/2;i++){
		t = lcm(t,2*(n-2*i)+2*(m-2*i)-4);
	}
	for(int i=0;i<r%t;i++){
		wheel();	
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
