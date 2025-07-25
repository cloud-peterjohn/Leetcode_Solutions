// https://leetcode.com/problems/number-of-closed-islands/

class Solution
{
private:
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        // 越界
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;
        // 如果是海水
        if (grid[i][j] == 1)
            return;
        // 变为海水，淹没岛屿
        grid[i][j] = 1;
        // 遍历邻居节点
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        // 淹没靠边岛屿
        for (int i = 0; i < grid.size(); ++i)
        {
            dfs(grid, i, 0);
            dfs(grid, i, grid[0].size() - 1);
        }
        for (int j = 0; j < grid[0].size(); ++j)
        {
            dfs(grid, 0, j);
            dfs(grid, grid.size() - 1, j);
        }

        int number = 0;
        for (int i = 1; i < grid.size() - 1; ++i)
        {
            for (int j = 1; j < grid[0].size() - 1; ++j)
            {
                if (grid[i][j] == 0)
                {
                    number++;
                    dfs(grid, i, j);
                }
            }
        }
        return number;
    }
};