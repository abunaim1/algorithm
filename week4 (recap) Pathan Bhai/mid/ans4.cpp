#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long int N = 1e3 + 7;
vector<pair<long long int, long long int>> adjL[N];
long long  int dis[N];
bool visited[N];
void dijkstra(long long int u)
{
    dis[u] = 0;
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
    pq.push(make_pair(0, u));
    while (!pq.empty())
    {
        pair<long long int, long long int> t = pq.top();
        pq.pop();
        long long int node = t.second;
        long long int nodeCost = t.first;
        if (visited[node])
        {
            continue;
        }
        visited[node] = true;
        for (pair<long long int, long long int> child : adjL[node])
        {
            long long int childNode = child.first;
            long long int childCost = child.second;
            if (nodeCost + childCost < dis[childNode])
            {
                dis[childNode] = nodeCost + childCost;
                pq.push(make_pair(dis[childNode], childNode));
            }
        }
    }
}
int main()
{
    long long int v, e;
    cin >> v >> e;
    while (e--)
    {
        long long int s, d, w;
        cin >> s >> d >> w;
        adjL[s].push_back(make_pair(d, w));
    }
    for (long long int i = 1; i <= v; i++)
    {
        dis[i] = INT_MAX;
    }
    long long int s;
    cin>>s;
    dijkstra(s);
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int a, b;
        cin>>a>>b;
        if(dis[a]<=b) cout<<"YES"<<endl;
        else cout<<"NO" <<endl;
    }     
    return 0;
}