#include <iostream>
#define pi pair<int, int>
using namespace std;
const int N = 1e3 + 5;
char matrix[N][N];
bool visited[N][N];
int row, col;
vector<pi> path = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};
bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < row && cj >= 0 && cj < col && matrix[ci][cj] == '.')
        return true;
    else
        return false;
}
int cnt;
void dfs(int si, int sj)
{
    visited[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = path[i].first + si;
        int cj = path[i].second + sj;
        if (isValid(ci, cj) && !visited[ci][cj])
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
            cin >> matrix[i][j];
        }
    }
    int mn = INT_MAX;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (!visited[i][j] && matrix[i][j] == '.')
            {
                cnt = 0;
                dfs(i, j);
                mn = min(cnt, mn);
            }
        }
    }
    if(cnt != 0) cout <<mn<<endl;
    else cout<<-1<<endl;
    return 0;
}