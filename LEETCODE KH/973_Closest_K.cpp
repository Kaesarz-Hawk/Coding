class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<pair<int, int>> vp;

        for (int i = 0; i < points.size(); i++)
        {
            int dist_square = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            vp.push_back({dist_square, i});
        }

        sort(vp.begin(), vp.end());

        vector<vector<int>> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(points[vp[i].second]);
        }

        return result;
    }
};