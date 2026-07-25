class NumMatrix
{
public:
    vector<vector<int>> pre;

    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        pre = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                pre[i + 1][j + 1] = matrix[i][j] + pre[i][j + 1] + pre[i + 1][j] - pre[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return pre[row2 + 1][col2 + 1] - pre[row1][col2 + 1] - pre[row2 + 1][col1] + pre[row1][col1];
    }
};