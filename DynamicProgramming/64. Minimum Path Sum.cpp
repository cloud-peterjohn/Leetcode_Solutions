// https://leetcode.com/problems/minimum-path-sum/

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp_table(m, vector<int>(n, 0));
        // 初始化
        dp_table[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i)
        {
            dp_table[i][0] = dp_table[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j)
        {
            dp_table[0][j] = dp_table[0][j - 1] + grid[0][j];
        }
        // DP
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp_table[i][j] = min(dp_table[i - 1][j], dp_table[i][j - 1]) + grid[i][j];
            }
        }
        return dp_table[m - 1][n - 1];
    }
};