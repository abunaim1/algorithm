#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 7;
vector<int> adj[N];
bool visited[N];
int depth[N];
int height[N];
void dfs(int u)  //u=parent
{
    visited[u] = true;

    for (int v : adj[u]) //v=children
    {
        if (visited[v])
            continue;
        // for depth calculation
        depth[v] = depth[u] + 1;
        dfs(v);
        // for height calculation

        // if (height[v] + 1 > height[u])
        //     height[u] = height[v] + 1;

        height[u] = max(height[u], height[v]+1);
    }
}
int main()
{
    int V, E;
    cin >> V >> E;
    for (int i = 1; i <= E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= V; i++)
    {
        cout << "Depth of Node: " << i << ": " << depth[i] << endl;
    }
    cout<<"*********"<<endl;
    for (int i = 1; i <= V; i++)
    {
        cout << "Height of Node: " << i << ": " << height[i] << endl;
    }
    return 0;
}