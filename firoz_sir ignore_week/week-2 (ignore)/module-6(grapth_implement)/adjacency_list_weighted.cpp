#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5+7;
vector<pair<int, int> > adj[N];
int main()
{
    int V,E;
    cin>>V>>E;
    for(int i=1; i<=E; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w)); //undirected graph
    }
    for(int i=1; i<=V; i++)
    {
        cout<<"List"<<" "<<i<<":"<<" ";
        for(auto x: adj[i])
        {
            cout<<"("<<x.first<<","<<x.second<<")"<<" ";
        }
        cout<<endl;
    }
    return 0;
}