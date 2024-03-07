#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 7;
vector<int> adjL[N];
vector<int> v;
bool visited[N];
int level[N];
void bfs(int parent)
{
    queue<int> q;
    q.push(parent);
    visited[parent] = true;
    level[parent] = 0;
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
        adjL[w].push_back(u);
    }
    bfs(0);
    int l;
    cin >> l;
    if(l==0)
    {
        cout<<0;
        return 0;
    }
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        if (l == level[i])
        {
            flag++;
            cout << i << " ";
        }
    }
    if (flag == 0)
        cout << -1;
    return 0;
}