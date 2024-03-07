// Dijkstra Algorithm - optimizedd // O(v+elogV)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<pair<int, int>> adjL[N];
int dis[N];
bool visited[N];
void dijkstra(int u)
{
    dis[u] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, u));
    while (!pq.empty())
    {
        pair<int, int> t = pq.top();
        pq.pop();
        int node = t.second;
        int nodeCost = t.first;
        if (visited[node])
        {
            continue;
        }
        visited[node] = true;
        for (pair<int, int> child : adjL[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if (nodeCost + childCost < dis[childNode])
            {
                dis[childNode] = nodeCost + childCost;
                pq.push(make_pair(dis[childNode], childNode)); // O(logV)
            }
        }
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    while (e--)
    {
        int s, d, w;
        cin >> s >> d >> w;
        adjL[s].push_back(make_pair(d, w));
        adjL[d].push_back(make_pair(s, w));
    }
    for (int i = 1; i <= v; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(1);
    for (int i = 1; i <= v; i++)
    {
        cout << "Node " << i << ": " << dis[i] << endl;
    }
    return 0;
}