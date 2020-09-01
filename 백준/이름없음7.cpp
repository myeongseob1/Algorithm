#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 21

typedef pair<int, int> p;

int N, M, Fuel; // ���� ũ��, �°� ��, ó���� ������ ���� �����

int StartLink[MAX][MAX]; // ����
int Dist[MAX][MAX]; // -1�̸� �̵��� �� ���� �����̹Ƿ� ���� �����϶� -1�̸� �׳� -1����ϸ� �ȴ� -> �� �����ִٴ� �� 
bool visit[MAX][MAX] = { false, };
p taxi; // �ý� ��ġ
p Customer[MAX*MAX]; // ���� �����ϰ��� �ϴ� ������

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

void Cal_Dist() { // �ý���ġ ���� �Ÿ� ���ϱ� �մ� ���ϱ�뵵
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
				if (StartLink[nx][ny] == 1)continue; // ���� ��ġ�� ��� ���ȵ� 
				
				Dist[nx][ny] = dist + 1;
				visit[nx][ny] = true;
				q.push({ nx,ny,dist + 1 }); // �� �κ� �������� 
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
				if (StartLink[nx][ny] == 1)continue; // ���� ��ġ�� ��� ���ȵ� 
				
				Dist[nx][ny] = dist + 1;
				visit[nx][ny] = true;
				q.push({ nx,ny,dist + 1 });
			}
		}
	}
}


bool solve() { // ���

	Cal_Dist(); // ���� �ý� ���� �մԱ��� �Ÿ� ���ϱ�

	priority_queue<info, vector<info>, cmp> pq;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Dist[i][j] != -1 && StartLink[i][j] >= 2) // StartLink[i][j] >= 2 �κ��� ó���� �ȳ־����� �׳� �ý� ���� ��ġ�� ���� �����߻�
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

	Cal_Destination(); // ���������� ���

	int customer_number = StartLink[x][y];
	p destination_pos = Customer[customer_number]; // ������ ��ġ 

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

	for (int i = 2; i <= M+1; i++) { // ó���� 1���� �Ϸ��ٰ� �����غ��� 1�� �����̶� +1����
		int a, b, c, d; // �մ� ��� ��ġ�� ������ ��ġ
		cin >> a >> b >> c >> d;

		StartLink[a][b] = i;

		Customer[i] = {c,d}; // ���� ������ ����
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
