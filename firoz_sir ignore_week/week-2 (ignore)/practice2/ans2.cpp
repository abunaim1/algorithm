#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5+7;
vector<int> adjL[N];
bool visited[N];
int level[N];

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s] = true;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int x: adjL[f])
        {
            if(visited[x])continue;
            level[x] = level[f] + 1;
            q.push(x);
            visited[x] = true;
        }
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
    bfs(1);
    int n;
    cin>>n;
    for(int i=1; i<=V; i++)
    {
        if(i==n)
        {
            cout<<level[i];
            break;
        }
    }
    return 0;
}