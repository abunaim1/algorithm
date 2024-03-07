#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3 + 5;
int adjm[N][N];
vector<int> v[N];
int main()
{
    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= E; i++)
    {
        int u, w;
        cin >> u >> w;
        v[u].push_back(w);
    }
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            for (int x : v[i])
            {
                if (x == j)
                {
                    adjm[i][x] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}