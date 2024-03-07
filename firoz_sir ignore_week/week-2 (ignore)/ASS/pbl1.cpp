#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 7;
vector<int> adjL[N];
int bfs(int s, int d)
{
    bool visited[N] = {false};
    int level[N] = {0};
    if (s == d)
        return 0;
    int x = 0;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int child : adjL[f])
        {
            if (visited[child])
                continue;
            q.push(child);
            visited[child] = true;
            level[child] = level[f] + 1;
            if (child == d)
            {
                x = level[child];
            }
        }
    }
    if(x==0) return -1;
    else return x;
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
        adjL[w].push_back(u);
    }
    int test;
    cin >> test;
    while (test--)
    {
        int s, d;
        cin >> s >> d;
        int result = bfs(s, d);
        cout << result << endl;
    }
    return 0;
}