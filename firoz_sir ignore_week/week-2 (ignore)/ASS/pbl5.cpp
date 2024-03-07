#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3 + 7;
vector<int> adjL[N];
bool visited[N];
vector<int> v;
int x = 0;
void dfs(int u)
{
    visited[u] = true;
    x++;
    for (int v : adjL[u])
    {
        if (visited[v])
            continue;
        dfs(v);
    }
}
int main()
{
    int V, E;
    cin >> V >> E;
    for (int i = 1; i <= E; i++)
    {
        int x, y;
        cin >> x >> y;
        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }
    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && !adjL[i].empty())
        {
            x = 0;
            dfs(i);
            if (x != 1)
            {
                v.push_back(x);
            }
        }
    }
    sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}