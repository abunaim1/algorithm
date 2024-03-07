//Dijkstra Algorithm - O(N*E)
#include<iostream>
#include<queue>
using namespace std;
const int N=1e5+7;
vector<pair<int, int> > adjL[N];
int dis[N];
void dijkstra(int u)
{
    queue<int>q;
    q.push(u);
    dis[u]=0;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(pair<int, int> child: adjL[f])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(dis[f]+childCost<dis[childNode])
            {
                dis[childNode] = dis[f]+childCost;
                q.push(childNode);
            }
        }
    }
}
int main()
{
    int v, e;
    cin>>v>>e;
    while(e--)
    {
        int s, d, w;
        cin>>s>>d>>w;
        adjL[s].push_back(make_pair(d,w));
        adjL[d].push_back(make_pair(s,w));
    }
    for(int i=1; i<=v; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(1);
    for(int i=1; i<=v; i++)
    {
        cout<<"Node "<<i<<": "<<dis[i]<<endl;
    }
    return 0;
}