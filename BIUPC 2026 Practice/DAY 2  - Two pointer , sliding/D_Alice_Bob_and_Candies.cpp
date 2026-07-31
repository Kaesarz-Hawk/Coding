// Author  : Kaesarz
// Date    : 30-07-2026
// Time    : 23:24

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SpeedxKH                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int alice_moves = 0;
    int bob_moves = 0;
    int alice_total_eaten_Size = 0;
    int bob_total_eaten_Size = 0;

    int left = 0;
    int right = n - 1;

    int alice_previous = 0;
    int bob_previous = 0;

    while (left <= right)
    {

        // Alice Turn er jonno
        int alice_current = 0;
        while (left <= right && alice_current <= bob_previous)
        {
            alice_current += a[left];
            alice_total_eaten_Size += a[left];
            left++;
        }
        alice_previous = alice_current;
        alice_moves++;

        if (left > right)
            break;

        // Bob Turn ebar
        int bob_current = 0;
        while (left <= right && bob_current <= alice_previous)
        {
            bob_current += a[right];
            bob_total_eaten_Size += a[right];
            right--;
        }
        bob_previous = bob_current;
        bob_moves++;
    }

    int total_moves = alice_moves + bob_moves;

    cout << total_moves << " " << alice_total_eaten_Size << " " << bob_total_eaten_Size << endl;
}

int main()
{
    SpeedxKH

        int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    // single test case
    // solve();

    return 0;
}