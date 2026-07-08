#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> weight(n + 1), value(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> weight[i];
    for (int i = 1; i <= n; i++)
        cin >> value[i];
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= W; j++)
            if (weight[i] <= j)
                dp[i][j] = max(dp[i - 1][j], value[i] + dp[i - 1][j - weight[i]]);
            else
                dp[i][j] = dp[i - 1][j];
    cout << dp[n][W];
    return 0;
}