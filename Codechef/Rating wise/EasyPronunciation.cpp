#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        char vowels[] = {'a', 'e', 'i', 'o', 'u'};
        int count_consonants = 0;
        bool bad = false;

        for (char c : s)
        {
            if (find(begin(vowels), end(vowels), c) == end(vowels))
            {
                count_consonants++;
                if (count_consonants >= 4)
                    bad = true;
            }
            else
            {
                count_consonants = 0;
            }
        }

        if (bad)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}