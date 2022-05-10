#include<iostream>
#include<vector>
 
#define endl "\n"
#define MAX 1000
using namespace std;
 
int R, C, K;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };
pair<int, int> Start;
vector<int> V;
 
void Input()
{
    cin >> R >> C >> K;
    for (int i = 0; i < K; i++)
    {
        int a, b; cin >> a >> b;
        MAP[a][b] = 1;
    }
    cin >> Start.first >> Start.second;
    for (int i = 0; i < 4; i++)
    {
        int a; cin >> a;
        V.push_back(a);
    }
}
 
bool CanMove(int x, int y)
{
    for (int i = 1; i <= 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        if (nx >= 0 && ny >= 0 && nx < R && ny < C)
        {
            if (MAP[nx][ny] == 0 && Visit[nx][ny] == false)
            {
                return true;
            }
        }
    }
    return false;
}
 
void Solution()
{
    int x = Start.first;
    int y = Start.second;
    int Dir_Idx = 0;
    Visit[x][y] = true;
 
    while (1)
    {
        if (CanMove(x, y) == false) break;
        
        while (1)
        {
            x = x + dx[V[Dir_Idx]];
            y = y + dy[V[Dir_Idx]];
 
            if (x < 0 || y < 0 || x >= R || y >= C) break;
            if (MAP[x][y] == 1) break;
            if (Visit[x][y] == true) break;
 
            Visit[x][y] = true;
        }
        x = x - dx[V[Dir_Idx]];
        y = y - dy[V[Dir_Idx]];
        Dir_Idx++;
        if (Dir_Idx == 5) Dir_Idx = 0;
    }
    cout << x << " " << y << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}

