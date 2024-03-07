// O(ElogE)
#include <iostream>
using namespace std;
class Edge
{
public:
    long long a, b, w;
    Edge(long long a, long long b, long long w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
const int N = 1e5 + 7;
int parent[N];
int parentSize[N];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 0;
    }
}
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int main()
{
    long long n, e, w;
    cin >> n >> e;
    vector<Edge> v;
    vector<Edge> ans;
    dsu_set(n);
    while (e--)
    {
        long long a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }
    sort(v.begin(), v.end(), cmp); 
    for (Edge x : v)            
    {
        long long a = x.a;
        long long b = x.b;
        long long leaderA = dsu_find(a);
        long long leaderB = dsu_find(b);
        if (leaderA == leaderB)
            continue;
        ans.push_back(x);
        dsu_union(a, b);
    }
    long long sum = 0;
    for (Edge val : ans)
    {
        sum += (long long)val.w;
    }
    if (ans.size() == n - 1)
    {
        cout << sum << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}