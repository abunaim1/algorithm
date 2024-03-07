#include<iostream>
using namespace std;
const int N = 1e5+7;
vector<int> u_graph[N];
bool visited[N];
void dfs(int parent)
{
    visited[parent] = true;
    for(int child: u_graph[parent])
    {
        if(visited[child])continue;
        dfs(child);
        cout<<"child: "<<child<<endl;
    }
    cout<<parent<<" ";
}
int main()
{
    int V;
    cin>>V;
    int E;
    cin>>E;
    for(int i=1; i<=E; i++)
    {
        int u, v;
        cin>>u>>v;
        u_graph[u].push_back(v);
        u_graph[v].push_back(u);
    }

    // for(int i=1; i<=V; i++)
    // {
    //     cout<<"List "<<i<<": ";
    //     for(int x: u_graph[i])
    //     {
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }

    dfs(1);

    return 0;
}