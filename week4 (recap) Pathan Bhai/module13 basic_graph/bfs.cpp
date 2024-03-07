#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 7;
vector<int> adjL[N];
bool visited[N];
int level[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int f = q.front();
        cout << f << " ";
        q.pop();
        // shortcut for loop (Recommented)
        //  for (int child : adjL[f])
        //  {
        //      if (visited[child])
        //          continue;
        //      q.push(child);
        //      level[child] = level[f] + 1;
        //      visited[child] = true;
        //  }
        // longcut for loop (Rahat Bhai)
        for (int i = 0; i < adjL[f].size(); i++)
        {
            int child = adjL[f][i];
            if (visited[child])
                continue;
            q.push(child);
            level[child] = level[f] + 1;
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
        int s, d;
        cin >> s >> d;
        adjL[s].push_back(d);
        adjL[d].push_back(s);
    }
    bfs(1);
    cout << endl;
    for (int i = 1; i <= v; i++)
    {
        cout << "Node " << i << ": " << level[i] << endl;
    }
    return 0;
}
//O(N+E)