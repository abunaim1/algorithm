#include <iostream>
using namespace std;
const int N = 1e5 + 7;
vector<int> adjL[N];
bool visited[N];
vector<int> cmp;
void dfs(int s)
{
    visited[s] = true;
    cmp.push_back(s);
    for (int child : adjL[s])
    {
        if (visited[child])
            continue;
        dfs(child);
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjL[a].push_back(b);
        adjL[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= v; i++)
    {
        if (visited[i])
            continue;
        cnt++;
        dfs(i);
        for (int x : cmp)
        {
            cout << x << " ";
        }
        cmp.clear();
        cout << endl;
    }
    cout << cnt << endl;
    return 0;
}