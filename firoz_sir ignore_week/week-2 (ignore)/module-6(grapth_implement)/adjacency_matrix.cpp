#include<iostream>
using namespace std;
const int N = 1e3+5;
int adjmat[N][N];
int main()
{
    int V; // #node
    cin>>V;
    int E; // #edges
    cin>>E;
    for(int i=1; i<=E; i++)
    {
        int u, v;
        cin>>u>>v;
        adjmat[u][v] = 1; //undirected
        // adjmat[v][u] = 1; // if q. say directed
    }
    for(int i=1; i<=V; i++)
    {
        for(int j=1; j<=V; j++)
        {
            cout<<adjmat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}