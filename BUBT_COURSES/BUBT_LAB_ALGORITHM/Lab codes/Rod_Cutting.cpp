#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> price(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> price[i];
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i] = max(dp[i], price[j] + dp[i - j]);
    cout << dp[n];
    return 0;
}