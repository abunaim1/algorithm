#include <iostream>
using namespace std;
class Edge
{
public:
    int u;
    int v;
    long long int w;
    Edge(int u, int v, long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    vector<Edge> v;
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }
    long long int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    int s;
    cin >> s;
    dis[s] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            long int a = v[j].u;
            long int b = v[j].v;
            int w = v[j].w;
            if (dis[a] < INT_MAX && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }
    bool cycle = false;
    for (int j = 0; j < v.size(); j++)
    {
        int a = v[j].u;
        int b = v[j].v;
        int w = v[j].w;
        if (dis[a] < INT_MAX && dis[a] + w < dis[b])
        {
            cycle = true;
            break;
        }
    }
    int test;
    cin>>test;
    while(test--)
    {
        int d;
        cin>>d;
        if(!cycle && dis[d] == INT_MAX)cout<<"Not Possible"<<endl;
        else if(!cycle) cout<<dis[d]<<endl;
    }
    if(cycle)cout<<"Negative Cycle Detected"<<endl;
    return 0;
}