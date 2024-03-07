#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5+7;
vector<int> adjL[N];
bool visited[N];
void dfs(int u)
{
    visited[u] = true;
    for(int v: adjL[u])
    {
        if(visited[v])continue;
        dfs(v);
    }
}
int main()
{
    int V, E;
    cin>>V>>E;
    for(int i=1; i<=E; i++)
    {
        int x, y;
        cin>>x>>y;
        adjL[x].push_back(y);
    }
    int cc=0;
    for(int i=1; i<=V; i++)
    {
        if(visited[i])continue;
        dfs(i);
        cc++;
    }
    cout<<"Number of connected Components: "<<cc;
    return 0;
}