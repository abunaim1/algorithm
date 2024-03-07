#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 7;
vector<int> adjL[N];
bool visited[N];
bool visited2[N];
int x = 0;
void dfs(int k)
{
    visited2[k] = true;
    for (int w : adjL[k])
    {
        if (visited2[w])
            continue;
        x++;
        dfs(w);
    }
}
void bfs(int parent, int k)
{
    queue<int> q;
    q.push(parent);
    visited[parent] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        if (k == f)
        {
            dfs(k);
        }
        for (int child : adjL[f])
        {
            if (visited[child])
                continue;
            q.push(child);
            visited[child] = true;
        }
    }
}
int main()
{
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, w;
        cin >> u >> w;
        adjL[u].push_back(w);
    }
    int k;
    cin >> k;
    for (int i = 0; i < V; i++)
    {
        if (visited[i])
            continue;
        bfs(i, k);
    }
    cout << x << endl;
    return 0;
}