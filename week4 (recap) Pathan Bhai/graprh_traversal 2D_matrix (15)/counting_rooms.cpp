#include <iostream>
#include <vector>
#define pi pair<int, int>
using namespace std;
const int N = 1e3 + 5;
bool visited[N][N];
int row, col;
char room[N][N];
vector<pi> path = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};
bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < row && cj >= 0 && cj < col && room[ci][cj] == '.')
        return true;
    else
        return false;
}
void dfs(int si, int sj)
{
    visited[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + path[i].first;
        int cj = si + path[i].second;
        if (isValid(ci, cj) &&!visited[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> room[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (!visited[i][j] && room[i][j] == '.')
            {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}