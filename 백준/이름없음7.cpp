#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 21

typedef pair<int, int> p;

int N, M, Fuel; // 지도 크기, 승객 수, 처음에 가지고 있을 연료양

int StartLink[MAX][MAX]; // 지도
int Dist[MAX][MAX]; // -1이면 이동할 수 없는 지역이므로 만약 도착일때 -1이면 그냥 -1출력하면 된다 -> 다 막혀있다는 뜻 
bool visit[MAX][MAX] = { false, };
p taxi; // 택시 위치
p Customer[MAX*MAX]; // 고객이 도착하고자 하는 목적지

int dx[4] = {-1,0,1,0}; // up right down left
int dy[4] = {0,1,0,-1}; 

struct info {
	int x, y, dist;
};

struct cmp {
	bool operator()(info a, info b) {
		if (a.dist == b.dist) {
			if (a.x == b.x)
				return a.y > b.y;
			return a.x > b.x;
		}
		return a.dist > b.dist;
	}
};

void Cal_Dist() { // 택시위치 기준 거리 구하기 손님 구하기용도
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[i][j] = false;
			Dist[i][j] = -1;
		}
	}

	int x = taxi.first;
	int y = taxi.second;

	queue<info> q;
	q.push({ x,y,0 });

	Dist[x][y] = 0;
	visit[x][y] = true;

	while (!q.empty()) {
		int Size = q.size();		
		while (Size--) {
			info tmp = q.front();
			q.pop();

			int x = tmp.x;
			int y = tmp.y;
			int dist = tmp.dist;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
				if (visit[nx][ny]) continue;
				if (StartLink[nx][ny] == 1)continue; // 벽돌 위치일 경우 계산안됨 
				
				Dist[nx][ny] = dist + 1;
				visit[nx][ny] = true;
				q.push({ nx,ny,dist + 1 }); // 이 부분 잊지말자 
			}
		}
	}
}

void Cal_Destination() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[i][j] = false;
			Dist[i][j] = -1;
		}
	}

	int x = taxi.first;
	int y = taxi.second;

	queue<info> q;
	q.push({ x,y,0 });

	Dist[x][y] = 0;
	visit[x][y] = true;

	while (!q.empty()) {
		int Size = q.size();
		while (Size--) {
			info tmp = q.front();
			q.pop();

			int x = tmp.x;
			int y = tmp.y;
			int dist = tmp.dist;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
				if (visit[nx][ny]) continue;
				if (StartLink[nx][ny] == 1)continue; // 벽돌 위치일 경우 계산안됨 
				
				Dist[nx][ny] = dist + 1;
				visit[nx][ny] = true;
				q.push({ nx,ny,dist + 1 });
			}
		}
	}
}


bool solve() { // 계산

	Cal_Dist(); // 현재 택시 기준 손님까지 거리 구하기

	priority_queue<info, vector<info>, cmp> pq;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Dist[i][j] != -1 && StartLink[i][j] >= 2) // StartLink[i][j] >= 2 부분을 처음에 안넣었더니 그냥 택시 시작 위치가 들어가서 문제발생
				pq.push({ i,j,Dist[i][j] });
		}
	}

	if (pq.size() == 0)
		return false;

	info customer_pos = pq.top();
	int x, y, dist;


	x = customer_pos.x;
	y = customer_pos.y;
	dist = customer_pos.dist;

	if (dist > Fuel)
		return false;

	Fuel -= dist;

	taxi = {x,y};

	Cal_Destination(); // 목적지까지 계산

	int customer_number = StartLink[x][y];
	p destination_pos = Customer[customer_number]; // 목적지 위치 

	int d_x = destination_pos.first;
	int d_y = destination_pos.second;

	if (Dist[d_x][d_y] == -1)
		return false;

	int d_dist = Dist[d_x][d_y];

	if (d_dist > Fuel)
		return false;

	Fuel -= d_dist;

	Fuel += (d_dist * 2);

	StartLink[x][y] = 0;

	taxi = { d_x,d_y };

	return true;
}

int main() {
	cin >> N >> M >> Fuel;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> StartLink[i][j];
		}
	}

	int x, y;
	cin >> x >> y;
	taxi = { x,y };

	for (int i = 2; i <= M+1; i++) { // 처음엔 1부터 하려다가 생각해보니 1은 벽돌이라 +1해줌
		int a, b, c, d; // 손님 출발 위치와 목적지 위치
		cin >> a >> b >> c >> d;

		StartLink[a][b] = i;

		Customer[i] = {c,d}; // 고객의 도착지 저장
	}
	

	for (int i = 0; i < M; i++) {
		if (!solve()) {
			Fuel = -1;
			break;
		}
	}

	cout << Fuel;

	return 0;
}
