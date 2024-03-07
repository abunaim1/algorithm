#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 7;
vector<int> adjL[N];
bool visited[N];
int path[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    path[s] = -1;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int child : adjL[f])
        {
            if (visited[child])
                continue;
            q.push(child);
            path[child] = f;
            visited[child] = true;
        }
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
        adjL[a].push_back(b);
    }
    bfs(1);
    // for(int i=1; i<=v; i++)
    // {
    //     cout<<"Node"<<i<<": "<<path[i]<<endl;
    // }
    int d;
    cin >> d;
    if (visited[d])
    {
        vector<int> reversing_path;
        while (d != -1)
        {
            reversing_path.push_back(d);
            d = path[d];
        }
        reverse(reversing_path.begin(), reversing_path.end());
        for(auto it=reversing_path.begin(); it!= reversing_path.end(); it++)
        {
            cout<<*it<<" ";
        }
    }
    else
    {
        cout << "Path nai" << endl;
    }
    return 0;
}