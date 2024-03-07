#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e5+7;
vector<int> adjL[N];
bool visited[N];
int level[N];
void bfs(int parent)
{
    queue<int>q;
    q.push(parent);
    visited[parent] = true;
    level[parent] = 0;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        cout<< "Visiting Node: "<<f<<endl;
        for(int child: adjL[f])
        {
            if(visited[child]) continue;
            q.push(child);
            visited[child] = true;
            level[child] = level[f]+1;
        }
    }
}
int main()
{
    int V, E;
    cin>>V>>E;
    for(int i=0; i<E; i++)
    {
        int u, w;
        cin>>u>>w;
        adjL[u].push_back(w);
        adjL[w].push_back(u);
    }
    bfs(1);
    cout<<"*****************"<<endl;
    for(int i=1; i<=V; i++)
    {
        cout<<"Level of "<<i<<": "<<level[i]<<endl;
    }
    return 0;
}