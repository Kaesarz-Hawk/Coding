class Solution
{
public:
    int getPower(long long x)
    {
        int steps = 0;
        while (x != 1)
        {
            if (x % 2 == 0)
                x = x / 2;
            else
                x = 3 * x + 1;
            steps++;
        }
        return steps;
    }

    int getKth(int lo, int hi, int k)
    {
        vector<pair<int, int>> vp;

        for (int x = lo; x <= hi; x++)
        {
            vp.push_back({getPower(x), x});
        }

        sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b)
             {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second; });

        return vp[k - 1].second;
    }
};