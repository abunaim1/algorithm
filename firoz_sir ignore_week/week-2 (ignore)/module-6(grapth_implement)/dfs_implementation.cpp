#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5+7;
vector<int> adj[N];
bool visited[N];
void dfs(int u)
{
    // section 1 : actions just after entering node u
    visited[u] = true;
    
    cout<<"Visiting Node: "<<u<<endl;

    for(int v: adj[u])
    {
        //section 2: actions before entering a new neighbor
        if(visited[v])continue;
        dfs(v);
        //section 3: actions after exiting a neighbor
    }
     // section 4 : actions just after exiting node u
}
int main()
{
    int V, E;
    cin>>V>>E;
    for(int i=1; i<=E; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for(int i=1; i<=V; i++)
    // {
    //     cout<<"List"<<" "<<i<<": ";
    //     for(int x: adj[i])
    //     {
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    dfs(1);
    return 0;
}