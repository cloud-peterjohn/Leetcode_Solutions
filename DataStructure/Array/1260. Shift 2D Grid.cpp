// https://leetcode.com/problems/shift-2d-grid/description/

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        // 将二维数组变为一维
        vector<int> v;
        for (const auto line : grid)
        {
            for (const auto val : line)
            {
                v.push_back(val);
            }
        }
        // 将移位后的序列写回矩阵
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                grid[i][j] = v[((i * n + j) + v.size() * k - k) % v.size()]; // 移动k位：-k，确保不为负：+v.size() * k
            }
        }
        return grid;
    }
};