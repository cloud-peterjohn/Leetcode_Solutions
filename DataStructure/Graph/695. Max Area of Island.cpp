// https://leetcode.com/problems/max-area-of-island/

class Solution
{
private:
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        // 越界
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return 0;
        // 如果是海水
        if (grid[i][j] == 0)
            return 0;
        // 变为海水，淹没岛屿
        grid[i][j] = 0;
        // 遍历邻居节点，计算总面积
        return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int area = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    int area_i = dfs(grid, i, j);
                    area = max(area, area_i);
                }
            }
        }
        return area;
    }
};