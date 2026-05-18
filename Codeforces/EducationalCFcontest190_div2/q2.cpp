#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s_digitstring;
        cin >> s_digitstring;

        int n_length = s_digitstring.size();

        int total_1and3 = 0;
        for (int i = 0; i < n_length; i++)
            if (s_digitstring[i] == '1' || s_digitstring[i] == '3')
                total_1and3++;

        int max_keep = total_1and3;
        int twos = 0, passed_1and3 = 0;

        for (int i = 0; i < n_length; i++)
        {
            if (s_digitstring[i] == '2')
                twos++;
            else if (s_digitstring[i] == '1' || s_digitstring[i] == '3')
                passed_1and3++;

            int current_valid = twos + (total_1and3 - passed_1and3);
            if (current_valid > max_keep)
                max_keep = current_valid;
        }

        int min_removals = n_length - max_keep;

        cout << min_removals << endl;
    }
    return 0;
}