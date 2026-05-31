#include <bits/stdc++.h>
using namespace std;
#define SpeedxKH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{
   SpeedxKH;

    int n;
    cin >> n;

    map<string, int> database;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (database[s] == 0)
        {
            cout << "OK\n";
            database[s]++;
        }
        else
        {
            cout << s << database[s] << "\n";
            database[s]++;
        }
    }

    return 0;
}