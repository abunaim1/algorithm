#include<iostream>
using namespace std;
const int N = 1e5+7;
vector<int> adjL[N];
bool visited[N];
int height[N];
void dfs(int u)
{
    visited[u]=true;
    for(int x: adjL[u])
    {
        if(visited[x])continue;
        dfs(x);
        height[u] = max(height[u], height[x]+1);
    }
}
int main()
{
    int V, E;
    cin>>V>>E;
    for(int i=1; i<=E; i++)
    {
        int u, w;
        cin>>u>>w;
        adjL[u].push_back(w);
    }
    dfs(1);
    int q; cin>>q;
    for(int i=1; i<=V; i++){
        for(int x: adjL[i])
        {
            if(x==q)
            {
                cout<<"height of "<<q<<": "<<height[q]<<endl;
            }
        }
    }
    if(q==1)
    {
        cout<<"height of "<<q<<": "<<height[q]<<endl;
    }
    return 0;
}