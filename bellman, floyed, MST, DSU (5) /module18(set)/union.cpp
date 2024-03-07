// When Two nodes or componant will be connected togather, that means ther leaders are connected with each other
#include <iostream>
using namespace std;
int parent[1000];
int parentSize[1000];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
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
int dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        parent[leaderB] = leaderA;
    }
}
int main()
{

    int n, e;
    cin >> n >> e;
    dsu_set(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }
    cout << dsu_find(5);
    return 0;
}