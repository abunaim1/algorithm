#include <iostream>
using namespace std;

const int N1 = 1e9 + 7;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int s = 1000 - m;
        vector<int> marks(n);
        vector<vector<int>> dp(n + 1, vector<int>(s + 1, INT_MAX - 1));
        for (int i = 0; i < n; i++)
        {
            cin >> marks[i];
        }
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (marks[i - 1] <= j)
                {
                    dp[i][j] = min(1 + dp[i][j - marks[i - 1]], dp[i - 1][j]);
                }
            }
        }

        if (dp[n][s] == INT_MAX - 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dp[n][s] << endl;
        }
    }

    return 0;
}