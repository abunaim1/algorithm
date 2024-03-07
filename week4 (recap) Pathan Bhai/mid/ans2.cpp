#include <iostream>
#define pi pair<int, int>
using namespace std;
const int N = 1e3 + 5;
char matrix[N][N];
bool visited[N][N];
int row, col;
int flag = 0;
vector<pi> path = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};
bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < row && cj>=0 && cj <col && matrix[ci][cj] == '.') return true;
    else return false;
}
void dfs(int si, int sj, int di, int dj)
{
    visited[si][sj] = true;
    if(si == di && sj == dj)
    {
        flag++;
        cout<< "YES" <<endl;   
    }
    for (int i = 0; i < 4; i++)
    {
        int ci = path[i].first + si;
        int cj = path[i].second + sj;
        if (isValid(ci, cj) && !visited[ci][cj])
        {
            dfs(ci, cj, di, dj);
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

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    if (!visited[si][sj] && matrix[si][sj] == '.')
    {
        dfs(si, sj, di, dj);
    }
    if(flag==0) cout<<"NO"<<endl;
    return 0;
}