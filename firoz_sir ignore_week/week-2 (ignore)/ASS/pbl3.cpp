#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 7;
vector<int> adjL[N];
vector<int> v;
bool visited[N];
int x = 0;
void bfs(int parent, int k)
{
    queue<int> q;
    q.push(parent);
    visited[parent] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        if (f == k)
        {
            for(int w: adjL[k])
            {
                x++;
            }
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
        adjL[w].push_back(u);
    }
    int k;
    cin >> k;
    for(int i=0; i<V; i++)
    {
        if(visited[i])continue;
        bfs(i, k);
    }
    cout << x << endl;
    return 0;
}