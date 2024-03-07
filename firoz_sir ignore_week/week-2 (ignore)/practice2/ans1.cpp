#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjL[N];
vector<int> v;
bool visited[N];
vector<int> bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        v.push_back(f);
        for (int x : adjL[f])
        {
            if (visited[x])
                continue;
            q.push(x);
            visited[x] = true;
        }
    }
    reverse(v.begin(), v.end());
    return v;
}
int main()
{
    int V, E;
    cin >> V >> E;
    for (int i = 1; i <= E; i++)
    {
        int u, w;
        cin >> u >> w;
        adjL[u].push_back(w);
    }
    vector<int> result = bfs(1);
    for (auto it = result.begin(); it != result.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}