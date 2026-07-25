#include <bits/stdc++.h>
using namespace std;
#define ll long long

void prefixsum(const vector<ll> &arr, int n)
{
    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + arr[i];
    }
    for (int i = 0; i <= n; i++)
    {
        cout << pre[i] << " ";
    }
    cout << '\n';
}

void differencearray(vector<ll> &arr, int n, int l, int r, ll x)
{
    vector<ll> diff(n + 1, 0);
    diff[l] += x;

    if (r + 1 < n)
    {
        diff[r + 1] -= x;
    }

    ll curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += diff[i];
        arr[i] += curr;
        cout << arr[i] << " ";
    }
    cout << '\n';
}

void xorversion(vector<ll> &arr, int n, int l, int r, ll x)
{
    vector<ll> diff(n + 1, 0);
    diff[l] ^= x;

    if (r + 1 < n)
    {
        diff[r + 1] ^= x;
    }

    ll curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr ^= diff[i];
        arr[i] ^= curr; // Fixed: XOR operator instead of +=
        cout << arr[i] << " ";
    }
    cout << '\n';
}

int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //here is the prefix sum of the array

    cout << "Prefix Sum: ";
    prefixsum(arr, n);

    // 0-based index range within bounds
    ll l = 0; 
    ll r = 3; 
    ll x = 5; 

    
    //here is the difference array of the array
    cout << "Difference Array: ";
    differencearray(arr, n, l, r, x);

    //here is the XOR version of the array
    cout << "XOR Version: ";
    xorversion(arr, n, l, r, x);
  

    return 0;
}