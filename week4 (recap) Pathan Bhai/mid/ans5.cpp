#include <iostream>
#include <queue>
#define pi pair<int, int>
using namespace std;
int row, col;
bool visited[105][105];
int dis[105][105];
vector<pi> path = {
    make_pair(1, 2),
    make_pair(1, -2),
    make_pair(-1, 2),
    make_pair(-1, -2),
    make_pair(2, 1),
    make_pair(2, -1),
    make_pair(-2, 1),
    make_pair(-2, -1)};
bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < row && cj >= 0 && cj < col)
        return true;
    else
        return false;
}
void bfs(int si, int sj)
{
    queue<pi> q;
    q.push(make_pair(si, sj));
    visited[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pi f = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int ci = f.first + path[i].first;
            int cj = f.second + path[i].second;
            if (isValid(ci, cj) && !visited[ci][cj])
            {
                q.push(make_pair(ci, cj));
                dis[ci][cj] = dis[f.first][f.second] + 1;
                visited[ci][cj] = true;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> row >> col;
        int si, sj;
        cin >> si >> sj;
        bfs(si, sj);

        int di, dj;
        cin >> di >> dj;
        if (visited[di][dj])
            cout << dis[di][dj] << endl;
        else
            cout << -1 << endl;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                visited[i][j] = false;
                dis[i][j] = 0;
            }
        }
    }
    return 0;
}