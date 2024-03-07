#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5+7;
vector<int> adj[N];
int main()
{
    int V,E;
    cin>>V>>E;
    for(int i=1; i<=E; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1; i<=V; i++)
    {
        cout<<"List"<<" "<<i<<":";
        for(int x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}