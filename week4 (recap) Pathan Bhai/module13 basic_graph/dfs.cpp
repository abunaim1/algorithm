#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5+7;
vector<int> adjL[N];
bool visited[N];
void dfs(int s)
{
    visited[s] = true;
    cout<<s<<endl;
    for(int x: adjL[s])
    {
        if(visited[x])continue;
        dfs(x);
    }
}
int main()
{
    int n, e;
    cin>>n>>e;
    while(e--)
    {
        int u, v;
        cin>>u>>v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    dfs(1);
    return 0;
}
//O(N+E)