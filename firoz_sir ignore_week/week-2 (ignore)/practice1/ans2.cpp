#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3 + 5;
int adjm[N][N];
vector<int> v[N];
int main()
{
    int V;
    cin >> V;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cin>>adjm[i][j];
        }
    }
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (adjm[i][j] == 1)
            {
                v[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= V; i++)
    {
        cout << "List " << i << ": ";
        for (int x : v[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}