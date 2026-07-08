#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item
{
    int value, weight;
};
bool cmp(Item a, Item b) { return (double)a.value / a.weight > (double)b.value / b.weight; }
int main()
{
    int n, W;
    cin >> n >> W;
    vector<Item> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].value >> a[i].weight;
    sort(a.begin(), a.end(), cmp);
    double profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (W >= a[i].weight)
        {
            profit += a[i].value;
            W -= a[i].weight;
        }
        else
        {
            profit += (double)a[i].value / a[i].weight * W;
            break;
        }
    }
    cout << profit;
    return 0;
}