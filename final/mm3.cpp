#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        int s = 1000 - m;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
        
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s; j++) {
                dp[i][j] = dp[i - 1][j];
                if (a[i - 1] <= j) {
                    dp[i][j] = (dp[i][j] + dp[i][j - a[i - 1]]) % MOD;
                }
                dp[i][j] = dp[i][j] % MOD; 
            }
        }
        
        cout << dp[n][s] << endl;
    }
    
    return 0;
}