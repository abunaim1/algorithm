//O(E + ElogE)
#include <iostream>
#include <queue>
#define pi pair<int, int>
using namespace std;
const int N = 1e5 + 7;
vector<pi> adjL[N];
bool visited[N];
class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }
};
void prims(int s, int n)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push(Edge(s, s, 0));
    vector<Edge> edgeList;
    int cnt = 0;
    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int a = parent.a;
        int b = parent.b;
        int w = parent.w;
        if (visited[b])
            continue;
        visited[b] = true;
        cnt++;
        edgeList.push_back(parent);
        for (pi child : adjL[b])
        {
            if (visited[child.first])
                continue;
            pq.push(Edge(b, child.first, child.second));
        }
    }
    edgeList.erase(edgeList.begin());
    long long int sum = 0;

    for(Edge val: edgeList)
    {
        sum+=(long long)val.w;
    }
    if(cnt == n)cout<<sum<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adjL[a].push_back(make_pair(b, w));
        adjL[b].push_back(make_pair(a, w));
    }
    prims(1, n);
}