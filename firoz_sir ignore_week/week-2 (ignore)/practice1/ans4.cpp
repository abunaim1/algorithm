#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 7;
vector<int> adjL[N];
bool visited[N];
int cnt[N];
void dfs(int parent)
{
    visited[parent] = true;
    for (int child : adjL[parent])
    {
        if (visited[child])
            continue;
        cnt[child] = cnt[parent] + 1;
        dfs(child);
    }
}
int main()
{
    int E, V;
    cin >> E >> V;
    for (int i = 1; i <= E; i++)
    {
        int u, v;
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    dfs(1);
    int w;
    cin >> w;
    for (int i = 1; i <= V; i++)
    {   
        for(int x: adjL[i])
        {
            if(w==x)
            {
                cout<<"Depth of "<<x<<": "<<cnt[x];
                break;
            }
        }
    }
    return 0;
}